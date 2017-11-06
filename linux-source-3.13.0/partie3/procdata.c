#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include "procdata.h"

#include <asm/uaccess.h>
#include <asm/current.h>
#include <asm/errno.h>

asmlinkage long sys_log710a2017as2(struct procdata *pudata) {
	struct procdata kdata;

	kdata.state = current->state;
	kdata.pid = task_tgid_vnr(current);
	rcu_read_lock();
	kdata.parent_pid = task_tgid_vnr(current->real_parent);
	rcu_read_unlock();
	kdata.uid = current_uid().val;
	strcpy(kdata.comm, current->comm);

	if (copy_to_user(pudata, &kdata, sizeof kdata)) {
		return -EFAULT;
	}
	printk(KERN_ALERT "LOG710 AUTOMNE 2017 Appel Systeme 02!\n");
	return 0;
}
