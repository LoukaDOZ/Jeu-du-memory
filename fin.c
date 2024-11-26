#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "fin.h"
/* Commentaires à droite du code. D'autres commentaires sont aussi disponibles dans fin.h */

void niveau_bronze(unsigned long jscore){												/* Fonction qui gère tous les affichages correspondant au niveau bronze et reçoie en argument le score du joueur */
	FILE* best_score;																	/* Variable qui reçoie le fichier à ouvrir pour connaître le meilleur score */
	unsigned long bscore;																/* Variable qui récupère la valeur du meilleur score */
	char strscore[100];																	/* Tableau qui recevra le meilleur temps en caractères */

	ChoisirCouleurDessin(CouleurParComposante(102,51,0));								/* Affichage du texte "Niveau bronze" */
	EcrireTexte(575, 290, "Niveau bronze", 1);											/* Affichage du texte "Niveau bronze" */

	best_score=fopen("bestbronze","r");													/* Ouverture du fichier bestbronze en lecture seule */

	if(best_score != NULL) {
		fread(&bscore, sizeof (unsigned long), 1, best_score);							/* Lecture de la valeur du meilleur score en unsigned long enregistrement dans bscore */
		sprintf(strscore, "Meilleur score en bronze : %04lu s", bscore);				/* Conversion du meilleur temps en "char" et enregistrement de celui-çi dans strscore */
		fclose(best_score);																/* Fermeture du fichier bestbronze */
	} else
		sprintf(strscore, "Meilleur score en bronze : Aucun");

	ChoisirCouleurDessin(CouleurParComposante(255,51,51));								/* Affichage du meilleur temps */
	EcrireTexte(260, 370, strscore, 2);													/* Affichage du meilleur temps */

	if(best_score == NULL || jscore < bscore){											/* On regarde si le score du joueur ( jscore ) est meilleur ( plus petit ) que le  précédent meilleur score */
		
		ChoisirCouleurDessin(CouleurParComposante(0,0,0));								/* Affichage du message "Nouveau meilleur score" */
		EcrireTexte(550, 447, "Nouveau meilleur score!", 1);							/* Affichage du message "Nouveau meilleur score" */

		best_score=fopen("bestbronze","w");												/* Ouverture du fichier bestbronze en écriture seule */

		fwrite(&jscore, sizeof (unsigned long), 1, best_score);							/* réécriture du meilleur score par celui du joueur pour les prochaines parties */

		fclose(best_score);																/* Fermeture du fichier bestbronze */
	}
}



void niveau_platine(unsigned long jscore){												/* Fonction qui gère tous les affichages correspondant au niveau platine */
	FILE* best_score;																	/* Variable qui reçoie le fichier à ouvrir pour connaître le meilleur score */
	unsigned long bscore;																/* Variable qui récupère la valeur du meilleur score */
	char strscore[100];																	/* Tableau qui recevra le meilleur temps en caractères */

	ChoisirCouleurDessin(CouleurParComposante(160,160,160));							/* Affichage du texte "Niveau platinum" */
	EcrireTexte(565, 290, "Niveau platinum", 1);										/* Affichage du texte "Niveau platinum" */

	best_score=fopen("bestplatinum","r");												/* Ouverture du fichier bestplatinum en lecture seule */

	if(best_score != NULL) {
		fread(&bscore, sizeof (unsigned long), 1, best_score);							/* Lecture de la valeur du meilleur score en unsigned long enregistrement dans bscore */
		sprintf(strscore, "Meilleur score en platinum : %04lu s", bscore);				/* Conversion du meilleur temps en "char" et enregistrement de celui-çi dans strscore */
		fclose(best_score);																/* Fermeture du fichier bestplatinum */
	} else
		sprintf(strscore, "Meilleur score en platinum : Aucun");

	ChoisirCouleurDessin(CouleurParComposante(255,51,51));								/* Affichage du meilleur temps */
	EcrireTexte(260, 370, strscore, 2);													/* Affichage du meilleur temps */

	if(best_score == NULL || jscore < bscore){											/* On regarde si le score du joueur ( jscore ) est meilleur ( plus petit ) que le  précédent meilleur score */
		ChoisirCouleurDessin(CouleurParComposante(0,0,0));								/* Affichage du message "Nouveau meilleur score" */
		EcrireTexte(550, 447, "Nouveau meilleur score!", 1);							/* Affichage du message "Nouveau meilleur score" */

		best_score=fopen("bestplatinum","w");											/* Ouverture du fichier bestplatinum en écriture seule */

		fwrite(&jscore, sizeof (unsigned long), 1, best_score);							/* réécriture du meilleur score par celui du joueur pour les prochaines parties */

		fclose(best_score);																/* Fermeture du fichier bestplatinum */
	}
}



