obj-m += malloc_time.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) O=/home/user/kernel-devel/build modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) O=/home/user/kernel-devel/build clean
