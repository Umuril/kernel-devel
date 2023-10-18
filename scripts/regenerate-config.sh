#!/bin/bash

make -C ../linux -j$(nproc) O=../build olddefconfig && 
make -C ../linux -j$(nproc) O=../build localmodconfig