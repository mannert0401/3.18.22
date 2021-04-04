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

#ifdef DEBUG_OPENAT
extern int openat_count[40];
extern s64 openat_intv[40];
#endif

#ifdef DEBUG_CREATE
extern s64 intv_create[160];
extern int count_create[40];
#endif

#ifdef DEBUG_EXT4_CREATE
extern s64 intv_ext4_create[160];
extern int count_ext4_create[40];
#endif

#ifdef DEBUG_EXT4_INODE
extern s64 intv_create_inode[160];
extern int count_create_inode[40];
#endif

#ifdef DEBUG_JOURNAL_START
extern s64 intv_journal_start[120];
extern int count_journal_start[40];
#endif

#ifdef DEBUG_JOURNAL_START_SB
extern s64 intv_journal_start_sb[120];
extern int count_journal_start_sb[40];
#endif

#ifdef DEBUG_HANDLE
extern s64 intv_handle[240];
extern int count_handle[40];
#endif

static int do_mycall(unsigned int psp_mode)
{       
	int tmp = jbd2_psp_mode;
	jbd2_psp_mode = psp_mode;
	
        printk("mycall: jbd2_psp_mode %u -> %u\n", tmp, jbd2_psp_mode);

#ifdef DEBUG_OPENAT
	for(tmp=0; tmp<40; tmp++) {
		openat_count[tmp] = 0;
		openat_intv[tmp] = 0;
	}
#endif
#ifdef DEBUG_CREATE
	for(tmp=0; tmp<40; tmp++) {
		intv_create[4*tmp] = 0;
		intv_create[4*tmp+1] = 0;
		intv_create[4*tmp+2] = 0;
		intv_create[4*tmp+3] = 0;
		count_create[tmp] = 0;
	}
#endif
#ifdef DEBUG_EXT4_CREATE
	for(tmp=0; tmp<40; tmp++) {
		intv_ext4_create[4*tmp] = 0;
		intv_ext4_create[4*tmp+1] = 0;
		intv_ext4_create[4*tmp+2] = 0;
		intv_ext4_create[4*tmp+3] = 0;
		count_ext4_create[tmp] = 0;
	}
#endif
#ifdef DEBUG_EXT4_INODE
	for(tmp=0; tmp<40; tmp++) {
		intv_create_inode[4*tmp] = 0;
		intv_create_inode[4*tmp+1] = 0;
		intv_create_inode[4*tmp+2] = 0;
		intv_create_inode[4*tmp+3] = 0;
		count_create_inode[tmp] = 0;
	}
#endif
#ifdef DEBUG_JOURNAL_START
	for(tmp=0; tmp<40; tmp++) {
		intv_journal_start[3*tmp] = 0;
		intv_journal_start[3*tmp+1] = 0;
		intv_journal_start[3*tmp+2] = 0;
		count_journal_start[tmp] = 0;
	}
#endif
#ifdef DEBUG_JOURNAL_START_SB
	for(tmp=0; tmp<40; tmp++) {
		intv_journal_start_sb[3*tmp] = 0;
		intv_journal_start_sb[3*tmp+1] = 0;
		intv_journal_start_sb[3*tmp+2] = 0;
		count_journal_start_sb[tmp] = 0;
	}
#endif
#ifdef DEBUG_HANDLE
	for(tmp=0; tmp<40; tmp++) {
		intv_handle[6*tmp] = 0;
		intv_handle[6*tmp+1] = 0;
		intv_handle[6*tmp+2] = 0;
		intv_handle[6*tmp+3] = 0;
		intv_handle[6*tmp+4] = 0;
		intv_handle[6*tmp+5] = 0;
		count_handle[tmp] = 0;
	}
#endif

        return 1;
}       
SYSCALL_DEFINE1(mycall, unsigned int, psp_mode)
{       
        return do_mycall(psp_mode);
}


