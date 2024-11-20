> [!WARNING]
> This project is not anywhere close to a stable release, and bugs may be present.

# Venozerith
Venozerith is a cross platform (Windows + Linux), drum-only DAW written in C, with minimal dependencies.
It uses Raylib as it's GUI.

# Getting Raylib on Windows
You can skip steps 1 through 4 if you already installed raylib previously.

1. Download [w64devkit](https://github.com/skeeto/w64devkit)
2. Download the [raylib distribution](https://github.com/raysan5/raylib/releases/download/5.0/raylib-5.0_win64_mingw-w64.zip)
3. Copy every file from `lib` and `include` into `w64devkit/x86_64-w64-mingw32/lib` and `w64devkit/x86_64-w64-mingw32/include`, respectively
4. Boot up `w64devkit.exe`
5. `cd` into this repository
6. Run `make`.

The output will be in `bin/`

## Screenshots
TODO

# Acquiring Venozerith
Venozerith will only sometimes release a stable version, so if the features on said
version match up to what you want, you can grab it from there.

## Compiling from source
This is only for *bleeding edge*, and as such, may be broken. If you would like
to proceed, you'll just need:
1. A C compiler (GCC is what I personally use)
2. A copy of [raylib](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux), either from your package manager or compiled 
yourself.

Once you have both of these things, you just need to run `make`. The output
will be in `bin`