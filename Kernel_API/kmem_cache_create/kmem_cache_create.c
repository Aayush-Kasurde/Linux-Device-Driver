/********************************************************************************
* File Name:	kmem_cache_create.c
********************************************************************************/

#include <linux/slab.h> 
#include <linux/init.h> 
#include <linux/module.h> 

static int __init kmem_cache_create_init(void); 
static void __exit kmem_cache_create_exit(void);

char * mem_spvm = NULL; 
struct kmem_cache *my_cachep = NULL;

int __init kmem_cache_create_init(void) 
{ 	 
	my_cachep = kmem_cache_create("my_cache", 32, 0, SLAB_HWCACHE_ALIGN, NULL); 	 
	if(my_cachep == NULL ) 
		printk("kmem_cache_create failed!\n"); 
	else 
	{ 
		printk("Cache size is: %d\n",kmem_cache_size(my_cachep)); 
		printk("Cache name is: %s\n", kmem_cache_name( my_cachep )); 
	} 	 
	return 0; 
}

void __exit kmem_cache_create_exit(void) 
{ 	 
	if(my_cachep) 
	{ 
		kmem_cache_destroy(my_cachep); 
		printk("kmem_cache_destroy succeed!\n"); 
	}	 
	printk("exit!\n"); 
}

module_init(kmem_cache_create_init); 
module_exit(kmem_cache_create_exit);
MODULE_LICENSE("GPL"); 