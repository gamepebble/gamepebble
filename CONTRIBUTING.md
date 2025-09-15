# Contributing to GamePebble

Thank you for your interest in contributing! 🎉

We welcome pull requests for:
- Bug fixes
- New examples and demo games
- Improvements to the emulator
- New platform HALs (other MCUs, displays, etc.)
- Documentation

---

## Workflow

1. **Fork & Clone**
   ```bash
   git clone https://github.com/<your-user>/gamepebble.git
   cd gamepebble
    ```

2. **Create a Branch**

   ```bash
   git checkout -b feature/my-cool-change
   ```

3. **Build & Test**

   * Host emulator build (Linux/macOS/Windows):

     ```bash
     cmake -S . -B build -DTARGET_HOST=ON
     cmake --build build -j
     ./build/examples/hello_host
     ```
   * Make sure examples run correctly.

4. **Code Style**

   * C code formatted with `clang-format` (`.clang-format` is provided).
   * Commit messages: `type(scope): description`

     * e.g., `fix(gfx): correct clipping at edge`
     * e.g., `feat(audio): add streaming API`

5. **Commit & Push**

   ```bash
   git add .
   git commit -m "feat(example): add bouncing ball demo"
   git push origin feature/my-cool-change
   ```

6. **Open a Pull Request**

   * Describe what changed and why.
   * Link issues if applicable.

---

## Issue Reporting

* Use the provided templates in `.github/ISSUE_TEMPLATE/`.
* Include system info, target (host/web/stm32), and reproduction steps.

---

## License

By contributing, you agree your code is released under the [MIT License](LICENSE).

