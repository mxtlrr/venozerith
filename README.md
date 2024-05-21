# Venozerith
Tiny, fast and high BPM "blast-beat" generator. Written in C.

# Compilation

## Dependencies
- Raylib

## How To Compile
Once you have raylib installed you can just run
```
$ make
```

Output file will be in `bin/`

# Usage

| Key | Function |
| --- | -------- |
| `a` | Increase BPM |
| `d` | Decrease BPM |
| `x` | Start/Stop   |

Venozerith increase BPM in increments of 10, and by default starts at 240. It has an upper limit of 1600 BPM.
