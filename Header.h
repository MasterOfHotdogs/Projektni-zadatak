#ifndef HEADER_H
#define HEADER_H


//3: primjena typedef
//10: upotreba struktura i funkcija

typedef struct pitanje {
	int tezina;
	char pitanje[200];
	char odg1[50];
	char odg2[50];
	char odg3[50];
	char odg4[50];
}PITANJE;

typedef struct highscore {
	char ime[20];
	long int highscore;
}HIGHSCORE;

//4: upotreba camelCase kroz cijeli projekt

char izbornik(void);
void start(void);
void* dodavanjePitanja(void);
void pomoc(void);
char izlaz(void);
char pregledPitanja(void);
void pretrazivanjeRang(void);
void highscore(void);
void admnistrator(void);
void kreiranjeDatoteke(void);
void provjeraStringa(char*);
void* ucitavanjePitanja(void);
void brisanjePitanja(void);
PITANJE sortiranjePolja(PITANJE*, int);
void selectionSort(HIGHSCORE*, int);
char ispisivanjePitanja(PITANJE);

#endif 
