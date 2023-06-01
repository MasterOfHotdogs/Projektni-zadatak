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
	printf("\n -----------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t Dobrodosli u kviz o video igrama");
	printf("\n -----------------------------------------------------------------------------------------------------");
	printf("\n\n\t>>Pravila igre <<");

	printf("\n\n\tOvaj kviz o video igrama je natjecateljska manifestaciju u kojem natjecatelj\
\n\todgovara na razna pitanja o video igrama. Kviz se sastoji od 15 pitanja za koja \
\n\tima ponudjeno 4 odgovora. Natjecatelj odgovara na pitanja do kraja kviza, dok na\
\n\tsvako tocno odgovoreno pitanje natjecatelj dobija bod. Cilj ovog kviza je testirati znanje\
\n\tnatjecatelja o video igrama, bile one stare ili nove.\n");

	printf("\n\n\t>> Opcija \"ODUSTANI\" <<");
	printf("\n\n\tNatjecatelj ukoliko odluci moze u bilo kojem trenutku prekunuti s igromm.\
\n\tpritiskom 'O' na tipkovnici, natjecatelj zavrsava svoju igru te mu se pripisuju bodovi steceni\
\n\tdo zadnjeg tocnog pitanja.");

	printf("\n\n -----------------------------------------------------------------------------------------------------");
	printf("\n");

	printf("\n\n\n\tPritisnite enter za povratak na pocetni zaslon!\n");
	system("pause");
	system("cls");
}

