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
Cette procédure permet de sauvegarder une instance de file d'attente dans la pile
Entrées :  file de type FileAttente et Pointeur pile
Préconditions : La file doit exister et la pile doit exister et etre initialisées
Postconditions : La pile comporte un maillon
*/

void empiler(FileAttente* file, Pile* pile);

/*



*/

void depiler();

void initPile();

void desinitPile();

#endif