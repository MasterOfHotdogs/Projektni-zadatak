#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"



//10: upotreba funkcija 
void pomoc(void) {

	system("cls");
	printf("\n ********************************* Dobrodosli u kviz o video igrama **********************************");
	printf("\n *****************************************************************************************************");
	printf("\n\n\t>>Pravila igre <<");

	printf("\n\n\tOvaj kviz o video igrama je natjecateljska manifestaciju u kojem natjecatelj\
\n\todgovara na razna pitanja o video igrama. Kviz se sastoji od 15 pitanja za koja \
\n\tima ponudjeno 4 odgovora. Natjecatelj odgovara na pitanja do kraja kviza, dok na\
\n\tsvako tocno odgovoreno pitanje natjecatelj dobija bod. Cilj ovog kviza je testirati znanje\
\n\tnatjecatelja o video igrama, bile one stare ili nove.\n");

	printf("\n\n\t>> Opcija \"ODUSTANI\" <<");
	printf("\n\n\tNNatjecatelj ukoliko odluci moze u bilo kojem trenutku prekunuti s igromm.\
\n\tpritiskom 'O' na tipkovnici, natjecatelj zavrsava svoju igru te mu se pripisuju bodovi steceni\
\n\tdo zadnjeg tocnog pitanja.");

	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}


void start(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");

}



void* dodavanjePitanja(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
	
}


void admnistrator(void) {
	system("cls");
	char username[15];
	char password[12];


	printf("Unesite korisnicko ime: ");
	scanf("%s", &username);

	printf("Unesite zaporku: ");
	scanf("%s", &password);

	if (strcmp(username, "Ronaldo") == 0) {
		if (strcmp(password, "SIU") == 0) {
			printf("Uspjesno ste se ulogirali");
			system("cls");
		}
		else {
			printf("\nPogeresna lozinka");
		}
	}
	else {
		printf("\nNepostojano korisnicko ime");
	}

	printf("\nPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");

}


char izlaz(void) {
	char unos[3];

	printf("Jeste li sigurni da zelite izaci iz programa?\n Upisite 'DA' za potvrdite izlazak: ");
	scanf("%s", unos);


	for (int i = 0; i < strlen(unos); i++) {
		unos[i] = toupper(unos[i]);
	}

	if (strcmp(unos, "DA") == 0) {
		printf("Izlazak iz programa...\n");
		exit(0);
	}
}

char pregledPitanja(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}

char pretrazivanjeRang(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}

void pregledRangLjestvice(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}