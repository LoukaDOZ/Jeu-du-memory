#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <graph.h>
#include "game.h"
/* Commentaires à droite du code. D'autres commentaires sont aussi disponibles dans game.h */

void remplir_tableaux(int* tab, int* tab2, int* tab3, int size){									/* Cette fonction à pour simple but de remplir tous les tableaux avec uniquement des zeros */

		/* Cette fonction est importante car elle permet déjà de connaître éxactement les valeurs dans les tableaux, 
		mais aussi car toute autre valeur que 0, dans ce programme, correspond à une action spécifique */

	int i;

	for(i=0; i<size*5; i++){

		tab[i]=0;																					/* On rempli de 0, FaceCarte */
		tab2[i]=0;																					/* On rempli de 0, typeCarte */
		tab3[i]=0;																					/* On rempli de 0, cartesTrouvees */
	}
}



int carte_random(int Max){																			/* Cette fonction a pour but de renvoyer une valeur aléatoire */
	int MIN=0, a, MAX=Max;																			/* MAX vaut le nombre de cartes totales du plateau transmis en argument par le biet de Max */

	a=rand()%(MAX-MIN)+MIN;																			/* La variable a prend une valeur aléatoire entre 0 et MAX */

	return a;																						/* On quitte la fonction en retournant la valeur de a */
}



void cartes_aleatoires(int* typec, int size){														/* Cette fonction est utilisée pour mélanger aléatoiremetn les cartes au début de la partie */
	int n, p, q=0;																					/* la variable n est la valeur de la cartes, p un compteur et q le numéro de la carte qui va reçevoir la valeur n */

	for(n=1, p=0; n<=((size*5)/2); p++){															/* Tant que n ne dépasse pas le nombre de paires, on augmente p de 1 à chaque fois */

		q=carte_random((size*5));																	/* On donne à q une valeur aléatoire reçue de carte_random */

		if(p==2){																					/* Si p à atteint 2 */

			n++;																					/* Alors n augmente de 1 */
			p=0;																					/* Et p revient à la valeur 0 */
		}

		if(typec[q]==0){																			/* Si la carte choisie au hasard n'a pas encore eu une valeur attribuée */

			typec[q]=n;																				/* Elle prend la valeur de n */
		}else{																						/* Si la carte choisie au hasard a déjà une valeur attribuée */

			p--;																					/* On refait un tour de plus car aucune carte n'a reçu la valeur n */
		}
	}
}



int marge(int size){																				/* Cette fonction à pour unique but de connaître la position en x de la première colonne en fonction de la taille du plateau, donc de la difficulté */
	int pos_x;																						/* Variable qui recevra la position en x de la première colonne */

	if(size==6){																					/* Si le joueur est en mode facile ( bronze ) */

		pos_x=280;																					/* Alors la position initiale est de 280 pixels */
	}

	if(size==8){																					/* Si le joueur est en mode normal ( platinum ) */

		pos_x=150;																					/* Alors la position initiale est de 150 pixels */
	}

	if(size==10){																					/* Si le joueur est en mode difficile ( master ) */

		pos_x=40;																					/* Alors la position initiale est de 40 pixels */
	}

	return pos_x;																					/* On quitte en renvoyant la position de la première colonne en x */
}



