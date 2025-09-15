# 🎮 GamePebble
Pocket-sized retro console you can code for in C

![Build](https://img.shields.io/github/actions/workflow/status/<your-user>/gamepebble/ci.yml?branch=main)
![License](https://img.shields.io/github/license/<your-user>/gamepebble)
![Platform](https://img.shields.io/badge/platform-STM32%20%7C%20Linux%20%7C%20Windows%20%7C%20WebAssembly-blue)

> **GamePebble** is a tiny open handheld project:  
> - Portable SDK for making retro-style games in C  
> - Cross-platform (STM32 microcontrollers, Linux/Windows emulator, WebAssembly)  
> - Target hardware: 128×64 OLED → up to 320×240 RGB TFT, buttons/joysticks, piezo, haptics  
> - Powered by a single 18650 cell  

---

## ✨ Features

- **SDK in C** with a stable API (`gfx`, `input`, `audio`, `sys`)  
- **Emulator** (SDL2) for Linux/Windows/Mac — develop instantly  
- **WebAssembly** target — play your games in the browser  
- **Embedded firmware** for STM32 Cortex-M3/M4 boards  
- **Asset pipeline** (PNG → sprites, WAV → PCM)  
- **Examples** (hello world, snake, more coming)  

---

## 🚀 Getting Started

### Prerequisites

- **Host builds**:  
  - CMake ≥ 3.20  
  - SDL2 dev package (`libsdl2-dev` on Linux)  
- **Web builds**:  
  - [Emscripten](https://emscripten.org/docs/getting_started/downloads.html)  
- **STM32 builds**:  
  - `arm-none-eabi-gcc` toolchain  
  - ST-Link or DFU for flashing  

### Clone

```bash
git clone https://github.com/<your-user>/gamepebble.git
cd gamepebble
````

### Build (Host Emulator)

```bash
cmake -S . -B build -DTARGET_HOST=ON
cmake --build build -j
./build/examples/hello_host
```

### Build (WebAssembly)

```bash
emcmake cmake -S . -B build-web -DTARGET_WEB=ON
cmake --build build-web
# open build-web/examples/hello_web.html in browser
```

### Build (STM32, e.g. F411 Lite)

```bash
cmake -S . -B build-stm -DTARGET_STM32=ON \
  -DCMAKE_TOOLCHAIN_FILE=cmake/GPToolchainARM.cmake
cmake --build build-stm
# flash build-stm/examples/hello_stm32.bin with st-flash
```

---

## 📂 Repo Structure

```
sdk/         # Public API headers + core code
platforms/   # HAL backends (host_sdl, web_sdl, stm32 boards)
examples/    # Hello world, snake, demos
tools/       # Asset pipeline scripts (png2sprite, wav2pcm)
docs/        # Guides and API references
```

---

## 🕹 Example Game Loop

```c
#include "gp/gp.h"

static void update(uint32_t dt) {
    gp_input_t in = input_poll();
    gfx_clear(0);
    if (in.buttons & GP_BTN_A) {
        gfx_text(10, 10, "Hello GamePebble!", 1);
        audio_tone(880, 100);
    }
    gfx_present();
}

int main(void) {
    gp_init(NULL);
    for (;;) gp_frame(update);
}
```

---

## 📖 Documentation

* [Getting Started](docs/getting-started.md)
* [Graphics API](docs/api-gfx.md)
* [Input API](docs/api-input.md)
* [Audio API](docs/api-audio.md)
* [System API](docs/api-sys.md)
* [Asset Pipeline](docs/asset-pipeline.md)

---

## 🔮 Roadmap

* [ ] Core SDK stable 1.0
* [ ] Emulator features (scaling, hot reload, screenshots)
* [ ] WebAssembly demo site with hosted examples
* [ ] Hardware reference design (KiCad, BOM, STL case)
* [ ] Community game jam 🎉

---

## 🤝 Contributing

Pull requests are welcome!
See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines and coding style.

---

## 📜 License

[MIT](LICENSE)

---

## 📸 Screenshots

*(Coming soon — emulator GIFs and hardware photos here)*

---
