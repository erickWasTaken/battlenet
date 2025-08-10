#!/bin/bash

warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations -Wno-switch"

if [[ "$(uname)" == "Linux" ]]; then
    echo "Running on Linux"
    libs="-lGL"
    outputFile=app
fi

clang++ -g src/main.cpp -o$outputFile $libs $warnings
