#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

//8: koristenje izbornika
char izbornik(void) {

	printf("\n\t\t_____________________________________________________________\n");

	printf("\n\t\t\t          D O B R O D O S L I\n ");
	printf("\n\t\t\t                    U\n ");
	printf("\n\t\t\t                 K V I Z\n ");
	printf("\n\t\t\t        O  V I D E O  I G R A M A");
	printf("\n\t\t");
	printf("\n\t\t*************************************************************");
	printf("\n\t\t  JESI LI ZAISTA GAMER? TESTIRAJ SVOJE ZNANJE U OVOM KVIZU!");
	printf("\n\t\t*************************************************************");
	printf("\n\t\t > Opcija 1: Zapocni igru");
	printf("\n\t\t > Opcija 2: Pogledaj rang ljestvicu");
	printf("\n\t\t > Opcija 3: Pretrazi igrace na rang ljestvici");
	printf("\n\t\t > Opcija 4: Dodaj pitanja");
	printf("\n\t\t > Opcija 5: Pregled pitanja");
	printf("\n\t\t > Opcija 6: Pomoc");
	printf("\n\t\t > Opcija 7: Izlaz iz programa");
	printf("\n\t\t_____________________________________________________________\n\n");


	char odabir;
	printf("\tOdaberite jednu od opcija: ");
	scanf("%c", &odabir);

	getchar();

	switch (odabir) {
	case '1':
		start();
		break;
	case '2':
		pregledRangLjestvice();
		break;
	case '3':
		pretrazivanjeRang();
		break;
	case '4':
		admnistrator();
		dodavanjePitanja();
		break;
	case '5':
		pregledPitanja();
		break;
	case '6':
		pomoc();
		break;
	case '7':
		izlaz();
		break;
	default:
		printf("\n\t\tKrivi odabir! Unesite neku od ponudjenih opcija\n");
		while ((odabir = getchar()) != '\n' && odabir != EOF) {}
		printf("\n\t\t");
		system("pause");
		system("cls");
		break;
	}
	return odabir;
}