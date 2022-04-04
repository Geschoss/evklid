#!/bin/bash
# Build script for engine
set echo on

mkdir -p ../bin

# Get a list of all the .c files.
cFilenames=$(find . -type f -name "*.c")

# echo "Files:" $cFilenames

assembly="engine"
compilerFlags="-g -shared -fdeclspec -fPIC"
# -fms-extensions 
# -Wall -Werror
includeFlags="-Isrc -I/opt/homebrew/include -I/usr/local/include"
# linkerFlags="-lvulkan -lxcb -lX11 -lX11-xcb -lxkbcommon -L/opt/homebrew/lib -L/usr/local/lib"
linkerFlags="-lvulkan  -L/opt/homebrew/lib -L/usr/local/lib"
defines="-D_DEBUG -DKEXPORT"

echo "Building $assembly..."
clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags