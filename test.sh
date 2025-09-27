#!/bin/bash

src=$(find . -name "*.cpp")

echo "$src"

g++ $src -o ./test

echo "Built successfully."
