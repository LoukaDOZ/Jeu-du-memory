#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "accueil.h"
/* Commentaires à droite du code. D'autres commentaires sont aussi disponibles dans accueil.h */

void regles(void) {																	/* Fonction qui affiche les règles ( Sa grande taille est due à la grande taille du texte qui la compose ) */
	int x_souris, y_souris;															/* Variables qui récupèreront les cordonnées de la souris */

		EffacerEcran(CouleurParComposante(255,255,255));							/* On réinitialise l'écran */
		ChargerImageFond("./Images/FondAccueil.png");								/* On réinitialise l'écran */

		ChoisirCouleurDessin(CouleurParComposante(80,80,80));						/* Rectangle en fond */
		RemplirRectangle(40,40,1180,634);											/* Rectangle en fond */
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));					/* Rectangle en fond */

	/* Affichage de la description des règles : */
		EcrireTexte(60,80,"- Regles -",2);
		EcrireTexte(50,120,"Un certain nombre de cartes sont presentes a l'ecran, faces cachees. Le but du jeu est simple :",1);
		EcrireTexte(50,145,"Retourner une carte et trouver sa paire parmi toutes les autres.",1);

		EcrireTexte(50,185,"La partie du joueur sera chronometree,",1);
		EcrireTexte(405,185,"son objectif sera alors d'effectuer un meilleur temps que les parties precedentes.",1);

		EcrireTexte(60,255,"- Comment Jouer -",2);
		EcrireTexte(50,295,"- Cliquer sur une carte la retournera jusqu'a ce qu'une seconde le soit egalement.",1);
		EcrireTexte(50,335,"- Une fois deux cartes retournees, elles resteront face visible pendant une seconde",1);
		EcrireTexte(50,375,"- Quand toutes les cartes sont decouvertes, le chronometre s'arretera et affichera le score du joueur",1);
		EcrireTexte(60,445,"- Mode Triche -",2);
		EcrireTexte(50,485,"En appuyant sur 'T', il est possible d'utiliser le mode tricheur.",1);
		EcrireTexte(605,485,"Mais ca n'est evidemment pas recommande pour de reelles parties.",1);
	/* Fin de l'affichage de la description des règles : */

			ChoisirCouleurDessin(CouleurParComposante(255,0,0));					/* Bouton "Retour au menu" */
			RemplirRectangle(800,600,400,60);										/* Bouton "Retour au menu" */

			ChoisirCouleurDessin(CouleurParComposante(255,255,255));				/* Bouton "Retour au menu" */
			DessinerRectangle(807,607,384,43);										/* Bouton "Retour au menu" */

			EcrireTexte(885,640,"Retour au Menu",2);								/* Bouton "Retour au menu" */

	while(1) {
		if(SourisCliquee()){														/* Détection d'un clic souris */
			SourisPosition();														/* Récupération des coordonnées de la souris */
			x_souris=_X;															/* Récupération des coordonnées de la souris */
			y_souris=_Y;															/* Récupération des coordonnées de la souris */

			if(x_souris>800 && x_souris<1200 && y_souris>600 && y_souris<1000){		/* Si un clic souris est détécté sur le bouton "Retour au menu" */
				afficher_accueil();													/* On revient au menu d'acceuil */
				break;																/* On revient au menu d'acceuil */
			}
		}
	}
}



