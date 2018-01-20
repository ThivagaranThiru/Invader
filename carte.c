#include "carte.h"

Carte* init_carte(){
    // taille de la map 100 *100
  	Carte* carte = malloc(sizeof(carte));
  	carte->largeur = 100;
  	carte->longueur = 100;
  	carte->data = malloc(sizeof(char) * carte->longueur * carte->largeur);//creation de la map
  	char cptL = 0, cptH = 0;

  	do{//liberation d'espace de jeu
    	data(carte, cptH, cptL) = '0';
    	cptH++;
    	if(cptH == carte->longueur){
      		cptH = 0;
      		cptL++;
    	}
  } while (cptL < ((carte->largeur)));
  
  //affiche_carte(carte);

	return carte;
}

void affiche_carte(Carte* c){
  write(1,"\x1b[34m",5); // ecrire en bleu
  for (int i = 0; i < c -> largeur; i++){//affichage de la carte dans la console
    for (int j = 0; j < c -> longueur; j++){
      if (data(c, j, i) == '0')
      { 
        //printf("%c", data(c, j, i));
        printf(" ");
      }else printf("%c", data(c, j, i));
    }
    printf("\n");
  }
}



