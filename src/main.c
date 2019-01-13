/*
 *--------------------------------------
 * Program Name:
 * Author:
 * License:
 * Description:
 *--------------------------------------
*/

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>
#include <keypadc.h>

#include "palette.h"

uint24_t x;
uint8_t y;

bool isClearPressed(){
    kb_Scan();
    return kb_Data[6] & kb_Clear;
}

uint8_t getPixelColor(uint24_t _x, uint8_t _y){
    uint8_t iter = 0;
    double xo = (double)_x / 80.0 - 2.0;
    double yo = (double)_y / 60.0 - 2.0;
    double x = 0.0;
    double y = 0.0;

    double xtmp = 0.0;
    
    while(x*x + y*y < 4.0 && iter < 32){
        xtmp = x*x - y*y + xo;
        y = 2*x*y + yo;
        x = xtmp;
        iter++;
    }

    return iter;
}

void run() {
    for(x = 0; x < 320; x++){
        for(y = 0; y < 120; y++){
            gfx_SetColor(getPixelColor(x, y));
            gfx_SetPixel(x, y);
            gfx_SetPixel(x, 240 - y);
        }
        if(isClearPressed()){
            return;
        }
    }
}

void main() {
    gfx_Begin();
    gfx_SetPalette(palette, sizeof palette, 0);
    gfx_FillScreen(32);
    run();
    while(!isClearPressed()){};
    gfx_End();
}
