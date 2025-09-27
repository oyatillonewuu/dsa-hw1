#! /bin/bash

src=$(find ./src -name "*.cpp")

if [ $? -ne 0 ]; then
  echo "Could not find source files."
  exit 1
fi

g++ $src -o ./app

if [ $? -eq 0 ]; then
  echo "Build successful."
else
  echo "Build failed."
fi
