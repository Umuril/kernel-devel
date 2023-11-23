if lsmod | grep -q hello; then
    sudo rmmod hello
fi
make
sudo insmod hello.ko
make clean
