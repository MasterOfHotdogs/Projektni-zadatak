#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Header.h"

//6: organizacija izvornog koda

int main(void) {
	char odabir = '1';


	while (odabir) {
		odabir = izbornik();
	}
	printf("\t\t  Hvala na sudjelovanju!\n");

	return 0;
}
