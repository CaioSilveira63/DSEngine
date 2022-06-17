//
// Created by caios on 04/06/2022.
//

#include "ColorMaker.h"

ColorMaker::ColorMaker(int RedValue, int GreenValue, int BlueValue, int AlphaValue) {
    if(RedValue > 255){
        RedValue = 255;
    }
    if(GreenValue > 255){
        GreenValue = 255;
    }
    if(BlueValue > 255){
        BlueValue = 255;
    }
    if(AlphaValue > 255){
        AlphaValue = 255;
    }
    Red = RedValue;
    Green = GreenValue;
    Blue = BlueValue;
    Alpha = AlphaValue;
};

