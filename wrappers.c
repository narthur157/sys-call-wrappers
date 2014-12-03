#include <stdlib.h>
#include <stdio.h>
#include <signal.h> 
#include <unistd.h>
#include <sys/types.h>
int forkChk() {
	int cpid = 0;
	if ((cpid=fork()) == -1) {
		perror("fork");
		exit(1);
	}
	return cpid;
}
int killChk(pid_t pid, int sig) {
	int result = kill(pid, sig);
	if (result == -1) {
		perror("kill");
		exit(1);
	}
	return result;
}
int dup2Chk(int a, int b) {
	int result=-1;
	if ((result=dup2(a,b)) == -1) {
		perror("dup2");
		exit(1);
	}
	return result;
}
int closeChk(int a) {
	int result=-1;
	if ((result=close(a)) == -1) {
		perror("close");
		exit(1);
	}
	return result;
}
FILE* fopenChk(char* name, char* mode) {
	FILE* f;
	if ((f=fopen(name,mode)) == 0) {
		perror("fopen");	
		exit(1);
	}
	return f;
}
int* pipeChk() {
	int *fds = calloc(2, sizeof(int));
	if (pipe(fds) == -1) {
		perror("pipe");
		exit(1);
	}
	return fds;
}

FILE* freopenChk(const char *path, const char *mode, FILE *stream) {
	FILE* retVal = freopen(path, mode, stream);
	if (retVal == NULL) {
		perror("freopen");
	}
	return retVal;
}
	
	
