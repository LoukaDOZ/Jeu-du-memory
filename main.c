#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "accueil.h"
#include "game.h"
#include "fin.h"
/* Commentaires à droite du code. D'autres commentaires trouvables dans acceuil.h, game.h et fin.h */

int main(void){
	while(1){
		int difficulte;									/* Variable qui récupère la valeur de la difficulté choisie ( voir les commentaires d'acceuil.h ) */
		unsigned long timeFinal;						/* Variable qui récupère le temps que le joueur à mit pour finir */

		srand(time(NULL));
		
		InitialiserGraphique();							/* Initialisation de la fenêtre d'accueil */
		CreerFenetre(0,0,1270,714);						/* Initialisation de la fenêtre d'accueil */
		ChoisirTitreFenetre("Memowatch");				/* Initialisation de la fenêtre d'accueil */

		difficulte=accueil();							/* Appel de la fonction qui gérera le menu d'accueil */

		if(difficulte==-1){								/* Si le joueur a cliqué sur "Quitter", acceuil renvoie -1, ici on verifie si c'st le cas */

			return EXIT_SUCCESS;						/* Si c'est le cas, on quitte le programme */

		}

		unsigned long chronoFixe = Microsecondes();		/* Constante qui servira au chronomètre */

		//timeFinal = game(difficulte, chronoFixe);		/* Appel de la fonction gérera la partie jeu */
timeFinal = 100;
		if(timeFinal!=0){								/* Si le joueur a cliqué sur "Quitter", acceuil renvoie -1, ici on verifie si c'st le cas */
		
			final(timeFinal, difficulte);					/* Appel de la fonction gérera la fin lorsque le joueur à gagné */
		}
}

}