void niveau_master(unsigned long jscore){												/* Fonction qui gère tous les affichages correspondant au niveau master */
	FILE* best_score;																	/* Variable qui reçoie le fichier à ouvrir pour connaître le meilleur score */
	unsigned long bscore;																/* Variable qui récupère la valeur du meilleur score */
	char strscore[100];																	/* Tableau qui recevra le meilleur temps en caractères */

	ChoisirCouleurDessin(CouleurParComposante(255,153,51));								/* Affichage du texte "Niveau master" */
	EcrireTexte(575, 290, "Niveau master", 1);											/* Affichage du texte "Niveau master" */

	best_score=fopen("bestmaster","r");													/* Ouverture du fichier bestmaster en lecture seule */

	if(best_score != NULL) {
		fread(&bscore, sizeof (unsigned long), 1, best_score);							/* Lecture de la valeur du meilleur score en unsigned long enregistrement dans bscore */
		sprintf(strscore, "Meilleur score en master : %04lu s", bscore);				/* Conversion du meilleur temps en "char" et enregistrement de celui-çi dans strscore */
		fclose(best_score);																/* Fermeture du fichier bestmaster */
	} else
		sprintf(strscore, "Meilleur score en master : Aucun");
	
	ChoisirCouleurDessin(CouleurParComposante(255,51,51));								/* Affichage du meilleur temps */
	EcrireTexte(260, 370, strscore, 2);													/* Affichage du meilleur temps */

	if(best_score == NULL || jscore < bscore){											/* On regarde si le score du joueur ( jscore ) est meilleur ( plus petit ) que le  précédent meilleur score */
		
		ChoisirCouleurDessin(CouleurParComposante(0,0,0));								/* Affichage du message "Nouveau meilleur score" */
		EcrireTexte(550, 447, "Nouveau meilleur score!", 1);							/* Affichage du message "Nouveau meilleur score" */

		best_score=fopen("bestmaster","w");												/* Ouverture du fichier bestmaster en écriture seule */

		fwrite(&jscore, sizeof (unsigned long), 1, best_score);							/* réécriture du meilleur score par celui du joueur pour les prochaines parties */

		fclose(best_score);																/* Fermeture du fichier bestmaster */
	}
}



void page_finale(unsigned long score, int niveau){										/* Fonction qui gère l'affichage de toutes les informations du menu de fin */
	char str[50];																		/* Tableau qui recevra le temps du joueur en caractères */
	int logo=ChargerSprite("./Images/logo.png");										/* Variable qui possède la valeur correspondant à l'image du logo */
	int quitter=ChargerSprite("./Images/icons/stop.png");								/* Variable qui possède la valeur correspondant à l'image du bouton "Quitter" */

	ChoisirCouleurDessin(CouleurParComposante(0,0,0));									/* Affichage carré en fond du menu de fin */
	RemplirRectangle(200,100,870,514);													/* Affichage carré en fond du menu de fin */
	ChoisirCouleurDessin(CouleurParComposante(255,255,255));							/* Affichage carré en fond du menu de fin */
	RemplirRectangle(210,110,850,494);													/* Affichage carré en fond du menu de fin */

	sprintf(str, "Votre temps : %04lu s", score);										/* Conversion du temps du joueur en "char" et enregistrement de celui-çi dans str */

	AfficherSprite(logo,600,120);														/* Affichage du logo */

	ChoisirCouleurDessin(CouleurParComposante(51,123,200));								/* Affichage temps du joueur */
	EcrireTexte(260, 450, str, 2);														/* Affichage temps du joueur */

	ChoisirCouleurDessin(CouleurParComposante(255,138,0));								/* Affichage du mot "Victoire" */
	EcrireTexte(580, 250, "Victoire!", 2);												/* Affichage du mot "Victoire" */

	if(niveau==6){																		/* Si le joueur à joué en facile */
		niveau_bronze(score);															/* Appel de cette fonction pour l'affichage correspondant au niveau facile */
	}
	if(niveau==8){																		/* Si le joueur à joué en normal */
		niveau_platine(score);															/* Appel de cette fonction pour l'affichage correspondant au niveau normal */
	}
	if(niveau==10){																		/* Si le joueur à joué en difficile */
		niveau_master(score);															/* Appel de cette fonction pour l'affichage correspondant au niveau difficile */
	}

	AfficherSprite(quitter,600,500);													/* Création du bouton "Quitter" */
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));									/* Création du bouton "Quitter" */
	EcrireTexte(623, 600, "Quitter", 0);												/* Création du bouton "Quitter" */

}



void final(unsigned long score, int difficulte){										/* Fonction squelette qui gère le menu de fin */
	int x_souris, y_souris;																/* Variables qui récupèreront les cordonnées de la souris */

	InitialiserGraphique();																/* Initialisation de la fenêtre de fin, différente de la fenêtre de jeu */
	CreerFenetre(0,0,1270,714);															/* Initialisation de la fenêtre de fin, différente de la fenêtre de jeu */
	ChoisirTitreFenetre("Memowatch");													/* Initialisation de la fenêtre de fin, différente de la fenêtre de jeu */
	EffacerEcran(CouleurParComposante(255,255,255));									/* Initialisation de la fenêtre de fin, différente de la fenêtre de jeu */
	ChargerImageFond("./Images/FondAccueil.png");										/* Initialisation de la fenêtre de fin, différente de la fenêtre de jeu */

	page_finale(score, difficulte);														/* Appel de la fonction d'affichage des fonctionnalités du menu de fin */

	while(1){

		if(SourisCliquee()){															/* Détection d'un clic souris */
			SourisPosition();															/* Récupération des coordonnées de la souris */
			x_souris=_X;																/* Récupération des coordonnées de la souris */
			y_souris=_Y;																/* Récupération des coordonnées de la souris */

			if(x_souris>=600 && x_souris<=680 && y_souris>=500 && y_souris<=580){		/* Détection d'un clic souris sur le bouton "Quitter" */

				FermerGraphique();														/* Si c'est le cas, on quitte */
				break;
			}
		}
	}
}