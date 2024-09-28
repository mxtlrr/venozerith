> [!WARNING]
> This project is not anywhere close to a stable release, and bugs may be present.

# Venozerith
Venozerith is a linux-only, drum-only DAW written in C, with minimal dependencies.
It uses Raylib as it's GUI.

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