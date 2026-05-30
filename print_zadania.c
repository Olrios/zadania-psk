/*

#include <cstdio>
#include <stdio.h>
#include "print_zadania.h"
#include <math.h>

int print_zadania()
{
	printf(1);


	char ch, file_name[25];
	FILE* fp;
	fp = fopen("Tekst.txt", "r");
	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		return 0;
	}
	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);
	fclose(fp);
	return 0;
}


*/