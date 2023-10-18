# https://docs.kernel.org/kbuild/reproducible-builds.html
KBUILD_BUILD_TIMESTAMP=`date +'%Y-%m-%d %H:%M:%S'`
KBUILD_BUILD_USER=user
KBUILD_BUILD_HOST=host
KCFLAGS=-ffile-prefix-map=OLD=NEW


make -C ../linux -j$(nproc) O=../build olddefconfig && 
make -C ../linux -j$(nproc) O=../build && 
make -C ../linux -j$(nproc) O=../build modules
