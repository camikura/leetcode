#!/usr/bin/env bash

set -eu

cmake -B build && cd build
cmake .. -DNOT_LEETCODE
cmake --build .
ctest --verbose
