#pragma once
#include "Model.h"
#include "View.h"
class Controller {
private:
    Model model;
    View view;
    bool gameOver;
public:
    Controller();
    void run();
    void playerTurn();
    bool isValidInput(int row, int col) const;
};