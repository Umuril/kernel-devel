if lsmod | grep -q malloc_time; then
    sudo rmmod malloc_time
fi
make
sudo insmod malloc_time.ko
make clean
