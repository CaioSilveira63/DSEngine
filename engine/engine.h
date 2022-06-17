//
// Created by caios on 03/06/2022.
//

#ifndef DSENGINE_ENGINE_H
#define DSENGINE_ENGINE_H


#include "shared/ColorMaker.h"

void ConsoleOut();

void GameMain(void (*BeforeLoop)(), void (*OnLoop)());

void Draw_Rectangle(int x, int y, int w, int h, ColorMaker Color);

#endif //DSENGINE_ENGINE_H
