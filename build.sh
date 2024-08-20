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
if $0 = 'run.sh'; then 
    cd ..
    atari800 -xe -nobasic inst.obx
fi