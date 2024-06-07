# Keybinding Configuration
The default configuration for keybindings looks like the following:
```ini
[options]
snare = 'S' 
hihat = 'D' 
kick = 'X'
```

To modify, **ONLY** change the character, e.g. `S`. This is to prevent anything
bad from happening. The code checks the 2nd character in specific indexes, so
something like
```ini
...
snare = 'use S'
```

will return `u`, and not `S`. Please make sure you keep this in mind as you
modify it.