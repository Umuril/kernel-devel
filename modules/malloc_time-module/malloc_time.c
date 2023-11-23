#define pr_fmt(fmt) 	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sysfs.h>
#include <linux/ktime.h>
#include <linux/printk.h>


static ssize_t bit_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "Hello, world with some time!\n");
}

static ssize_t bit_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	u64 start_time;
	long siz;

	int res = kstrtol(buf, 10, &siz);
	if (res < 0)
		return res;

	start_time = ktime_get_ns();
	char * blocco = (char *)kmalloc(siz, GFP_KERNEL);
	if (blocco == NULL) {
		pr_crit("Non sono riuscito ad allocare %ld bytes.\n", siz);
		return -1;
	}
	pr_crit("Allocati %ld bytes in %lld ns\n", siz, ktime_get_ns() - start_time);

	start_time = ktime_get_ns();
	for(int i = 0; i < siz; ++i) {
		blocco[i] = 0x42;
	}
	pr_crit("Scritti %ld bytes in %lld ns\n", siz, ktime_get_ns() - start_time);

	start_time = ktime_get_ns();
	kfree(blocco);
	pr_crit("Liberati %ld bytes in %lld ns\n", siz, ktime_get_ns() - start_time);

	return count;
}


static struct kobj_attribute bit_attr = __ATTR_RW(bit);
static struct kobject *sysfs_kobj;

int init_module(void) {
	int error;
	pr_info("Hello, I am a cool small module!\n");
	sysfs_kobj = kobject_create_and_add("KUSTOM", kernel_kobj);
	if (!sysfs_kobj) {
		return -ENOMEM;
	}
	error = sysfs_create_file(sysfs_kobj, &bit_attr.attr);
	if (error) {
		pr_debug("Cannot create sysfs file 'hello'!\n");
	}
	return error;
}

void cleanup_module(void) {
	kobject_put(sysfs_kobj);
	pr_info("I am removed :(\n");
}

MODULE_LICENSE("GPL");
