# SDL Snakes

This is a simple snake game written in C using the SDL2 library. The game features a snake that moves around the screen,
collecting food and growing in length. The player controls the snake's direction using the arrow keys.

This was just a way for me to refamiliarize myself with SDL, and learn more modern C and build systems.

## Building

You need the following:

- SDL2
- SDL2_ttf
- clang
- ninja
- cmake

On Arch Linux, you can install these dependencies using the following command:

```bash
sudo pacman -S sdl2 sdl2_ttf clang cmake ninja
```

On Ubuntu, you can install these dependencies using the following command:

```bash
sudo apt-get install libsdl2-dev libsdl2-ttf-dev clang cmake ninja-build
```

Once you have the dependencies installed, you can build the game using the following commands:

```bash
cmake .
ninja
```

This will create an executable file called `snakes` in the `bin` directory.


