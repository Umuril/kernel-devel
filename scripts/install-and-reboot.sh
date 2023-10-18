sudo make -C ../linux -j$(nproc) O=../build modules_install && 
sudo make -C ../linux -j$(nproc) O=../build install && 
sudo reboot now
