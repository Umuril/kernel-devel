# https://docs.kernel.org/kbuild/reproducible-builds.html
export KBUILD_BUILD_TIMESTAMP=`date +'%Y-%m-%d %H:%M:%S'`
export CC="ccache gcc"

make CC="ccache gcc" -C ../linux -j$(nproc) O=../build && 
make CC="ccache gcc" -C ../linux -j$(nproc) O=../build modules
