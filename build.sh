#!/bin/bash

includes="-I$VCPKG_ROOT/installed/x64-linux/include -Iextern"
warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations -Wno-switch -Wno-unused-result"
buildpath="build"

if [[ "$(uname)" == "Linux" ]]; then
    echo "Running on Linux"
    libs="-lGL -lsfml-graphics -lsfml-system -lsfml-window"
    outputFile=unix
fi

if [ -d "build" ]; then
    echo "build directory found! Building files accordingly..."
else
    mkdir build
fi

clang++ $includes -g main.cpp -o$outputFile $libs $warnings
mv $outputFile $buildpath

