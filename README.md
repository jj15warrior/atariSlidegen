# atari slidegen

this is a compression engine designed specifically to pack and display images on 8-bit atari computers

tested on:
- 800
- 65XE

it's based on:
- [tebe6502](https://github.com/tebe6502) `mads` and `mad-pascal`. Both are amazing projects and their MIT license is inside the buildtools folder.
- [nothings](https://github.com/nothings) `stb lib` for quickly loading, resizing and saving images from C++
- atari slidegen 1.0 that was lost in a disk format

## Usage

## Linux
This was tested under arch, but should work on other distros

1. Clone this repo
2. Pick an image of your choosing, and put it in the root folder of this repo under the name image.png ` note: other image formats might also work, did not test that. Anyway, rename them to image.png`

__automatic build:__

3. Run the `build.sh` script

__manual build:__

First, build the c++ project
```console
cd src/;
g++ main.cpp -o main;
chmod +x ./main
```
Then, run it in the root directory
```console
mv ./main ../
cd ../
./main
```
This generates the compressed pascal output and might take a few seconds depending on the images complexity

Next, move inst.pas to the buildtools folder and compile it using the mad toolchain
```console
mv inst.pas buildtools/
cd buildtools;
./mp inst.pas -ipath:lib -target:a8 # generate the object file
./mads inst.a65 -x -i:base # assemble it to an executable format
```
the output file is inst.obx

4. The last step is to actually run this program and see the result. This depends on your setup, as you can either flash it onto a tape, copy onto a SD card (for sd to tape adapters) or emulate it

this is how to emulate it using the atari800 emulator
```console
atari800 -xe -nobasic ./inst.obx
```

## windows

You have to provide your own mp.exe and mads.exe binaries which can be found in tebe6502 projects. Put them inside buildtools/ and it should work. Keep in mind that the build.sh script won't work and you'll have to do it manually.