void start(void) {

	system("cls");

	HIGHSCORE igrac;
	int r1 = 1, count = 0, granica = 0, var, j;
	char znak;

	printf("\n\n\n\n\t\t\tUnesite svoje ime: ");
	scanf("%s", igrac.ime);
	//system("pause");
	system("cls");


	FILE* hp = NULL;
	hp = fopen("highscore.bin", "ab+");
	if (hp == NULL) {
		printf("\nDatoteka se ne moze otvoriti.\n");
		perror("Otvaranje");
	}

	poljePitanja = (PITANJE*)ucitavanjePitanja();
	if (poljePitanja == NULL) {
		perror("Zauzimanje memorije za sortirana pitanja");
		exit(EXIT_FAILURE);
	}

	PITANJE vraceno;
	char tocno;

	do {
		switch (r1) {
		case 1:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 1. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
			
				if (znak == tocno){

					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 2:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 2. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 3:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 3. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				 if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 4:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 4. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 5:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 5. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 6:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 6. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				
				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					granica = 1000;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					granica = 1000;
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 7:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 7. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				
				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 8:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 8. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				
				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					r1++;
					count++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 9:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 9. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 10:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 10. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 11:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 11. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					granica = 32000;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					granica = 32000;
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 12:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 12. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 13:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 13. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;


		case 14:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 14. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);;
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count++;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1++;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;

		case 15:
			printf("\n-------------------------------------------------------------");
			printf("\n\t\t\t 15. pitanje");
			printf("\n-------------------------------------------------------------");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();

				if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!\n\t\t");
					count++;
					r1 = 0;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					j = 0;
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;
		}
	} while (r1);

	igrac.highscore = (count);
	system("cls");
	printf("\n\tVase ime:%s i vas highscore: %d/15\n\t", igrac.ime, igrac.highscore);

	fprintf(hp, "%8d %s", igrac.highscore, igrac.ime);


	fclose(hp);
	//free(poljePitanja);
	//printf("\n\t");
	int uvijet;
	while ((uvijet = getchar()) != '\n' && uvijet != EOF) {}
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

	if (strcmp(username, "Mato") == 0) {
		if (strcmp(password, "gas") == 0) {
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
		perror("Ucitavanje pitanja iz datoteke pitanja.bin");
		return NULL;
	}

	fread(&brojPitanja, sizeof(int), 1, pF);

	PITANJE* poljePitanja = { NULL };
	poljePitanja = (PITANJE*)calloc(brojPitanja, sizeof(PITANJE));
	if (poljePitanja == NULL) {
		perror("Zauzimanje memorije za pitanja");
		return NULL;
	}

	fread(poljePitanja, sizeof(PITANJE), brojPitanja, pF);
	fclose(pF);
	return poljePitanja;
}


char ispisivanjePitanja(PITANJE odabrano) {


	int x;
	printf("\n\n\t%s", odabrano.pitanje);
	x = (float)rand() / RAND_MAX * 1000;

	char tocni;

	if (0 <= x && x < 250) {
		printf("\n\tA:%s\tB:%s\tC:%s\tD:%s", odabrano.odg2, odabrano.odg3, odabrano.odg1, odabrano.odg4);
		tocni = 'c';
	}
	if (250 <= x && x < 500) {
		printf("\n\tA:%s\tB:%s\tC:%s\tD:%s", odabrano.odg4, odabrano.odg1, odabrano.odg2, odabrano.odg3);
		tocni = 'b';
	}
	if (500 <= x && x < 750) {
		printf("\n\tA:%s\tB:%s\tC:%s\tD:%s", odabrano.odg3, odabrano.odg2, odabrano.odg4, odabrano.odg1);
		tocni = 'd';
	}
	if (750 <= x && x <= 1000) {
		printf("\n\tA:%s\tB:%s\tC:%s\tD:%s", odabrano.odg1, odabrano.odg4, odabrano.odg3, odabrano.odg2);
		tocni = 'a';
	}
	return tocni;
}




char pregledPitanja(void) {
	poljePitanja = (PITANJE*)ucitavanjePitanja();


	int tezina, i;
	printf("\n\tUnesiste tezinu pitanja koja zelite pretrazit: ");
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

void pretrazivanjeRang(void) {

		FILE* hp = NULL;
		hp = fopen("highscore.bin", "rb");
		if (hp == NULL) {
			printf("\nDatoteka se ne moze otvoriti.\n");
			perror("Otvaranje");
		}

		HIGHSCORE* hs;
		int highscore;
		char ime[20];
		int i = 0, brojac = 0;


		while ((fscanf(hp, "%d %s", &highscore, ime)) != EOF) {
			brojac++;
		}

		hs = (HIGHSCORE*)calloc(brojac, sizeof(HIGHSCORE));

		rewind(hp);

		while ((fscanf(hp, "%d %s", &(hs + i)->highscore, (hs + i)->ime)) != EOF) {
			i++;
		}


		char s[20];
		char* string = &s;
		int f = 0;


		printf("\n\tUnesite ime trazenog igraca: ");
		fgets(string, 19, stdin);
		provjeraStringa(string);

		for (i = 0; i < brojac; i++) {
			//printf("\n\tOvo je ime iz stirnga: %s, a ovo iz polja: %s", string, (hs + i)->ime);

			if (strcmp((hs + i)->ime, string) == 0) {
				printf("\n\tIgrac je pronaden!\n");
				printf("\n\tIme:%s\t\tHighscore:%d/15", (hs + i)->ime, (hs + i)->highscore);
				f = 1;
				//printf("\n\t");
				//system("pause");
				//system("cls");
			}

			else if (i == (brojac - 1) && f < 1) {
				printf("\n\tTakav igrac ne postoji");
				//printf("\n\t");
				//system("pause");
				//system("cls");

			}
		}
		/*printf("\n\tTakav igrac ne postoji");
		printf("\n\t");
		system("pause");
		system("cls");*/

		fclose(hp);
		printf("\n\t");
		system("pause");
		system("cls");

	}


void selectionSort(HIGHSCORE* hs, int n) {


	HIGHSCORE temp;

	int min = -1, i, j;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if ((hs + min)->highscore > (hs + j)->highscore) {
				min = j;
			}
		}

		temp = hs[min];
		hs[min] = hs[i];
		hs[i] = temp;
	}

	j = 1;
	//printf("\nOvo je n:%d", n);
	printf("\n-------------------------------------------------------------");
	if (n >= 10) {
		for (i = 0; i < 10; i++) {
			printf("\n\t%d. Ime: %s\t\tHighscore: %d/15", j, (hs + i)->ime, (hs + i)->highscore);
			printf("\n-------------------------------------------------------------");
			j++;
		}
	}
	else if (n < 10) {
		for (i = n - 1; i >= 0; i--) {
			printf("\n\t%d. Ime: %s\t\tHighscore: %d/15", j, (hs + i)->ime, (hs + i)->highscore);
			printf("\n-------------------------------------------------------------");
			j++;
		}
	}
}

void highscore(void) {


	FILE* hp = NULL;
	hp = fopen("highscore.bin", "rb");
	if (hp == NULL) {
		printf("\nDatoteka se ne moze otvoriti.\n");
		perror("Otvaranje");
	}


	HIGHSCORE* hs;
	int highscore;
	char ime[20];
	int i = 0, brojac = 0;


	while ((fscanf(hp, "%7d %s", &highscore, ime)) != EOF) {
		brojac++;
	}

	hs = (HIGHSCORE*)calloc(brojac, sizeof(HIGHSCORE));

	rewind(hp);

	while ((fscanf(hp, "%7d %s", &(hs + i)->highscore, (hs + i)->ime)) != EOF) {
		i++;
	}

	selectionSort(hs, brojac);

	fclose(hp);

	//printf("\nPritisnite enter za povratak na pocetni zaslon!\n");
	printf("\n\t");
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

	remove("pitanja.bin") == 0 ? printf("Izbrisali ste datoteku pitanja.bin.\n") : printf("Datoteka neuspjesno izbrisana ili ona ne postoji.\n");  //18: remove()
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

