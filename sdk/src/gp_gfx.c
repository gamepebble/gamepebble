/*
 * MIT License
 *
 * Copyright (c) 2025 Grzegorz Grzęda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "gp/gp.h"
#include "gp_platform.h"

void gp_gfx_draw_line(int x0, int y0, int x1, int y1, uint16_t color) {
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    uint8_t bitmap[1];
    bitmap[0] = (color & 1) ? 0xFF : 0x00;
    while (true) {
        gp_platform_gfx_write(x0, y0, 1, 1, bitmap);
        if (x0 == x1 && y0 == y1) {
            break;
        }
        e2 = err << 1;
        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void gp_gfx_draw_pixel(int x, int y, uint16_t color) {
    uint8_t bitmap[1];
    bitmap[0] = (color & 1) ? 0xFF : 0x00;
    gp_platform_gfx_write(x, y, 1, 1, bitmap);
}

void gp_gfx_draw_rect(int x, int y, int width, int height, uint16_t color) {
    gp_gfx_draw_line(x, y, x + width - 1, y, color);
    gp_gfx_draw_line(x, y, x, y + height - 1, color);
    gp_gfx_draw_line(x + width - 1, y, x + width - 1, y + height - 1, color);
    gp_gfx_draw_line(x, y + height - 1, x + width - 1, y + height - 1, color);
}

void gp_gfx_fill_rect(int x, int y, int width, int height, uint16_t color) {
    for (int i = 0; i < height; i++) {
        gp_gfx_draw_line(x, y + i, x + width - 1, y + i, color);
    }
}

void gp_gfx_draw_circle(int x0, int y0, int radius, uint16_t color) {
    int x = radius;
    int y = 0;
    int err = 0;

    uint8_t bitmap[1];
    bitmap[0] = (color & 1) ? 0xFF : 0x00;

    while (x >= y) {
        gp_platform_gfx_write(x0 + x, y0 + y, 1, 1, bitmap);
        gp_platform_gfx_write(x0 + y, y0 + x, 1, 1, bitmap);
        gp_platform_gfx_write(x0 - y, y0 + x, 1, 1, bitmap);
        gp_platform_gfx_write(x0 - x, y0 + y, 1, 1, bitmap);
        gp_platform_gfx_write(x0 - x, y0 - y, 1, 1, bitmap);
        gp_platform_gfx_write(x0 - y, y0 - x, 1, 1, bitmap);
        gp_platform_gfx_write(x0 + y, y0 - x, 1, 1, bitmap);
        gp_platform_gfx_write(x0 + x, y0 - y, 1, 1, bitmap);

        y += 1;
        if (err <= 0) {
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void gp_gfx_update(void) {
    gp_platform_gfx_update();
}