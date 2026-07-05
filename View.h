#pragma once
#include <string>
#include "Model.h"
class View {
public:
    void displayBoard(const Model& model);
    void displayMessage(const std::string& msg);
    void displayResult(const Model& model);
};