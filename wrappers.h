
#ifndef WRAP_H_G
#define WRAP_H_G
// this does basic error checking so that things don't go mysteriously wrong. 
// If something bad happens, you'll at least know what call is at fault
int killChk(pid_t pid, int sig);
int forkChk();
int dup2Chk(int a, int b);
int closeChk(int a);
FILE* fopenChk(char* name, char* mode); 
int* pipeChk(); 
FILE* freopenChk(const char *path, const char *mode, FILE *stream);
#endif
