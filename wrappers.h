
#ifndef WRAP_H_G
#define WRAP_H_G
// this does basic error checking so that things don't go mysteriously wrong. 
// If something bad happens, you'll at least know what call is at fault
int closeChk(int fd); 
ssize_t getlineChk(char **lineptr, size_t *n, FILE *stream); 
ssize_t writeChk(int fildes, const void *buf, size_t nbyte);
int openChk(const char *path, int oflag); 
ssize_t readChk(int fildes, void *buf, size_t nbyte); 
int killChk(pid_t pid, int sig);
int forkChk();
int dup2Chk(int a, int b);
int closeChk(int a);
FILE* fopenChk(char* name, char* mode); 
int* pipeChk(); 
FILE* freopenChk(const char *path, const char *mode, FILE *stream);
void* mallocChk(size_t size);
void* callocChk(size_t num, size_t size);
#endif