void afficher_accueil(void){														/* Fonction chargé d'afficher les différents boutons de l'acceuil */
	EffacerEcran(CouleurParComposante(255,255,255));								/* On réinitialise l'écran */
	ChargerImageFond("./Images/FondAccueil.png");									/* On réinitialise l'écran */

    ChoisirCouleurDessin(CouleurParComposante(0,0,0));								/* Affichage des carrés pour les boutons d'action de l'acceuil */
	RemplirRectangle(200,150,230,200);												/* Affichage des carrés pour les boutons d'action de l'acceuil */
	RemplirRectangle(520,250,230,200);												/* Affichage des carrés pour les boutons d'action de l'acceuil */
	RemplirRectangle(840,350,230,200);												/* Affichage des carrés pour les boutons d'action de l'acceuil */
	ChoisirCouleurDessin(CouleurParComposante(255,255,255));						/* Affichage des carrés pour les boutons d'action de l'acceuil */
	RemplirRectangle(210,160,210,180);												/* Affichage des carrés pour les boutons d'action de l'acceuil */
	RemplirRectangle(530,260,210,180);												/* Affichage des carrés pour les boutons d'action de l'acceuil */
	RemplirRectangle(850,360,210,180);												/* Affichage des carrés pour les boutons d'action de l'acceuil */

	ChoisirCouleurDessin(CouleurParComposante(255,150,0));							/* Affichage de la description des boutons d'action de l'acceuil */
    EcrireTexte(273,300,"Jouer",2);													/* Affichage de la description des boutons d'action de l'acceuil */
    EcrireTexte(585,400,"Regles",2);												/* Affichage de la description des boutons d'action de l'acceuil */
    EcrireTexte(905,500,"Quitter",2);												/* Affichage de la description des boutons d'action de l'acceuil */

    int jouer=ChargerSprite("./Images/icons/manette.png");							/* Variable qui possède la valeur correspondant à l'image du bouton "Jouer" */
    int regle=ChargerSprite("./Images/icons/regles.png");							/* Variable qui possède la valeur correspondant à l'image du bouton "Règles" */
    int quitter=ChargerSprite("./Images/icons/stop.png");							/* Variable qui possède la valeur correspondant à l'image du bouton "Quitter" */

    AfficherSprite(jouer,275,170);													/* Affichage des icones pour les boutons d'action de l'acceuil */
    AfficherSprite(regle,590,270);													/* Affichage des icones pour les boutons d'action de l'acceuil */
    AfficherSprite(quitter,910,370);												/* Affichage des icones pour les boutons d'action de l'acceuil */

	LibererSprite(jouer);															/* Libération du sprite */
	LibererSprite(regle);															/* Libération du sprite */
	LibererSprite(quitter);															/* Libération du sprite */
}



void afficher_diffculte(void){														/* Fonction chargé d'afficher les différents boutons de difficulté après avoir cliqué sur "Jouer" */
	EffacerEcran(CouleurParComposante(255,255,255));								/* On réinitialise l'écran */
	ChargerImageFond("./Images/FondAccueil.png");									/* On réinitialise l'écran */

	ChoisirCouleurDessin(CouleurParComposante(0,0,0));								/* Affichage des carrés pour les boutons de difficulté */
	RemplirRectangle(90,210,300,300);												/* Affichage des carrés pour les boutons de difficulté */
	RemplirRectangle(490,210,300,300);												/* Affichage des carrés pour les boutons de difficulté */
	RemplirRectangle(890,210,300,300);												/* Affichage des carrés pour les boutons de difficulté */
	ChoisirCouleurDessin(CouleurParComposante(255,255,255));						/* Affichage des carrés pour les boutons de difficulté */
	RemplirRectangle(100,220,280,280);												/* Affichage des carrés pour les boutons de difficulté */
	RemplirRectangle(500,220,280,280);												/* Affichage des carrés pour les boutons de difficulté */
	RemplirRectangle(900,220,280,280);												/* Affichage des carrés pour les boutons de difficulté */

	ChoisirCouleurDessin(CouleurParComposante(255,150,0));							/* Affichage de la description des boutons de difficulté */
	EcrireTexte(185,450,"Bronze",2);												/* Affichage de la description des boutons de difficulté */
	EcrireTexte(580,450,"Platinum",2);												/* Affichage de la description des boutons de difficulté */
	EcrireTexte(990,450,"Master",2);												/* Affichage de la description des boutons de difficulté */
	EcrireTexte(128,490,"Plateau : 6x5 -> 30 cartes",1);							/* Affichage à l'écran de la taille du plateau bronze */
	EcrireTexte(527,490,"Plateau : 8x5 -> 40 cartes",1);							/* Affichage à l'écran de la taille du plateau platinum */
	EcrireTexte(925,490,"Plateau : 10x5 -> 50 cartes",1);							/* Affichage à l'écran de la taille du plateau master */

	int bronze=ChargerSprite("./Images/icons/bronze.png");							/* Variable qui possède la valeur correspondant à l'image du bouton "Bronze" */
	int platinum=ChargerSprite("./Images/icons/platinum.png");						/* Variable qui possède la valeur correspondant à l'image du bouton "Platinum" */
	int master=ChargerSprite("./Images/icons/master.png");							/* Variable qui possède la valeur correspondant à l'image du bouton "Master" */

	AfficherSprite(bronze,180,250);													/* Affichage des icones pour les boutons de difficulté */
	AfficherSprite(platinum,575,250);												/* Affichage des icones pour les boutons de difficulté */
	AfficherSprite(master,967,250);													/* Affichage des icones pour les boutons de difficulté */

	LibererSprite(bronze);															/* Libération du sprite */
	LibererSprite(platinum);														/* Libération du sprite */
	LibererSprite(master);															/* Libération du sprite */
}



