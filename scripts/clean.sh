export CC="ccache gcc"

make CC="ccache gcc" -C ../linux -j$(nproc) O=../build clean 

