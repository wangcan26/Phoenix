#!bin/bash

cd ./external/bgfxLib
git submodule init
git submodule update
cd ../

if [ ! -d "./build" ]; then
    mkdir ./build
fi

cd build

cmake -DCMAKE_INSTALL_PREFIX=../../install \
    -DBGFX_BUILD_EXAMPLES=ON \
    -DBGFX_INSTALL_EXAMPLES=ON \
    -G "CodeLite - Unix Makefiles" \
    ..

make -j8 && make install

cd ../..