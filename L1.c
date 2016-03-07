#include "L1.h"

int main()
{
	pid_t pid = 1;
	ARRAY array;
	int rv, i, fpp = 0, k = 0;
	clearfile("out.txt");
	if(pid > 0)
		array = getarray();
	for(i = 0; i < array.num; i++)
	{
		switch(pid = fork()) 
		{
		case -1:
		{
	        perror("fork"); 
	        exit(1);
			break;
		}
	    case 0:
		{
			int a = 0;
			FILE *fin = fopen("in.txt", "r");
			fseek(fin, fpp, SEEK_SET);
			char* string = (char *)calloc(array.ar[k] + 1, sizeof(char));
			fgets(string, array.ar[k] + 1, fin);
			sort(string);
			fclose(fin);
			free(string);
			free(array.ar);
			rv = -2;
	        exit(rv);
			break;
		}
	    default:
		{
	        wait(&rv);
			fpp += array.ar[k];
			k++;
			break;
		}
	    }
	}
 	getstring("out.txt", array.size);
	intotal();
	printf("\n");
	free(array.ar);
	return 0;
}