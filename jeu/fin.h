#ifndef FIN_H
#define FIN_H
/* Des commentaires plus précis sont disponibles dans fin.c */

void  final(unsigned long score, int difficulte);
/* Squelette du menu de victoire, cette fonction détecte aussi un cilc souris sur le bouton "Quitter" */

void page_finale(unsigned long score, int niveau);
/* Affiche le style de la page finale */

void niveau_bronze(unsigned long jscore);
/* Cette fonction annonce "niveau bronze" si le joueur a joué en facile, affiche le score du joueur, ainsi que le meilleur score jamais réalisé en mode facile */

void niveau_platine(unsigned long jscore);
/* Cette fonction annonce "niveau platinum" si le joueur a joué en normal, affiche le score du joueur, ainsi que le meilleur score jamais réalisé en mode normal */

void niveau_master(unsigned long jscore);
/* Cette fonction annonce "niveau master" si le joueur a joué en difficile, affiche le score du joueur, ainsi que le meilleur score jamais réalisé en mode difficle */

#endif