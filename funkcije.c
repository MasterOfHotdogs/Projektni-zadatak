#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"

//5: static za globalne i lokalne varijable

static int brojPitanja = 0;
static PITANJE* poljePitanja = NULL;
static int counter = 0;

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

void kreiranjeDatoteke(void) {

	FILE* fp = NULL;
	fp = fopen("pitanja.bin", "rb");
	if (fp == NULL) {

		fp = fopen("pitanja.bin", "wb");
		if (fp == NULL) {
			perror("Kreiranje datoteke pitanja.bin");   //19: perror();
			exit(EXIT_FAILURE);
		}
		fwrite(&brojPitanja, sizeof(int), 1, fp);
		fclose(fp);
	}
	else {
		fwrite(&brojPitanja, sizeof(int), 1, fp);
		fclose(fp);
	}

}


void start(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");

}



//16: datoteke
void* dodavanjePitanja(void) {

	kreiranjeDatoteke();
	FILE* pF = fopen("pitanja.bin", "rb+");
	if (pF == NULL) {
		perror("Dodavanje studenta u datoteke pitanja.bin");
		exit(EXIT_FAILURE);
	}
	fread(&brojPitanja, sizeof(int), 1, pF);
	printf("Ukupan broj pitanja: %d\n", brojPitanja);

	PITANJE temp = { 0 };
	int t, c;

	printf("\nUnesite tezinu pitanja od 1 do 15: ");
	do {
		scanf("%d", &t);
		if (1 > t || t > 15) {
			printf("\nUnjeli ste nedozvoljen broj! Uneiste neki od brojeva u trazenom intervalu: ");
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	} while (!(1 <= t && t <= 15));
	temp.tezina = t;
	getchar();

	printf("Unesite pitanje!\n");
	fgets(temp.pitanje, 199, stdin);

	printf("Unesite odgovor!\n");
	fgets(temp.odg1, 49, stdin);

	printf("Unesite odgovor!\n");
	fgets(temp.odg2, 49, stdin);

	printf("Unesite odgovor!\n");
	fgets(temp.odg3, 49, stdin);

	printf("Unesite odgovor!\n");
	fgets(temp.odg4, 49, stdin);

	fseek(pF, sizeof(PITANJE) * brojPitanja, SEEK_CUR);
	fwrite(&temp, sizeof(PITANJE), 1, pF);

	//17: rewind();

	rewind(pF);   
	brojPitanja++;
	fwrite(&brojPitanja, sizeof(int), 1, pF);
	fclose(pF);
	printf("\n\t");
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
			
			int g = 0; 
			printf("Koliko pitanja zelite dodati?\n");
			scanf("%d", &g);

			for (int i = 0; i < g; i++) {
				dodavanjePitanja();
			}
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

	printf("Jeste li sigurni da zelite zatvoriti program?\n");
	printf("Utipkajte 'da' ako zelite zatvoriti program\n");
	char potvrda[3] = { '\0' };      //12: staticki zauzeto polje
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		return NULL;
	}

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	system("pause");
	system("cls");
	return '1';
}

void* ucitavanjePitanja(void) {
	FILE* pF = fopen("pitanja.bin", "rb");
	if (pF == NULL) {
		perror("Ucitavanje pitanja iz datoteke pitanja.bin nije uspjelo");
		return NULL;
	}

	fread(&brojPitanja, sizeof(int), 1, pF);

	PITANJE* poljePitanja = { NULL };
	poljePitanja = (PITANJE*)calloc(brojPitanja, sizeof(PITANJE));    //14: calloc();
	if (poljePitanja == NULL) {
		perror("Zauzimanje memorije za pitanja");
		return NULL;
	}

	fread(poljePitanja, sizeof(PITANJE), brojPitanja, pF);
	fclose(pF);
	return poljePitanja;
}

