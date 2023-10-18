#!/bin/bash

make -C ../linux -j$(nproc) O=../build localmodconfig
