obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) O=/home/user/build modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) O=/home/user/build clean
