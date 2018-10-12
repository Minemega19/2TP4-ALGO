#include <iostream>
#include "fileAttente.h"
#include "pile.h"
using namespace std;


void empiler(FileAttente file, Pile* pp) { //FileAttente* file == FileAttente *file == pointeur
	FileAttente filetemp;
	if (file.tete != NULL) {
		filetemp = file;
		(*pp).pile->file = filetemp;
	}
	else {
		cout << " Impossible de faire la sauvegarde d'une file existante " << endl;
	}
}

void depiler(FileAttente* file, Pile* pile) {
	
	if ((*pile).pile != NULL) {
		 
	}
}

FileAttente initFileAttente() {
	FileAttente file;
	file.tete = NULL;
	file.queue = NULL;
	return file;
}

void retirerEnTete(FileAttente* pf) { // *pf == contenu
	maillon* p;
	if ((*pf).tete != NULL) { 
		p = (*pf).tete;
		(*pf).tete = (*(*pf).tete).suivant;
		delete(p);
	}
}

void desinitFileAttente(FileAttente* file) {
	while ((*file->tete).suivant != NULL) {
		retirerEnTete(file);
	}
	free(file->tete);
	file->tete = NULL;
	file->queue = NULL;
}

void ajouterEnQueue(FileAttente* pf, char nom[]) {

	maillon* p;
	p = new maillon;

	if ((*pf).tete != NULL) {
		p = (*pf).queue;
		(*p).suivant = new maillon;
		p = (*p).suivant;
		for (int i = 0; i < TAILLE; i++) {
			(*p).nom[i] = nom[i];
		}
		(*p).suivant = NULL;
		(*pf).queue = p;
	}
	else {
		for (int i = 0; i < TAILLE; i++) {
			(*p).nom[i] = nom[i];
		}
		(*p).suivant = NULL;
		(*pf).tete = p;
		(*pf).queue = p;
	}
}


void afficherTeteDeFile(FileAttente file) {
	if (file.tete != NULL) {
		cout << "Voici la valeur en tete de file : " << (*file.tete).nom << endl;
	}
	else {
		cout << "Il n'y a pas de file d'attente !" << endl;
	}
}

int longueurFile(FileAttente file) {
	int i = 0;
	maillon* temp;
	if (file.tete != NULL) {
		temp = file.tete;
		i++;
		while ((*temp).suivant != NULL) {
			i++;
			temp = (*temp).suivant;
		}
	}

	return i;
}

void afficheMenu() {
	cout << " Veuillez choisir l'une des manieres de calcul proposees : " << endl;
	cout << " 1 - Ajouter une personne en queue " << endl;
	cout << " 2 - Retirer la personne en tete " << endl;
	cout << " 3 - Consulter la personne en tete de file " << endl;
	cout << " 4 - Calculer la longueur de la file d'attente " << endl;
	cout << " 5 - Undo ";
	cout << " 6 - Quitter " << endl;
}

int main() {
	int choix;
	char a[TAILLE];
	FileAttente file;
	file = initFileAttente();
	FileAttente* pf;
	pf = &file;

	do {
		afficheMenu();
		cin >> choix;

		switch (choix) {
		case 1:
			cout << " Ajouter une personne en queue : ";
			cin >> a;
			ajouterEnQueue(pf, a);
			break;

		case 2:
			cout << " Suppression de la personne en tete " << endl;
			retirerEnTete(pf);
			break;

		case 3:
			cout << " Consultation de la personne en tete de file" << endl;
			afficherTeteDeFile(file);
			break;

		case 4:
			cout << " Calcul de la longueur de la file d'attente " << endl;
			cout << longueurFile(file) << endl;
			break;

		case 5:
			cout << " Reviens en arrière ... " << endl;
			break;

		case 6:
			cout << " Fin du programme ... " << endl;
			desinitFileAttente(pf);
			break;

		default:
			cout << " La valeur saisie n'est pas bonne. Aucun calcul ne sera fait. " << endl;
		}
	} while (choix != 5);
}