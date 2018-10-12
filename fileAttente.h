#ifndef FILEATTENTE_H
#define FILEATTENTE_H

//Definition des structures du maillon
const int TAILLE = 10;

typedef struct maillon {
	char nom[TAILLE];
	struct maillon* suivant;
} maillon;

//Definition de la structure de la file d'attente

typedef struct FileAttente {
	maillon* tete;
	maillon* queue;
} FileAttente;

// Cette fonction permet d'initialiser une file d'attente
// Entrées : Rien
// Sorties : Rien
// Preconditions : La file ne doit pas etre initialisée
// Postconditions : La file est initialisée a NULL
// Retourne une file initialisée
FileAttente initFileAttente();

// Cette procedure permet de desinitialiser une file d'attente
// Entrées : pf : Pointeur FileAttente
// Sorties : Rien
// Préconditions : Rien
// Postconditions : La file est NULL
void desinitFileAttente(FileAttente* file);

// Cette procédure permet d'ajouter un entier en queue de file d'attente
// Entrées : pf : Pointeur FileAttente, nom : tableau de Caracteres
// Sorties : pf : Rien
// Preconditions :
// Postconditions : La longueur de la file augmente de 1.
void ajouterEnQueue(FileAttente* pf, char nom[]);

// Cette procédure permet de retirer en tete de file d'attente
// Entrées : pf : Pointeur FileAttente
// Sorties : Rien
// Preconditions : La file ne doit pas etre vide
// Postconditions : La longueur de la file diminue de 1.
void retirerEnTete(FileAttente* pf);

// Cette fonction permet de calculer la longueur de la file d'attente
// Entrées : file : FileAttente
// Sorties : Rien
// Préconditions : La file doit exister
// Postconditions :
// Retourne la longueur de la file
int longueurFile(FileAttente file);

// Cette procédure permet d'afficher la valeur en tete de file d'attente
// Entrées : file : FileAttente
// Sorties : Rien
// Préconditions : la file ne doit pas etre vide
// Postconditions : Rien
void afficherTeteDeFile(FileAttente file);

// Cette procedure permet de faire l'affichage d'un menu
// Entrées : Rien
// sorties : Rien
// Préconditions : Rien
// Postconditions : Rien
void afficheMenu();

#endif