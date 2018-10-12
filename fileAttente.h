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
// Entr�es : Rien
// Sorties : Rien
// Preconditions : La file ne doit pas etre initialis�e
// Postconditions : La file est initialis�e a NULL
// Retourne une file initialis�e
FileAttente initFileAttente();

// Cette procedure permet de desinitialiser une file d'attente
// Entr�es : pf : Pointeur FileAttente
// Sorties : Rien
// Pr�conditions : Rien
// Postconditions : La file est NULL
void desinitFileAttente(FileAttente* file);

// Cette proc�dure permet d'ajouter un entier en queue de file d'attente
// Entr�es : pf : Pointeur FileAttente, nom : tableau de Caracteres
// Sorties : pf : Rien
// Preconditions :
// Postconditions : La longueur de la file augmente de 1.
void ajouterEnQueue(FileAttente* pf, char nom[]);

// Cette proc�dure permet de retirer en tete de file d'attente
// Entr�es : pf : Pointeur FileAttente
// Sorties : Rien
// Preconditions : La file ne doit pas etre vide
// Postconditions : La longueur de la file diminue de 1.
void retirerEnTete(FileAttente* pf);

// Cette fonction permet de calculer la longueur de la file d'attente
// Entr�es : file : FileAttente
// Sorties : Rien
// Pr�conditions : La file doit exister
// Postconditions :
// Retourne la longueur de la file
int longueurFile(FileAttente file);

// Cette proc�dure permet d'afficher la valeur en tete de file d'attente
// Entr�es : file : FileAttente
// Sorties : Rien
// Pr�conditions : la file ne doit pas etre vide
// Postconditions : Rien
void afficherTeteDeFile(FileAttente file);

// Cette procedure permet de faire l'affichage d'un menu
// Entr�es : Rien
// sorties : Rien
// Pr�conditions : Rien
// Postconditions : Rien
void afficheMenu();

#endif