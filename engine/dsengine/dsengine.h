//
// Created by caios on 03/06/2022.
//

#ifndef DSENGINE_DSENGINE_H
#define DSENGINE_DSENGINE_H
#include "../shared/ColorMaker.h"


void engine_ConsoleOut();

void EngineGameMain(void (*BeforeLoop)(), void (*OnLoop)());

void engine_DrawRectangle(int x, int y, int w, int h, ColorMaker Color);

#endif //DSENGINE_DSENGINE_H