char pregledPitanja(void) {
	poljePitanja = (PITANJE*)ucitavanjePitanja();


	int tezina, i;
	printf("\n\tUneiste tezinu pitanja koja zelite pretrazit: ");
	do {
		scanf("%d", &tezina);
		if (tezina < 0 || tezina > 15) {
			printf("\n\tUnjeli ste pogresnu tezinu pitanja! Unesite neku od dozvoljenih vrijednost: ");
		}
	} while (!(0 < tezina && tezina < 16));

	PITANJE* sortirano = NULL;

	counter = 0;
	for (i = 0; i < brojPitanja; i++) {
		if ((poljePitanja + i)->tezina == tezina) {
			counter++;
		}
	}
	printf("\nBroj pitanja za ovu razinu: %d\n", counter);
	sortirano = (PITANJE*)calloc(counter, sizeof(PITANJE));
	if (sortirano == NULL) {
		perror("Zauzimanje memorije za sortirana pitanja");
		exit(EXIT_FAILURE);
	}

	int j = 0;
	for (i = 0; i < brojPitanja; i++) {
		if ((poljePitanja + i)->tezina == tezina) {
			sortirano[j] = poljePitanja[i];
			printf("\n\t%s", (sortirano + j)->pitanje);
			printf("\n\tA:%s\tB:%s\tC:%s\tD:%s", (sortirano + j)->odg1, (sortirano + j)->odg2, (sortirano + j)->odg3, (sortirano + j)->odg4);
			j++;
		}
	}
	system("pause");
	system("cls");
	int uvijet;
	while ((uvijet = getchar()) != '\n' && uvijet != EOF) {}
}

char pretrazivanjeRang(void) {
	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}

void selectionSort(HIGHSCORE* hs, int n) {


	HIGHSCORE temp;

	int min = -1, i, j;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if ((hs + j)->highscore > (hs + min)->highscore) {
				min = j;
			}
		}

		temp = hs[min];
		hs[min] = hs[i];
		hs[i] = temp;
	}

	j = 1;
	//printf("\nOvo je n:%d", n);
	if (n >= 10) {
		for (i = 0; i < 10; i++) {
			printf("\n\t%d. Ime: %s\t\tHighscore: %d", j, (hs + i)->ime, (hs + i)->highscore);
			j++;
		}
	}
	else if (n < 10) {
		for (i = n - 1; i >= 0; i--) {
			printf("\n\t%d. Ime: %s\t\tHighscore: %d", j, (hs + i)->ime, (hs + i)->highscore);
			j++;
		}
	}
}

void highscore(void) {

	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}

void provjeraStringa(char* polje) {
	int n = strlen(polje);
	if (polje[n - 1] == '\n') {
		polje[n - 1] = '\0';
	}
}

void brisanjePitanja(void) {

	remove("pitanja.bin") == 0 ? printf("Izbrisali ste datoteku pitanja.bin.\n") : printf("Datoteka neuspjesno izbrisani ili ona ne postoji.\n");  //18: remove()
	system("pause");
	system("cls");
}


//9: pokazivaci
PITANJE sortiranjePolja(PITANJE* poljePitanja, int tezina) {

	PITANJE* sortirano = NULL;
	int i;
	counter = 0;
	for (i = 0; i < brojPitanja; i++) {
		if ((poljePitanja + i)->tezina == tezina) {
			counter++;
		}
	}
	//printf("\nBroj pitanja za ovu razinu %d", counter);
	sortirano = (PITANJE*)calloc(counter, sizeof(PITANJE));
	if (sortirano == NULL) {
		perror("Zauzimanje memorije za sortirana pitanja");
		exit(EXIT_FAILURE);
	}

	int j = 0;
	for (i = 0; i < brojPitanja; i++) {
		if ((poljePitanja + i)->tezina == tezina) {
			sortirano[j] = poljePitanja[i];
			j++;
		}
	}

	int p[3], y;
	PITANJE odabrano;

	srand((unsigned)time(NULL));

	for (i = 0; i < 3; i++) {
		p[i] = (float)rand() / RAND_MAX * counter;
		//("\n%d", p[i]);
	}
	y = p[2];
	odabrano = sortirano[y];
	//printf("\ny je jednako: %d a conter je jednak %d", y, counter);

	return odabrano;
}

