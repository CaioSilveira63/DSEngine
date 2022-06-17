//
// Created by caios on 03/06/2022.
//
#include <SFML/Graphics.hpp>
#include "../shared/ColorMaker.h"

#ifndef DSENGINE_PCENGINE_H
#define DSENGINE_PCENGINE_H

void engine_ConsoleOut();

void EngineGameMain(void (*BeforeLoop)(), void (*OnLoop)());

void engine_DrawRectangle(int x, int y, int w, int h, ColorMaker Color);


#endif //DSENGINE_PCENGINE_H
