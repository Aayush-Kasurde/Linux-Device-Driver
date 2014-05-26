#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pid.h>
#include <linux/sched.h>

int kernel_thread_function(void * argc)
{
	pr_info("In the kernel function\n");
	pr_info("Current PID is %d\n", current->pid);
	return 0;
}
static int __init task_eight_init_module(void)
{
	int ret;
	pr_info("Kernel thread example - start\n");
	ret = kernel_thread(kernel_thread_function, NULL, CLONE_KERNEL);
	pr_info("Kernel thread result %d\n", ret);
	pr_info("Current PID is %d\n", current->pid);
	return 0;
}

static void __exit task_eight_exit_module(void)
{
	pr_info("Kernel thread example - end\n");
}

module_init(task_eight_init_module);
module_exit(task_eight_exit_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aayush Kasurde");
MODULE_DESCRIPTION("Kernel Thread example");
