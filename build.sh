#!/bin/bash
cd src/
g++ main.cpp -o main
chmod +x main
mv main ../
cd ../
./main
rm main
cp inst.pas ./buildtools
cd buildtools
./mp inst.pas -ipath:lib -target:a8
./mads inst.a65 -x -i:base
mv inst.obx ../
echo $1;
if [ $1 = "run" ]; then 
    cd ../
    atari800 -xe -nobasic ./inst.obx
fi