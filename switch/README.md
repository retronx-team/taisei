Taisei Switch Port
==================

<p align="center"><img src="icon.jpg"></p>

## Installation

### Grabbing Binaries

Download the latest release,
and extract the archive in the `/switch` folder on your SD Card. 
Then, run the game from the [hbmenu](https://github.com/switchbrew/nx-hbmenu)
using [hbl](https://github.com/switchbrew/nx-hbloader).

**WARNING:** This will crash if executed from an applet such as the Photo/Library applet,
be sure to launch it from hbmenu on top of the game of your choice,
which can be done by holding R over any installed title on latest Atmosphère, with default settings.

### Build dependencies

For building, you need the devkitA64 from devkitPro setup, along with switch portlibs and libnx. 
Documentation to setup that can be found [here](https://switchbrew.org/wiki/Setting_up_Development_Environment).

You will need the following packages/group installed from devkitPro pacman: 
`switch-dev switch-portlibs dkp-toolchain-vars switch-pkg-config`

Also, SDL3 has not been published as a package yet, but you can build it from [source](https://github.com/p-sam/SDL/tree/switch-sdl-3.4)

Other dependencies common to the main targets include:

    * meson >= 0.45.0 (build system; >=0.48.0 recommended)
    * Python >= 3.14 (or with zstd api backported)
    * ninja
    * gettext

### Compiling from source

Run one of the following commands from the project root:

```
mkdir -p ./build/nx
./switch/crossfile.sh > ./build/nx/crossfile.txt
meson setup --cross-file="./build/nx/crossfile.txt" . ./build/nx
ninja -C ./build/nx
```

**Note:** You can optionally set a custom prefix and `ninja install` NRO and assets into that folder.