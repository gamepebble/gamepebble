# Getting Started with GamePebble

This guide shows how to build and run your first GamePebble game.

---

## Prerequisites

### Host (Linux / macOS / Windows)
- CMake ≥ 3.20
- SDL2 development libraries

**Linux (Debian/Ubuntu):**
```bash
sudo apt install build-essential cmake libsdl2-dev
````

**macOS (Homebrew):**

```bash
brew install cmake sdl2
```

**Windows:**

* Install [MSYS2](https://www.msys2.org/), then:

  ```bash
  pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-SDL2
  ```

---

### WebAssembly

* Install [Emscripten](https://emscripten.org/docs/getting_started/downloads.html).
* Activate environment:

  ```bash
  source ~/emsdk/emsdk_env.sh
  ```

---

### STM32 Targets

* Install ARM GCC:

  ```bash
  sudo apt install gcc-arm-none-eabi
  ```
* Install `stlink` or use STM32CubeProgrammer for flashing.

---

## Building the Emulator

```bash
git clone https://github.com/<your-user>/gamepebble.git
cd gamepebble
cmake -S . -B build -DTARGET_HOST=ON
cmake --build build -j
./build/examples/hello_host
```

A window should open showing a bouncing block and “GamePebble”.

---

## Building for WebAssembly

```bash
emcmake cmake -S . -B build-web -DTARGET_WEB=ON
cmake --build build-web
```

Open `build-web/examples/hello_web.html` in your browser.

---

## Building for STM32 (F411 Lite example)

```bash
cmake -S . -B build-stm -DTARGET_STM32=ON \
  -DCMAKE_TOOLCHAIN_FILE=cmake/GPToolchainARM.cmake
cmake --build build-stm
st-flash write build-stm/examples/hello_stm32.bin 0x8000000
```

---

## Next Steps

* Read the [Graphics API](api-gfx.md) to learn drawing.
* Check the [Input API](api-input.md) to read buttons/joysticks.
* Browse `examples/` for sample games.
* Use `tools/gp.py` to convert PNG/WAV assets into embedded C arrays.

---

## Troubleshooting

* **SDL2 not found**: make sure dev package is installed (`libsdl2-dev`).
* **Emscripten errors**: run `source emsdk_env.sh` before building.
* **STM32 flash failed**: check USB cable and board jumpers; try DFU mode.
