//
// Created by caios on 03/06/2022.
//

#include "engine.h"
#include <iostream>

#if defined(PlatformType) && PlatformType == 0

#include "pcengine/pcengine.h"
#include "shared/ColorMaker.h"

#else
#include "dsengine/dsengine.h"

#endif


void ConsoleOut() {
    engine_ConsoleOut();
}

void GameMain(void (*BeforeLoop)(), void (*OnLoop)()) {
    EngineGameMain(BeforeLoop, OnLoop);
}

void Draw_Rectangle(int x, int y, int w, int h, ColorMaker Color) {
    engine_DrawRectangle(x, y, w, h, Color);
}