int accueil(void){																	/* Fonction squelette qui gère le menu d'acceuil ( Sa grand taille est due au nombreux détecteurs de clics souris ) */
	int x_souris, y_souris;															/* Variables qui récupèreront les cordonnées de la souris */
	int diff, menu=0;																/* Variable pour savoir dans quel menu on se trouve et une qui reçoie la difficulté choisie */

	afficher_accueil();																/* Affichage de l'acceuil */

    while(menu==0){																	/* Tant qu'on est dans le menuy d'acceuil */

	if(SourisCliquee()){															/* Détection d'un clic souris */
		SourisPosition();															/* Détection d'un clic souris */
		x_souris=_X;																/* Récupération des coordonnées de la souris */
		y_souris=_Y;																/* Récupération des coordonnées de la souris */

		if(x_souris>=200 && x_souris<=430 && y_souris>=150 && y_souris<=350){		/* Si un clic souris est fait sur le bouton "Jouer" */

			afficher_diffculte();													/* Appel de la fonction d'affichage des difficultés */

		    menu++;																	/* Changement de menu */
		}


   		 if(x_souris>=520 && x_souris<=750 && y_souris>=250 && y_souris<=450){		/* Si un clic souris est fait sur le bouton "Règles" */

			regles();																/* Appel de la fonction d'affichage des règles */
		}


		 if(x_souris>=840 && x_souris<=1070 && y_souris>=350 && y_souris<=550){		/* Si un clic souris est fait sur le bouton "Quitter" */

		   	diff=-1;																/* Diff vaut -1 */

		   	FermerGraphique();														/* On ferme le graphique */

			return diff;															/* On quitte la fonction en renvoyant la valeur de diff */

		}

	}

}

	while(menu==1){																	/* Quand on est dans le menu de selection de la difficulté */

		if(SourisCliquee()){														/* Détection d'un clic souris */
			SourisPosition();														/* Détection d'un clic souris */
			x_souris=_X;															/* Détection d'un clic souris */
			y_souris=_Y;															/* Détection d'un clic souris */

			if(x_souris>=90 && x_souris<=390 && y_souris>=210 && y_souris<=510){	/* Si un clic souris est fait sur le bouton "Bronze" */

				diff=6;																/* Diff vaut 6 ( plus d'informations dans acceuil.h ) */
				FermerGraphique();													/* On ferme le graphique */

				return diff;														/* On quitte la fonction en renvoyant la valeur de diff */

			}

			if(x_souris>=490 && x_souris<=790 && y_souris>=210 && y_souris<=510){	/* Si un clic souris est fait sur le bouton "Platinum" */

				diff=8;																/* Diff vaut 8 ( plus d'informations dans acceuil.h ) */
				FermerGraphique();													/* On ferme le graphique */

				return diff;														/* On quitte la fonction en renvoyant la valeur de diff */

			}

			if(x_souris>=890 && x_souris<=1190 && y_souris>=210 && y_souris<=510){	/* Si un clic souris est fait sur le bouton "Master" */

				diff=10;															/* Diff vaut 10 ( plus d'informations dans acceuil.h ) */
				FermerGraphique();													/* On ferme le graphique */

				return diff;														/* On quitte la fonction en renvoyant la valeur de diff */

			}
		}
	}
}