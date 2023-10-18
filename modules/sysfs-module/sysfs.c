#define pr_fmt(fmt) 	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sysfs.h>

#include <linux/printk.h>


static ssize_t bit_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "Hello, world!\n");
}

static ssize_t bit_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	if (buf && buf[count-1] == '\n') {
		pr_info("I got '%s' :D\n", buf);
	}	
	return count;
}


static struct kobj_attribute bit_attr = __ATTR_RW(bit);
static struct kobject *sysfs_kobj;

int init_module(void) {
	int error;
	pr_info("Hello, I am a cool small module!\n");
	sysfs_kobj = kobject_create_and_add("sysfs", kernel_kobj);
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
