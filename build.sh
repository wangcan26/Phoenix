#!bin/bash
if [ ! -d "./build" ]; then
    mkdir ./build
fi

cd build

cmake -DCMAKE_INSTALL_PREFIX=../install \
    -G "CodeLite - Unix Makefiles" \
    ..

cd ..
