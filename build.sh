#!bin/bash

cd ./external/bgfxLib
git submodule init
git submodule update
cd ../../

if [ ! -d "./build" ]; then
    mkdir ./build
fi

cd build

cmake -DCMAKE_INSTALL_PREFIX=../install \
    -G "CodeLite - Unix Makefiles" \
    ..

make && make install


cd ..
