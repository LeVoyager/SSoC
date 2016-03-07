#include "L1.h"

int scani(float sz)
{
	int c;
	do
	{
		FLUSH;
		if (!scanf("%d", &c) || c < 1 || c > sz)
		{
			printf("Input error! Try again, please: ");
			continue;
		}
		else
		{
			return c;
			break;
		}
	} while (1);
}

ARRAY getarray()
{
	ARRAY array;
	float sz = 0, ctr = 0;
	int i;
	FILE *fin = fopen("in.txt", "r");
	while(fgetc(fin) != EOF)
		sz++;
	printf("\nInput process's number, from 1 to %.0f: ",sz);
	array.size = sz;
	array.num = scani(sz);
	array.ar = (int *)calloc(array.num, sizeof(int));
	for(i = array.num; i > 0; i--)
	{
		ctr = sz/i;
		if(sz - ceil(ctr) >= 0)
			ctr = ceil(ctr);
		array.ar[array.num - i] = ctr;
		sz -= ctr;
	}
	fclose(fin);
	return array;
}

void sort(char *string)
{
	int i, j;
	char c;
	for(i = 0; i < strlen(string) - 1; i++)
	{
		for(j = 0; j < strlen(string) - 1 - i; j++)
		{
			if(string[j] > string[j + 1])
			{
				c = string[j + 1];
				string[j + 1] = string[j];
				string[j] = c;
			}
		}
	}
	FILE *fp = fopen("out.txt", "a");
	fputs(string, fp);
	fclose(fp);
}

char* getstring(const char *f, int len)
{
	FILE *fin = fopen(f, "r");
	char *str = (char *)calloc(len + 1, sizeof(char));
	fgets(str, len + 1, fin);
	clearfile("out.txt");
	sort(str);
	free(str);
	fclose(fin);
	return str;
}

void clearfile(const char *f)
{
	FILE *fin = fopen(f, "w");
	fclose(fin);
}

void intotal()
{
	FILE *fin = fopen("out.txt", "r");
	char c = 'a', t = getc(fin);
	int kol;
	printf("\n\tRESULT:\n");
	while(c != EOF)
	{
		c = t;
		kol = 0;
		while(t == c)
		{
			t = getc(fin);
			if(t == EOF)
			{
				fseek(fin, -1, SEEK_END);
				t = getc(fin);
				printf("%c: %d\n", c, kol + 1);
				kol = -1;
				break;
			}
			kol++;
		}
		if(kol == -1)
			break;
		printf("%c: %d\n", c, kol);
	}
	fclose(fin);
}