#ifdef __linux__
	#define FLUSH __fpurge(stdin)
#endif

#ifdef _WIN32
	#define FLUSH fflush(stdin)
#endif

#ifdef _WIN64
	#define FLUSH fflush(stdin)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <string.h>

typedef struct ARRAY
{
	int num,
	    size,
	    *ar;
} ARRAY;

int scani(float);
ARRAY getarray();
void sort(char *);
char* getstring(const char *, int);
void clearfile(const char *);
void intotal();
