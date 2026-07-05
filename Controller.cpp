#include <iostream>
#include "Controller.h"
Controller::Controller() : gameOver(false) {}

void Controller::run() {
    while (!gameOver) {
        view.displayBoard(model);
        int player = model.getCurrentPlayer();
        view.displayMessage("玩家 " + std::string(player == 1 ? "X" : "O") + " 的回合，请输入行和列 (1-3): ");
        playerTurn();
        model.checkWin(); // 已在placeMark中调用，但可再次确认
        if (model.getWinner() != 0 || model.isFull()) {
            gameOver = true;
        }
    }
    view.displayResult(model);
}

void Controller::playerTurn() {
    int row, col;
    while (true) {
        std::cin >> row >> col;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            view.displayMessage("输入无效，请输入数字。");
            continue;
        }
        // 转换为0-based
        row--; col--;
        if (!isValidInput(row, col)) {
            view.displayMessage("无效坐标或该位置已有棋子，请重新输入。");
            continue;
        }
        if (model.placeMark(row, col)) {
            break;
        }
        else {
            view.displayMessage("落子失败，请重试。");
        }
    }
}

bool Controller::isValidInput(int row, int col) const {
    if (row < 0 || row>2 || col < 0 || col>2) return false;
    return model.getCell(row, col) == ' ';
}