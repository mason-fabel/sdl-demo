# sdl-demo
I like having fun with graphics programming, and SDL appears to let me get to the fun bits in a cross-platform way. I have no particular goals
for this project, other than putting some pixels on the screen in a way that makes me happy.

## Dependencies
Currently, `sdl-demo` depends on the following homebrew packages:
- `sdl2`
- `sdl2_image`

You should be able to `brew install <package>` to install dependencies. The makefile has assumptions about where homebrew installs packages.
I believe these assumptions match homebrew defaults, but I make no guarantees.

## Building
From the root directory, run `make`. This should build the `sdl-demo` executable.

## Run
From the root directory, run `./sdl-demo`.
