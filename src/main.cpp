#include "../engine/engine.h"
#include "../engine/shared/ColorMaker.h"
#include <string>
#include <iostream>

void Print(std::string text){
    std::cout << text;
    std::cout << "\n";
}

//Initialize values
void BeforeLoop() {
    std::cout << "teste";
}

// Draw and physics
void OnLoop() {
    ColorMaker Cor = ColorMaker(0, 255, 0);
    Draw_Rectangle(10, 10, 100, 50, Cor);
}

//Just let it be...
int main() {
    GameMain(BeforeLoop, OnLoop);
}
