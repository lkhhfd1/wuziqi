#include <iostream>
#include "View.h"
void View::displayBoard(const Model& model) {
    std::cout << "\n  1   2   3\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << model.getCell(i, j);
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  ---------\n";
    }
    std::cout << "\n";
}
void View::displayMessage(const std::string& msg) { std::cout << msg << std::endl; }
void View::displayResult(const Model& model) {
    displayBoard(model);
    int w = model.getWinner();
    if (w == 1) std::cout << "玩家 X 获胜！\n";
    else if (w == 2) std::cout << "玩家 O 获胜！\n";
    else if (w == 3) std::cout << "平局！\n";
}