void afficher_recto(int* type, int a, int x_pos, int y_pos){										/* Cette fonction affiche la face découverte d'une carte. Sa grande taille est due au nombre d'icones de cartes possible ( 25 au maximum ) */
	int imageCarte;																					/* Variable qui aura la valeur correspondant à un sprite */

/* Dans ce qui suit, chaque valeur qu'une carte possède correspond à une icone : */
/* On regarde à quelle icone la valeur de la carte correspond */
/* On donne à imageCarte la valeur correspondant à l'icone */
/* On affiche l'icone dans le rectangle noir aux cordonnées x_pos, y_pos */

	if(type[a]==1){
		imageCarte=ChargerSprite("./Images/icons/ana.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==2){
		imageCarte=ChargerSprite("./Images/icons/ange.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==3){
		imageCarte=ChargerSprite("./Images/icons/ashe.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==4){
		imageCarte=ChargerSprite("./Images/icons/brigitte.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==5){
		imageCarte=ChargerSprite("./Images/icons/chacal.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==6){
		imageCarte=ChargerSprite("./Images/icons/chopper.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==7){
		imageCarte=ChargerSprite("./Images/icons/doom.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==8){
		imageCarte=ChargerSprite("./Images/icons/dva.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==9){
		imageCarte=ChargerSprite("./Images/icons/faucheur.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==10){
		imageCarte=ChargerSprite("./Images/icons/genji.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==11){
		imageCarte=ChargerSprite("./Images/icons/hammond.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==12){
		imageCarte=ChargerSprite("./Images/icons/hanzo.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==13){
		imageCarte=ChargerSprite("./Images/icons/lucio.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==14){
		imageCarte=ChargerSprite("./Images/icons/maccree.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==15){
		imageCarte=ChargerSprite("./Images/icons/mei.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==16){
		imageCarte=ChargerSprite("./Images/icons/moira.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==17){
		imageCarte=ChargerSprite("./Images/icons/orisa.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==18){
		imageCarte=ChargerSprite("./Images/icons/phara.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==19){
		imageCarte=ChargerSprite("./Images/icons/rein.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==20){
		imageCarte=ChargerSprite("./Images/icons/sombra.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==21){
		imageCarte=ChargerSprite("./Images/icons/symetra.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==22){
		imageCarte=ChargerSprite("./Images/icons/torb.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==23){
		imageCarte=ChargerSprite("./Images/icons/tracer.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==24){
		imageCarte=ChargerSprite("./Images/icons/zarya.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}
	if(type[a]==25){
		imageCarte=ChargerSprite("./Images/icons/zen.png");
		AfficherSprite(imageCarte,x_pos+10,y_pos+20);
	}

	LibererSprite(imageCarte);																		/* On libère le sprite */
}

void afficher_fond(int* type, int size, int pos_x){									/* On utilise cette fonction pour afficher les cartes face cachée ou découverte */
	int j;
	int position_x=pos_x, position_y=20;															/* Positions initiales de la première carte ( en haut à gauche ) */
	int fond=ChargerSprite("./Images/fondcartes.png");												/* Variable qui possède la valeur correspondant à l'image qui fait le contour des cartes */													
	int couleur = 0;

	for(j=0; j<size*5; j++, position_x+=120){														/* On parcours toutes les cartes par rapport à leur position en x et y */

		if(j==size || j==size*2 || j==size*3 || j==size*4){											/* Si on atteint le bout de la ligne */

			position_x=pos_x;																		/* On revient à la première colonne */
			position_y+=140;																		/* Mais cette fois on passe à la ligne suivante */
		}

		AfficherSprite(fond,position_x,position_y);												/* On affiche l'image du contour des cartes */
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));								/* On créé un rectangle blanc plus petit par dessus */
		RemplirRectangle(position_x+3,position_y+3,94,114);										/* On créé un rectangle blanc plus petit par dessus */
	}
	LibererSprite(fond);																			/* On libère le sprite */
}

void afficher_verso(int* facec, int* type, int size, int pos_x){									/* On utilise cette fonction pour afficher les cartes face cachée ou découverte */
	int j;
	int position_x=pos_x, position_y=20;															/* Positions initiales de la première carte ( en haut à gauche ) */													
	int logo=ChargerSprite("./Images/logo.png");													/* Variable qui possède la valeur correspondant à l'image du logo */
	int couleur = 0;

	for(j=0; j<size*5; j++, position_x+=120){														/* On parcours toutes les cartes par rapport à leur position en x et y */

		if(j==size || j==size*2 || j==size*3 || j==size*4){											/* Si on atteint le bout de la ligne */

			position_x=pos_x;																		/* On revient à la première colonne */
			position_y+=140;																		/* Mais cette fois on passe à la ligne suivante */
		}

		if(facec[j]==0){																			/* Si la carte doit etre face cachée ( vaut 0 ) */

			AfficherSprite(logo,position_x+10,position_y+30);										/* On affiche l'image du logo */
		}else{

			afficher_recto(type, j, position_x, position_y);										/* Si la carte doit être face découverte ( vaut 1 ), on appelle la fonction afficher_recto */
		}
	}

	LibererSprite(logo);																			/* On libère le sprite */
}



int clic_carte(int* facec, int* nb_retournee, int* cTrouvee, int souris_x, int souris_y, int pos_x, int size, int compte){ /* Cette fonction détecte sur quelles cartes les clics souris sont réalsés */
	int j, position_x=pos_x, position_y=20;															/* Positions initiales de la première carte ( en haut à gauche ) */

	for(j=0; j<size*5; j++, position_x+=120){														/* On parcours toutes les cartes par rapport à leur position en x et y */

		if(j==size || j==size*2 || j==size*3 || j==size*4){											/* Si on atteint le bout de la ligne */

			position_x=pos_x;																		/* On revient à la première colonne */
			position_y+=140;																		/* Mais cette fois on passe à la ligne suivante */
		}
		
		if(souris_x>position_x && souris_y>position_y && souris_x<position_x+100 && souris_y<position_y+120 && facec[j]==0 && cTrouvee[j]==0){ /* Si la position de la souris est en accord avec celle d'une carte */

			facec[j]=1;																				/* Cette carte est mise face retournée */
			compte++;																				/* Compte est augmenté de 1 */

			if(nb_retournee[0]==0){																	/* Si la première case de nb_retournee n'est pas utilisé pour stocker une valeur */

				nb_retournee[0]=j;																	/* Nb_retournee prend la valeur du numéro correspondant à la carte */
			}else{																					/* Si la première case de nb_retournee est déjà utilisé pour stocker une valeur */

				nb_retournee[1]=j;																	/* C'est la seconde case de nb_retournee qui stocke la valeur du numéro de la carte */
			}
		}
	}

	return compte;																					/* On quitte en renvoyant la valeur de compte */
}



unsigned long triche(int* typec, int size, int x){													/* Cette fonction, donne à chronoVariable sa valeur, mais surtout elle met toutes les cartes face découvertes quand la touche T est pressée */

	unsigned long tempsTriche=0;																	/* Variable qui prendra le temps écoulé durant le lancement et l'arrêt du mode tricheuret si le mode tricheur n'est pas ctivé, elle prend 0 */
	int bin;																						/* Variable poubelle */

	if(ToucheEnAttente()==1 && Touche()=='t'){														/* Si la touche T est pressée */
	
		int i;
		int* tricheFace;																			/* Ce tableau est utilisé de la même façon que faceCartes, à la différence qu'il n'affiche que les cartes face découverte */

		tricheFace = (int*) malloc((size*5)*sizeof(int));											/* Initialisation de la taille du tableau en fonction de la difficulté */

		for(i=0; i<size*5; i++){																	/* Remplissage du tableau avec uniquement dla valeur 1 */
			tricheFace[i]=1;																		/* Remplissage du tableau avec uniquement dla valeur 1 */
		}

		afficher_verso(tricheFace, typec, size, x);													/* Affichage des cartes mais avec cette fois tricheFace en tableau au lien de faceCartes ce qui retourne toutes les cartes */

		while(1){

			tempsTriche = Microsecondes();															/* Si le mode tricheur est activé, tempsTriche prend le temps écoulé durant le lancement et l'arrêt du mode tricheur */

			if(ToucheEnAttente()==1 && Touche()=='t'){												/* Si T est de nouveau pressé */

			afficher_fond(typec, size, x);

				free(tricheFace);																	/* Libération du tableau tricheFace */
				break;																				/* On quitte la boucle while et donc la fonction */
			}
		}
	}

	while(SourisCliquee()){																			/* Quand un clic souris est détecté */

		bin=_X;																						/* On jette à la poubelle les coordonées de la souris pour éviter de pouvoir cliquer quand le mode triche est activé */ 
		bin=_Y;																						/* On jette à la poubelle les coordonées de la souris pour éviter de pouvoir cliquer quand le mode triche est activé */ 
	}

	return tempsTriche;																				/* On quitte la fonction en renvoyant tempsTriche */
}



int paires(int* nb_retournee, int* typec, int* cTrouvees){											/* Cette fonction vérifie si 2 cartes retournées par le joueur sont des paires ou non */
	int i;

	if(typec[nb_retournee[0]]==typec[nb_retournee[1]]){												/* Si la première carte retournée est identique ( la même valeur ) à la deuxièeme */

		cTrouvees[nb_retournee[0]]=1;																/* On enregistre dans cTrouvees la valeur de la paire trouvée */

		for(i=0; i<2; i++){																			/* On remet les valeurs de nb_retournées à 0 */

				nb_retournee[i]=0;																	/* On remet les valeurs de nb_retournées à 0 */
			}

		return 1;																					/* Et on renvoie 1 */
	}else{

		return 0;																					/* Sinon, on renvoie 0 */
	}
}



int victoire(int* cTrouvee, int size){																/* fonction dont le but est de vérifier si le joueur à trouvé toutes les paires de cartes */
	int i, valeur;

	for(i=1; i<(size*5); i++){																		/* On regarde toutes les cartes */

		if(cTrouvee[i]==0){																			/* Si une carte est encore face cachée */

			valeur=0;																				/* Alors valeur prend 0 */
			break;																					/* On s'arrête de vérifier */
		}else{

			valeur=1;																				/* Sinon, valeur prend 1 */
		}
	}
	return valeur;																					/* Sortie de la fonction avec revoie de valeur ( 0 ou 1 ) */
}



unsigned long timer(unsigned long chronoV, unsigned long chronoF, unsigned long timeTriche, int* incremente, unsigned long* cRes2) {/* Cette fonction à pour but de caclculer le temps qui s'écoule depuis le lancement de la partie, puis de l'afficher */
	unsigned long chronoRes=0;																		/* Variable qui recevra le temps écoulé depuis le lancement de la partie */
	char str[50];																					/* Tableau qui recevra le temps en caractères */

	chronoRes = (chronoV - chronoF)/1000000;														/* Attribution à chronoRes, chronoVariable - chronoFixe ( déclaré dans le main ), le tout mis en secondes */

	if(timeTriche!=0){																				/* Si le joueur a appuyé sur le mode tricheur */

		chronoRes -= ((timeTriche - chronoF)/1000000)/2;											/* On retire, au temps total, le temps écoulé durant le lancement et l'arrêt du mode tricheur */
	}

	if(*cRes2 == 0){																				/* Si le chronomètre est à 0 */

		ChoisirCouleurDessin(CouleurParComposante(255,255,255));									/* Affichage du temps à 0 */
		EcrireTexte(450, 780, "Temps ecoule : 0000 s", 2);											/* Affichage du temps à 0 */
	}

	if(chronoRes > *cRes2){																			/* Si une seconde s'est écoulée */
		
		*cRes2 = chronoRes;																			/* ChronoRes2 se remet au même  niveau que chronoRes */
		*incremente += 1;																			/* On augmente le chronomètre de 1 seconde suplémentaire */
		sprintf(str, "Temps ecoule : %04d s", *incremente);											/* Conversion du temps en "char" et enregistrement de celui-çi dans str */

		ChoisirCouleurDessin(CouleurParComposante(20,20,20));										/* Ajout d'un bloc pour empêcher un chevauchement du temps avec l'ancienne valeur du temps */
		RemplirRectangle(0,714,1270,100);															/* Ajout d'un bloc pour empêcher un chevauchement du temps avec l'ancienne valeur du temps */

		ChoisirCouleurDessin(CouleurParComposante(255,255,255));									/* Affichage du nouveau temps */
		EcrireTexte(450, 780, str, 2);																/* Affichage du nouveau temps */

		int exit=ChargerSprite("./Images/icons/exit.png");
		AfficherSprite(exit,1050,715);
		LibererSprite(exit);
		}

	return *incremente;																				/* Sortie de la fonction avec revoie du temps */
}



void cartes_differentes(unsigned long temps1, unsigned long temps2, int* nb_retournee, int* facec){	/* Après 1 seconde, cette fonction remet tout à 0 lorsque les 2 cartes retournées ne sont pas identiques */
	int i, stock;																					/* Stock enregistrera la valeur la carte retournée, pour la remettre face cachée ensuite */

	while(1){
		temps2 = Microsecondes();																	/* Attribution d'une valeur en microsecondes à temps2 */

		if( ((temps2 - temps1)/1000000) > 0){														/* Si 1 seconde s'est écoulée */

			for(i=0; i<2; i++){

				stock=nb_retournee[i];																/* Stock prend la valeur de nb_retournee[i], soit une des 2 cartes retournée */
				facec[stock]=0;																		/* Cette même carte est remiste face cachée */
				nb_retournee[i]=0;																	/* Nb_retournee[i] est ensuite remis à 0 */
				}

			break;																					/* Une fois les 2 cartes remises face cachée, on quitte la fonction */
		}
	}
}



unsigned long game(int taille, unsigned long chronoFixe){											/* Fonction squelette qui gère la partie jeu. La variable taille correspond a la valeur de la difficulté */
																									/* Sa grande taille est due aux nombreuses déclaration et appels de fonctions */
	int* faceCarte;																					/* Tableau qui gérera l'affichage recto ( vaut 1 ) ou verso ( vaut 0 ) des cartes */
	int* typeCarte;																					/* Tableau qui permettera d'afficher l'icone, correspondant à une valeur, sur le recto des cartes */
	int* cartesTrouvees;																			/* Tableau qui enregistrera quelles paires ont été trouvées */
	int x, compteur=0, paire=0, gagner=0, drapTriche=0;												/* Variables pour de futur utilistations. La variable "x" sera la position initiale en x de la première colonne de cartes */
	int x_souris, y_souris;																			/* Variables qui récupèreront les cordonnées de la souris */
	int nb_retournee[2]={0,0};																		/* Tableau qui aura pour but de recupérer la valeur correspondant aux cartes retournées */
	unsigned long chronoVariable, temps1, temps2, tempsFinal, tempsTriche;							/* Variable pour de futur utilisations en lien avec le chronomètre */
	int incrementation = 0;																			/* Variable qui gère le temps que le joueur met pour finir la partie */
	unsigned long chronoRes2 = 0;																	/* Variable de comparaison utile dans l'incrémentation du chronomètre ( voir fonction timer ) */

	faceCarte = (int*) malloc((taille*5)*sizeof(int));												/* Initialisation de la taille du tableau en fonction de la difficulté */
	typeCarte = (int*) malloc((taille*5)*sizeof(int));												/* Initialisation de la taille du tableau en fonction de la difficulté */
	cartesTrouvees = (int*) malloc((taille*5)*sizeof(int));											/* Initialisation de la taille du tableau en fonction de la difficulté */

	remplir_tableaux(faceCarte, typeCarte, cartesTrouvees, taille);									/* Appel d'une fonction de remplissage des tableaux */

	cartes_aleatoires(typeCarte, taille);															/* Appel d'une fonction d'attribution aléatoire de valeurs */        

	InitialiserGraphique();																			/* Initialisation d'une nouvelle fenêtre de jeu car sa taille est plus grande que celle d'acceuil */
	CreerFenetre(0,0,1270,814);																		/* Initialiation de la fenêtre de jeu */
	ChargerImageFond("./Images/FondAccueil.png");													/* Initialiation de la fenêtre de jeu */
	ChoisirTitreFenetre("Memowatch");																/* Initialiation de la fenêtre de jeu */
	ChoisirCouleurDessin(CouleurParComposante(20,20,20));											/* Initialiation de la fenêtre de jeu */
	RemplirRectangle(0,714,1270,100);																/* Initialiation de la fenêtre de jeu */

	x=marge(taille);																				/* Appel d'une fonction pour obtenir une marge pour l'affichage des cartes */
	afficher_fond(typeCarte, taille, x);
	afficher_verso(faceCarte, typeCarte, taille, x);												/* Appel d'une fonction pour afficher les cartes */

	int exit=ChargerSprite("./Images/icons/exit.png");
	AfficherSprite(exit,1050,715);
	LibererSprite(exit);

	while(1){

		temps1 = Microsecondes();																	/* Attribution d'une valeur en microsecondes à temps1 */
		chronoVariable = Microsecondes();

		if(tempsFinal>2){
			tempsTriche = triche(typeCarte, taille, x);													/* Appel de la fonction pour le mode triche */
		}
		
		afficher_verso(faceCarte, typeCarte, taille, x);											/* Appel d'une fonction pour afficher les cartes */

		tempsFinal = timer(chronoVariable, chronoFixe, tempsTriche, &incrementation, &chronoRes2);	/* Utilisation de la fonction timer pour afficher un chronomètre*/

		if(SourisCliquee()){																		/* Détection d'un clic souris */
			SourisPosition();																		/* Récupération des coordonnées de la souris */
			x_souris=_X;																			/* Récupération des coordonnées de la souris */
			y_souris=_Y;																			/* Récupération des coordonnées de la souris */

			if(x_souris>=1050 && x_souris<=1170 && y_souris>=715 && y_souris<=832){
				tempsFinal = 0;
				break;
			}

			compteur=clic_carte(faceCarte, nb_retournee, cartesTrouvees, x_souris, y_souris, x, taille, compteur);	/* Appel de la fonction clic_carte après le clic souris */

			afficher_verso(faceCarte, typeCarte, taille, x);										/* Appel d'une fonction pour afficher les cartes */
		}

		if(compteur==2){																			/* Si 2 cartes ont été retournées */
			paire=paires(nb_retournee, typeCarte, cartesTrouvees);									/* On appelle la fonction paires pour vérifier si elles sont identiques */

			if(paire==0){																			/* Si ce ne sont pas les mêmes */
					
				cartes_differentes(temps1, temps2, nb_retournee, faceCarte);						/* On appel cette fonction pour tout remettre à 0 */
				}
				
				afficher_fond(typeCarte, taille, x);
				afficher_verso(faceCarte, typeCarte, taille, x);
				compteur=0;																			/* Compteur est remis à 0 */
			}

		gagner=victoire(faceCarte, taille);															/* Appel de la fonction victoire pour vérifier si toutes les cartes ont été retournées */
		if(gagner==1){																				/* Si oui */
			afficher_verso(faceCarte, typeCarte, taille, x);										/* Appel d'une fonction pour afficher les cartes */
			sleep(1);																				/* On attend 1 seconde */
			break;																					/* On quitte la boucle while */
		}
	}

	FermerGraphique();																				/* Fermeture du graphique */
	free(faceCarte);																				/* Libération du tableau */
	free(typeCarte);																				/* Libération du tableau */
	free(cartesTrouvees);																			/* Libération du tableau */

	return tempsFinal;																				/* On quitte la foncion game en renvoyant le temps réalisé par le joueur */
}