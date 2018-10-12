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
Cette proc�dure permet de sauvegarder une instance de file d'attente dans la pile
Entr�es :  file de type FileAttente et Pointeur pile
Pr�conditions : La file doit exister et la pile doit exister et etre initialis�es
Postconditions : La pile comporte un maillon
*/

void empiler(FileAttente* file, Pile* pile);

/*



*/

void depiler();

void initPile();

void desinitPile();

#endif