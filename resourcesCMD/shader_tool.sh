#!bin/bash

shaderc -f shaders/$1 -o ../resources/shaders/glsl/$2 --platform osx --type $3