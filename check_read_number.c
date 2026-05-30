#include <stdio.h>
#include <stdbool.h>
#include "check_read_number.h"

bool check_read_number(double* number)
{
	if (scanf_s("%lf", number) != 1) {
		printf("Blad: To nie jest poprawna liczba.\n");
		while (getchar() != '\n');
		return false;
	}
	return true;
}