#ifndef GAME_H
#define GAME_H
/* Des commentaires plus précis sont disponibles dans game.c */

unsigned long game(int taille, unsigned long fauxchrono);
/* Squelette qui structure la partie jeu du projet. La fonction renvoie le score du joueur, c'est-à-dire, le temps qu'il a mis pour gagner.
Elle détecte aussi l'appuie sur la touche T popur le mode triche ainsi que les clics souris sur les cartes */

void remplir_tableaux(int* tab, int* tab2, int* tab3, int size);
/* Cette fonction a pour simple but de remplir tous les tableaux avec uniquement des zeros. 
L'utilité est de simplement connaître la valeur exacte de chaques cases des tableaux pour éviter tous types de bugs liés aux valeur dans les tableaux */

int carte_random(int Max);
/* Carte_random renvoie une valeur aléatoire entre 0 et le nombre de cartes totales */

void cartes_aleatoires(int* typec, int size);
/* Cette fonction a pour but mélanger aléatoirement les cartes du plateau */

int marge(int size);
/* Cette fonction renvoie un nombre de pixels qui permet de placer la première colonne dans la fenêtre en fonction du nombre de cartes du plateau, lié au niveau de difficulté */

void afficher_verso(int* facec, int* type, int size, int pos_x);
/* Affiche les cartes face cachée si type = 0 */

void afficher_recto(int* type, int a, int x_pos, int y_pos);
/* Affiche les cartes face découverte si, dans la fonction afficher_verso, type = 1. L'icone de la face découverte dépend de la valeur aléatoire conférée à la carte */

int clic_carte(int* facec, int* nb_retournee, int* cTrouvee, int souris_x, int souris_y, int pos_x, int size, int compte);
/* Clic_carte cherche entre quelles cordonnées un clic souris à été détécté. Si des cordonnées correspondent à celles d'une carte et que cette carte est bien face cachée, ele est retournée.
Elle renvoie le nombre de clics sur des cartes ont été fait et enregistre quelles cartes ont été retournées */

unsigned long triche(int* typec, int size, int x);
/* Affiche la face découverte de toutes les cartes et stoppe le chronomètre si la touche T est pressé. Si T est de nouveau pressé, la fonction est quittée */

int paires(int* nb_retournee, int* typec, int* cTrouvees);
/* Si 2 clics souris sur des cartes ont été fait, cette fonction regarde si les cartes sont les mêmes, dans ce cas elle renvoie 1, sinon, elle renvoie 0 */

int victoire(int* cTrouvee, int size);
/* Cette fonction vérifie si une carte est face cachée, si c'est le cas, la fonction renvoie 0, si toutes les cartes sont face découverte, elle renvoie 1 et le joueur a gagné */

unsigned long timer(unsigned long chronoV, unsigned long chronoF, unsigned long timeTriche, int* incrementation, unsigned long* cRes2);
/* Calcule le temps écoulé depuis le lancement de la partie et l'affiche */

void cartes_differentes(unsigned long temps1, unsigned long temps2, int* nb_retournee, int* facec);
/* Si les 2 cartes retournées ne sont pas identiques, cette fonction est appelée et les cartes sont remises face cachée après une seconde */

#endif