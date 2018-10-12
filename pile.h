#ifndef PILE_H
#define PILE_H

typedef struct maillonPile{
	FileAttente file;
	struct maillonPile* suivant;
}maillonPile;

typedef struct Pile {
	struct maillonPile* pile;
}Pile;

/*



*/

void empiler();

/*



*/

void depiler();

#endif
