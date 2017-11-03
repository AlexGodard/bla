#include <sys/syscall.h>
#include <stdio.h>
#include "procdata.h"

#define sys_log710a2017as2 356

long getprocdata(void) {
	struct procdata pudata;
	long res = (long) syscall(sys_log710a2017as2(&pudata);

	printf("L'etat du processus est : %d\n", pudata.state);
	printf("Le PID du processus est : %d\n", pudata.pid);
	printf("Le PID du processus pere est : %d\n", pudata.parent_pid);
	printf("L'ID de l'utilisateur du processus est : %d\n", pudata.uid);
	printf("Le nom du programme (commande) ayant resulte en ce processus est : %s\n", pudata.comm);

	return res;
}

main() {
	printf("Le code de retour du nouvel appel systeme est : %d\n",
getprocdata());
	return 0;
}
