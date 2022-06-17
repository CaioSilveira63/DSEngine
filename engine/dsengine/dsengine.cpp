//
// Created by caios on 03/06/2022.
//
#include <iostream>
#include "dsengine.h"
#include "../shared/ColorMaker.h"
#include <3ds.h>
#include <citro2d.h>

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

u32 clrRec1 = C2D_Color32(0x9A, 0x6C, 0xB9, 0xFF);

void engine_ConsoleOut() {
    std::cout << "DS Engine";
}

void engine_DrawRectangle(int x, int y, int w, int h, ColorMaker Color) {
    C2D_DrawRectSolid(x, y, 0, w, h, C2D_Color32(Color.Red, Color.Green, Color.Blue, 255));

}

void EngineGameMain(void (*BeforeLoop)(), void (*OnLoop)()) {
//---------------------------------------------------------------------------------
    // Init libs
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    consoleInit(GFX_BOTTOM, NULL);

    // Create screens
    C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    // Create colors
    u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
    u32 clrRed = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
    u32 clrBlue = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);


    u32 clrClear = C2D_Color32(0x00, 0x00, 0x00, 0x00);
    BeforeLoop();
    // Main loop
    while (aptMainLoop()) {
        hidScanInput();

        // Respond to user input
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
            break; // break in order to return to hbmenu
        printf("\x1b[1;1HSimple citro2d shapes example");
        printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime() * 6.0f);
        printf("\x1b[3;1HGPU:     %6.2f%%\x1b[K", C3D_GetDrawingTime() * 6.0f);
        printf("\x1b[4;1HCmdBuf:  %6.2f%%\x1b[K", C3D_GetCmdBufUsage() * 100.0f);

        // Render the scene
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_TargetClear(top, clrClear);
        C2D_SceneBegin(top);
        OnLoop();
        C3D_FrameEnd(0);
    }

    // Deinit libs
    C2D_Fini();
    C3D_Fini();
    gfxExit();
}
