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
#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdio.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_SCALE 4

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static char buffer[SCREEN_WIDTH * SCREEN_HEIGHT] = {0};

void gp_platform_init(void) {
    printf("Initializing platform-specific resources...\n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("GamePebble", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH * SCREEN_SCALE,
                              SCREEN_HEIGHT * SCREEN_SCALE, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

void gp_platform_process(void) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                exit(0);
            }
        }
    }
}

void gp_platform_gfx_write(int x, int y, int width, int height, const uint8_t* bitmap) {
    for (int xi = 0; xi < width; xi++) {
        for (int yj = 0; yj < height; yj++) {
            buffer[(y + yj) * 128 + (x + xi)] = bitmap[xi * height + yj];
        }
    }
}

void gp_platform_gfx_update(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_SCALE; i++) {
        for (int j = 0; j < SCREEN_HEIGHT * SCREEN_SCALE; j++) {
            uint8_t color = buffer[(j / SCREEN_SCALE) * SCREEN_WIDTH + (i / SCREEN_SCALE)] ? 255 : 0;
            SDL_SetRenderDrawColor(renderer, color, color, color, 255);
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
    SDL_RenderPresent(renderer);
}

void gp_platform_delay(uint32_t ms) {
    SDL_Delay(ms);
}

uint32_t gp_platform_millis(void) {
    return SDL_GetTicks();
}