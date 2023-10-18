if lsmod | grep -q sysfs; then
    sudo rmmod sysfs
fi
make
sudo insmod sysfs.ko
make clean
