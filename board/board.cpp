#include "board.h"

Board::Board(){
    const int initData[9][9] = {
        {-4,-5,-6,-7,-8,-7,-6,-5,-4},
        {0,-3,0,0,0,0,0,-2,0},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1},
        {0,2,0,0,0,0,0,3,0},
        {4,5,6,7,8,7,6,5,4}
    }; // создаем массив с текущими фигурами на доске

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            boardMas_[i][j] = initData[i][j]; // перенос фигур в нужное поле
        }
    }

    // Инициализация массивов захваченных фигур
    for (int i = 0; i < 19; ++i) {
        capturedBlack_[i] = 0;
        capturedWhite_[i] = 0;
    }
    currentMove_ = true; // начальный ход за черными (true), белые - false.
    checkBlack_ = false;
    checkWhite_ = false; // установки шахов
};

void Board::SetMove(int oldInd1, int oldInd2, int newInd1, int newInd2){
    if(boardMas_[newInd1][newInd2] != 0) {// если в новой позиции была фигура
        capturedAdd(boardMas_[newInd1][newInd2]);// отправить фигуру в список
    }
    boardMas_[newInd1][newInd2] = boardMas_[oldInd1][oldInd2];// установка фигуры на позицию
    boardMas_[oldInd1][oldInd2] = 0; // обнуление предыдущей позиции
    CheckCheck();// проверить, не появился ли шах на доске
    currentMove_ = !currentMove_;// сменить ход
};

void Board::capturedAdd(int figure){
    if(currentMove_){ // если ход черных
        int i = 0;
        while (capturedWhite_[i]!=0){
            i++;
        }
        capturedWhite_[i] = figure * -1; // добавим в список захваченных белых фигур еще одну
    }
    else{ // иначе
        int i = 0;
        while (capturedBlack_[i]!=0){
            i++;
        }
        capturedBlack_[i] = figure * -1; // добавим в список захваченных черных фигур еще одну
    }
};

int Board::GetCell(int ind1, int ind2) const {
    return boardMas_[ind1][ind2];
};
