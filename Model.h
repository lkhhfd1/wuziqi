#pragma once
class Model {
private:
    char board[3][3];
    int currentPlayer; // 1: X, 2: O
    int winner;        // 0: none, 1: X, 2: O, 3: draw
public:
    Model();
    bool placeMark(int row, int col);
    void checkWin();
    bool isFull() const;
    void reset();
    char getCell(int row, int col) const;
    int getCurrentPlayer() const;
    int getWinner() const;
};