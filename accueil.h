#ifndef ACCUEIL_H
#define ACCUEIL_H
/* Des commentaires plus précis sont disponibles dans accueil.c */

int accueil(void); 
/* Squelette de l'organisation de la page d'accueil, cette fonction renvoie la valeur qui correspond au choix de la difficulté :
(en réalité, la difficulté est le nombre de colonnes de cartes, puisque pour simplifier, le nombre de ligne est fixe et vaut 5)
> Facile : renvoie 6 car 6*5 = 30 cartes -> 15 paires 
> Normal :  renvoie 8 car 8*5 = 40 cartes -> 20 paires
> Difficile : renvoie 10 car 10*5 = 50 cartes -> 25 paires
> Renvoie -1 si le joueur à séléctionné "Quitter"
Cette fonction détecte aussi les clics de souris sur les boutons d'action "Jouer", "Règles" et "Quitter" */

void afficher_accueil(void);
/* Affiche le menu d'accueil lors du lancement du programme */

void regles(void);
/* Affiche les règles du jeu lorsqu'un clic est détecté sur le bouton "Règles" */

void afficher_diffculte(void);
/* Affiche le choix des difficultés possibles ("Facile", "Normal", "Difficile") lorsqu'un clic est détecté sur le bouton "Jouer" */

#endif