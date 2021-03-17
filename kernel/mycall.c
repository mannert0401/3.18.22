#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

/*
asmlinkage long sys_mycall(void)
{
       printk(KERN_EMERG "My call test\n");
       return 1;
}
*/

unsigned int jbd2_psp_mode;
EXPORT_SYMBOL(jbd2_psp_mode);   
               
static int do_mycall(unsigned int psp_mode)
{       
	int tmp = jbd2_psp_mode;
	jbd2_psp_mode = psp_mode;

        printk("mycall: jbd2_psp_mode %u -> %u\n", tmp, jbd2_psp_mode);
        return 1;
}       
SYSCALL_DEFINE1(mycall, unsigned int, psp_mode)
{       
        return do_mycall(psp_mode);
}


