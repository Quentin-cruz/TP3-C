//Definir une structure de donnees Heure permettant de representer une heure au format hh / mm / ss, puis ecrire les fonctions suivantes :
//Ecrire une fonction de conversion d'un element de type Heure en un nombre de secondes (entier)
//Ecrire une fonction de conversion d'un nombre de secondes (entier) en un element de type Heure
//Ecrire une fonction qui retourne un temps correspondant à l’addition de deux elements de type Heure
//Creer un programme permettant de saisir un temps en H / M / S puis convertir ce temps en nombre de secondes.Ensuite saisir 
//un nombre de secondes et le convertir en temps au format H / M / S.Puis ajoutez les deux temps precedemment saisis et affichez le resultat.

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int hh, mm, ss;
}Heure;

int conversionHorairetoS(Heure* h) {

	h->ss += h->hh * 3600 + h->mm * 60;
	h->hh = 0;
	h->mm = 0;
	return h->ss;

}


Heure conversionStoHoraire(int totalSecondes) {
	Heure htemp;
	int t = totalSecondes;
	int reste = t % 3600;
	htemp.hh = t / 3600;
	htemp.mm = reste / 60;
	htemp.ss = reste % 60;
	return htemp;
}

Heure additionH(Heure* h, Heure* h2) {
	conversionHorairetoS(h);
	conversionHorairetoS(h2);
	h->ss += h2->ss;
	*h = conversionStoHoraire(h->ss);
	return *h;

}

int main()
{
	Heure* h;
	h = (Heure*)malloc(sizeof(Heure));
	h->hh = 0;
	h->mm = 0;
	h->ss = 0;
	Heure* h2;
	h2 = (Heure*)malloc(sizeof(Heure));
	h2->hh = 0;
	h2->mm = 0;
	h2->ss = 0;
	printf("Saisir les heures : ");
	scanf("%d", &h->hh);
	printf("\nSaisir les minutes : ");
	scanf("%d", &h->mm);
	printf("\nSaisir les secondes : ");
	scanf("%d", &h->ss);
	conversionHorairetoS(h);
	printf("\nHoraires converti en second : %d", h->ss);
	printf("\nSaisir un nombre de secondes : ");
	scanf("%d", &h2->ss);
	*h2 = conversionStoHoraire(h2->ss);
	printf("\nSecondes converties en horaire : %d:%d:%d", h2->hh, h2->mm, h2->ss);
	additionH(h, h2);
	printf("\nValeur totale des horaires additionnees : %d:%d:%d", h->hh, h->mm, h->ss);
	free(h);
	free(h2);
	return 0;
}
