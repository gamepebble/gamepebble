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
#include "gp_platform.h"
#include <stdint.h>
#include <stdio.h>

void gp_platform_init(void) {
    printf("Initializing platform-specific resources...\n");
}

void gp_platform_gfx_write(int x, int y, int width, int height, const uint8_t* bitmap) {
    printf("Writing graphics to (%d, %d) [%d x %d]\n", x, y, width, height);
}

void gp_platform_gfx_update(void) {
    printf("Updating graphics display...\n");
}

void gp_platform_delay(uint32_t ms) {
    printf("Delaying for %d milliseconds...\n", ms);
}

uint32_t gp_platform_millis(void) {
    printf("Getting current milliseconds since initialization...\n");
    return 0;
}