// Model.cpp
#include "Model.h"

// 构造函数，调用 reset() 初始化游戏状态
Model::Model() {
    reset();
}

// 重置棋盘和状态
void Model::reset() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 1;   // 玩家1（X）先手
    winner = 0;          // 0 表示未分胜负
}

// 尝试在 (row, col) 落子，成功返回 true，失败返回 false
bool Model::placeMark(int row, int col) {
    // 检查坐标是否在有效范围内
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    // 检查该位置是否已被占用
    if (board[row][col] != ' ') {
        return false;
    }

    // 落子：当前玩家为1则放 'X'，为2则放 'O'
    board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

    // 检查落子后是否产生胜者
    checkWin();

    // 如果游戏尚未结束（无胜者且棋盘未满），切换到下一个玩家
    if (winner == 0 && !isFull()) {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return true;
}

// 检查当前棋盘是否存在胜者，若有则设置 winner 为对应玩家编号
void Model::checkWin() {
    // 定义所有可能的获胜线（8条）：行、列、对角线
    // 每条线由三个坐标对 (row, col) 组成
    const int lines[8][3][2] = {
        {{0,0},{0,1},{0,2}}, // 第1行
        {{1,0},{1,1},{1,2}}, // 第2行
        {{2,0},{2,1},{2,2}}, // 第3行
        {{0,0},{1,0},{2,0}}, // 第1列
        {{0,1},{1,1},{2,1}}, // 第2列
        {{0,2},{1,2},{2,2}}, // 第3列
        {{0,0},{1,1},{2,2}}, // 主对角线
        {{0,2},{1,1},{2,0}}  // 副对角线
    };

    for (int i = 0; i < 8; ++i) {
        int r1 = lines[i][0][0], c1 = lines[i][0][1];
        int r2 = lines[i][1][0], c2 = lines[i][1][1];
        int r3 = lines[i][2][0], c3 = lines[i][2][1];

        char cell1 = board[r1][c1];
        // 如果第一个格子为空，跳过这条线
        if (cell1 == ' ') continue;

        // 检查三个格子是否相同
        if (cell1 == board[r2][c2] && cell1 == board[r3][c3]) {
            winner = (cell1 == 'X') ? 1 : 2;
            return;   // 找到胜者，立即返回
        }
    }

    // 没有找到胜者
    if (isFull()) {
        winner = 3; // 3 代表平局
    }
    else {
        winner = 0; // 游戏继续
    }
}

// 检查棋盘是否已满（没有空格）
bool Model::isFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;   // 还有空格，未满
            }
        }
    }
    return true;   // 全满
}

// 获取指定格子的字符
char Model::getCell(int row, int col) const {
    // 调用者应确保坐标有效，这里简单返回，不做边界检查（也可加上断言）
    return board[row][col];
}

// 获取当前玩家（1 或 2）
int Model::getCurrentPlayer() const {
    return currentPlayer;
}

// 获取胜者编号（0:无, 1:X胜, 2:O胜, 3:平局）
int Model::getWinner() const {
    return winner;
}