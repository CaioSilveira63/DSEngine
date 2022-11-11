//
// Created by caios on 03/06/2022.
//

#include <iostream>
#include "pcengine.h"
#include "../shared/ColorMaker.h"
#include <windows.h>

void engine_ConsoleOut() {
    std::cout << "PC Engine";
}

sf::RenderWindow window(sf::VideoMode(400, 240), "DS Engine");

void engine_DrawRectangle(int x, int y, int w, int h, ColorMaker Color) {
    sf::RectangleShape rectangle(sf::Vector2f(w, h));
    sf::Color color(Color.Red, Color.Green, Color.Blue, Color.Alpha);
    rectangle.setFillColor(color);
    rectangle.setPosition(x, y);
    window.draw(rectangle);
}

void EngineGameMain(void (*BeforeLoop)(), void (*OnLoop)()) {
    ::ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
    BeforeLoop();
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        OnLoop();
        window.display();

    }

}

