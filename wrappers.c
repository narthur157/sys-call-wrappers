#include <stdlib.h>
#include <stdio.h>
#include <signal.h> 
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t getlineChk(char **lineptr, size_t *n, FILE *stream) {
	ssize_t result = getline(lineptr, n, stream);
	if (result < 0) {
		perror("getline");
		exit(1);
	}
	return result;
}
int closeChk(int fd) {
	int result = close(fd);
	if (result < 0) {
		perror("close");
		exit(1);
	}
	return result;
}
ssize_t writeChk(int fildes, const void *buf, size_t nbyte) {
	int result = write(fildes, buf, nbyte);
	if (result < 0) {
		perror("write");
		exit(1);
	}
	return result;
}
int openChk(const char *path, int oflag) {
	int result = open(path, oflag);
	if (result < 0) {
		perror("openChk");
	}
	return result;
}
ssize_t readChk(int filedes, void *buf, size_t nbyte) {
	int result = read(filedes, buf, nbyte);
	if (read < 0) {
		perror("read");
		exit(1);
	}
	return result;
}
void* mallocChk(size_t size) {
	void* result = malloc(size);
	if (result == NULL) {
		perror("malloc");
		exit(1);
	}
	return result;
}
void* callocChk (size_t num, size_t size) {
	void* result = calloc(num, size);
	if (result == NULL) {
		perror("calloc");
		exit(1);
	}
	return result;
}
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
	
	
