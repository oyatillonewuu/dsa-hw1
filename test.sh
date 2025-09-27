#!/bin/bash

src=$(find ./src/data_structures ./src/utils ./tests -name "*.cpp")

if [ $? -ne 0 ]; then
  echo "Could not find source files."
  exit 1
fi

echo "$src"

g++ $src -o ./test

if [ $? -eq 0 ]; then
  echo "Test build successfull."
else
  echo "Test build failed."
fi
