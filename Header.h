#ifndef HEADER_H
#define HEADER_H


//3: primjena typedef

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

char izbornik(void);
void start(void);
void* dodavanjePitanja(void);
void pomoc(void);
char izlaz(void);
char pregledPitanja(void);
char pretrazivanjeRang(void);
void pregledRangLjestvice(void);
void admnistrator(void); 
//void kreiranje(void);

#endif 