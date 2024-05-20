# LVGL web simulator project with EEZ Studio

## How to get started

### Install SDL

Downlad [SDL](https://www.libsdl.org/) (a graphics library to open a window and handle the mouse). On Linux:
1. Find the current version of SDL2: `apt-cache search libsdl2 (e.g. libsdl2-2.0-0)`
2. Install SDL2: `sudo apt-get install libsdl2-2.0-0` (replace with the found version)
3. Install SDL2 development package: `sudo apt-get install libsdl2-dev`
4. If build essentials are not installed yet: `sudo apt-get install build-essential`

### Install Emscripten SDK
Download the [Emscripten SDK](https://kripken.github.io/emscripten-site/) and make sure it is in your PATH.

1. `git clone https://github.com/emscripten-core/emsdk.git`
2. `cd <path-to-emsdk>`
3. `git pull`
4. `./emsdk install latest`
5. `./emsdk activate latest`
6. `source ./emsdk_env.sh`

More info here: https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

### Build the project
1. `cd C:\Users\mvladic\eez-projects\native-interface-lvgl-with-flow.eez-project`
2. `mkdir build`
3. `cd build`
4. `emcmake cmake ..`
5. `emmake make -j4`
6. A file called `index.html` will be generated. Run this in your browser.

#### Known issue with Google Chrome browser
Chrome can't open the generated html file offline. It works if you copy the files to a server. Use Firefox or other browser for offline testing.

#### Known issue with Firefox
Firefox can't open the generated html file offline unless you go to `about:config` and change `privacy.file_unique_origin` to `false`.
