# https://docs.kernel.org/kbuild/reproducible-builds.html
export KBUILD_BUILD_TIMESTAMP=`date +'%Y-%m-%d %H:%M:%S'`

make -C ../linux -j$(nproc) O=../build olddefconfig && 
make -C ../linux -j$(nproc) O=../build && 
make -C ../linux -j$(nproc) O=../build modules
