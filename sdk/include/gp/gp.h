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
#ifndef GP_H
#define GP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define GP_BUTTON_UP (1 << 0)
#define GP_BUTTON_DOWN (1 << 1)
#define GP_BUTTON_LEFT (1 << 2)
#define GP_BUTTON_RIGHT (1 << 3)
#define GP_BUTTON_SELECT (1 << 4)
#define GP_BUTTON_START (1 << 5)
#define GP_BUTTON_A (1 << 6)
#define GP_BUTTON_B (1 << 7)
#define GP_BUTTON_L1 (1 << 8)
#define GP_BUTTON_R1 (1 << 9)
#define GP_BUTTON_L2 (1 << 10)
#define GP_BUTTON_R2 (1 << 11)
#define GP_BUTTON_MENU (1 << 12)

typedef struct {
    int x;
    int y;
} gp_input_joystick_t;

typedef enum {
    GP_SCREEN_FORMAT_1BPP,
    GP_SCREEN_FORMAT_5R6G5B,
    GP_SCREEN_FORMAT_COUNT_,
} gp_screen_format_t;

typedef struct {
    const char* version;
    struct {
        int width;
        int height;
        gp_screen_format_t format;
    } screen;
    bool has_joystick_l;
    bool has_joystick_r;
    bool has_haptics;
} gp_capabilities_t;

void gp_init(void);
const gp_capabilities_t* gp_get_capabilities(void);

void gp_gfx_clear(uint16_t color);
void gp_gfx_draw_pixel(int x, int y, uint16_t color);
void gp_gfx_draw_rect(int x, int y, int width, int height, uint16_t color);
void gp_gfx_fill_rect(int x, int y, int width, int height, uint16_t color);
void gp_gfx_draw_circle(int x0, int y0, int radius, uint16_t color);
void gp_gfx_fill_circle(int x0, int y0, int radius, uint16_t color);
void gp_gfx_draw_line(int x0, int y0, int x1, int y1, uint16_t color);
void gp_gfx_draw_sprite(int x, int y, int width, int height, const uint8_t* bitmap);
void gp_gfx_update(void);

void gp_sys_delay(int ms);
uint32_t gp_sys_millis(void);
uint32_t gp_sys_random(void);

gp_input_joystick_t gp_input_get_joystick_l(void);
gp_input_joystick_t gp_input_get_joystick_r(void);
uint32_t gp_input_get_buttons(void);

#endif  // GP_H