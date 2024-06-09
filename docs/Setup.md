# How To Setup Venozerith?

First, make a directory called `config`, and make sure it has the following
general directory tree
```
config/
|
|------ keys.ini
|------ theme.ini
|------ samples/
        |
        |-------- hihat.mp3
        |-------- kick.mp3
        |-------- snare.mp3
```

Then, make sure the venozerith binary is in the same directory where the
`config/` directory, e.g.
```
$ ls
venozerith* config/
```

Then you can easily just run venozerith with `./venozerith`