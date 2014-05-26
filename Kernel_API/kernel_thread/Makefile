task_module := kernel_thread
obj-m   := $(task_module).o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD       := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.order *.symvers

load:
	insmod ./$(task_module).ko

unload:
	rmmod $(task_module)
