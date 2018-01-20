#include "deplacement.h"

int upRock(Carte* carte, int i, int j, Invader invader){// déplacemant du missile joueur vers le haut
	
		if (i == carte->largeur+1){// 
			data(carte,j,i+1) = '0';
			return 1;
		} 

		if(data(carte,j,i) != '0'){//s il y a une collision au dessus de lui le missile s arrête
			return 1;
		}else{//sinon le effache son ancien position et affiche à sa nouvelle position
			data(carte,j,i+1) = '0';
			data(carte,j,i) = *invader.symbol;
		}

	return 0;
}

int gauche(Carte* carte, int i, int j, Invader invader){
// deplacement du vaisseau joueur 

	bool pas_de_place = false;
	int old_j = j;
	int a = i, b = j;
	int new_i = i-invader.largeur;
	int new_j = j-1; 

	for (int y = 0; y <=invader.largeur; y++){//s il en contact sur la gauche, le vaisseau est bloque
    	if(data(carte,new_j,new_i) != '0' ){
    		 pas_de_place = true;
    	}
    	new_i++;
    }

    j = old_j;

	if (i != 0 && j-1 > 0 && pas_de_place == false){

		for (int z = 0; z < invader.largeur; z++){// ici on supprime son ancienne position
		    for (int y = 0; y < invader.longueur; y++){
		    	data(carte,b,(a-((invader.largeur)-1)))= '0';
		    	b++;
		    }
		    b = old_j;
		    a++;
		}

		for (int z = 0; z < invader.largeur; z++){// affiche le vaisseau à sa nouvelle postion
		for (int y = 0; y < invader.longueur; y++){
	   		data(carte,j-1,i) = datainvader(invader, y, z);
	    	j++;
		}
		j = old_j;
		i--;
	}
		
	return 0;
	}else return 1;
} 


int droite(Carte* carte, int i, int j, Invader invader){ //deplacement du vaisseau joueur vers la droite

	bool pas_de_place = false;
	int old_j = j;
	int a = i, b = j;
	int new_i = i-invader.largeur;
	int new_j = j+invader.longueur; 

	for (int y = 0; y <=invader.largeur; y++){//s il en contact sur sa droite, le vaisseau est bloque
    	if(data(carte,new_j,new_i) != '0' ){
    		 pas_de_place = true;
    	}
    	new_i++;
    }

    if(new_j == carte->longueur) pas_de_place = true;//s il arrive au bout de la map vers la droite, le vaisseau est bloque

    j = old_j;

	if (i != 0 && j+1 < carte->longueur-2 && pas_de_place == false){

		for (int z = 0; z < invader.largeur; z++){// ici on supprime le vaisseau à sa ancienne position
		    for (int y = 0; y < invader.longueur; y++){
		    	data(carte,b,(a-((invader.largeur)-1))) = '0';
		    	b++;
		    }
		    b = old_j;
		    a++;
		}

		for (int z = 0; z < invader.largeur; z++){// affiche le vaisseau à sa nouvelle postion
			for (int y = 0; y < invader.longueur; y++){
	   			data(carte,j+1 ,i) = datainvader(invader, y, z);
	    		j++;
			}
			j = old_j;
			i--;
	}

	return 0;
	}else return 1;
}

int down(Carte* carte, int i, int j, Invader invader){// deplacement le vaissau ennemies vers là bas
	int a = i, b = j;
	int old_j = j;
	bool pas_de_place = false;
	int new_i = i + invader.largeur;

	if (new_i == 97){//quand le vaisseau ennemi viens en fin de map le jeu s'arrête
		pas_de_place = true;
		printf("VOUS AVEZ PERDU\n");
		printf("Merci d'avoir jouer.. \nFermeture\n");
		exit(EXIT_SUCCESS);
	} 

	/*for (int y = 0; y <=invader.longueur; y++){// ici pour voir s'il pas de collision entre les vaisseau
    	if(data(carte, j, new_i) != '0'){
    		//pas_de_place = true;
    		//printf("VOUS AVEZ PERDU\n");
			//printf("Merci d'avoir jouer.. \nFermeture\n");
			//exit(EXIT_SUCCESS);
    	} 
    		j++;
   	}*/


	j = old_j;

	if (pas_de_place == false){
		if (i != 0){
			for (int z = 0; z < invader.largeur; z++){// supprime le vaisseau à son ancienne position
			    for (int y = 0; y < invader.longueur; y++){
			    	data(carte,b,a-1) = '0';
			    	b++;
			    }
			    b = old_j;
			    a++;
			}
		}
		for (int z = 0; z < invader.largeur; z++){//affiche le vaisseau à sa nouvelle position
		    for (int y = 0; y < invader.longueur; y++){
	    		data(carte, j, i) = datainvader(invader, y, z);
	    		j++;
		    }
		    j = old_j;
		    i++;
		}
		return 0;
	}else return 1;

}

int downRock(Carte* carte, int i, int j, Invader invader){// missile du vaisseau ennemies vers le bas 

			if(data(carte,j,i) != '0'){//collision missile et vaisseau
				return 1;		
			}else{
				data(carte,j,i-1) = '0';
				data(carte,j,i) = *invader.symbol;	
			}

	return 0;
}

int gaucheEnne(Carte* carte, int i, int j, Invader invader){// depalement du vaisseau ennemie vers la gauche

	bool pas_de_place = false;
	int old_j = j;
	int a = i, b = j;
	int new_i = i+invader.largeur;
	int new_j = j-1; 

	for (int y = 0; y <=invader.largeur; y++){//si son coté gauche est en contact, il supprime ce dernier 
    	if(data(carte,new_j,new_i) != '0' ){
    		data(carte,new_j,new_i) = '0';
    	}
    	new_i--;
    }

    /*new_i = i+invader.largeur; 

    for (int y = 0; y <=invader.longueur; y++){ //ça permet de savoir si il y a une collision coté le vaissau 
   		if(data(carte,j-1,new_i) != '0' ){       //quand on fait un mvt gauche mais je ne sais pas si je vais m en servir
    		 pas_de_place = true;
    	}
    	j--;
    }*/

    j = old_j;

	if (i != 0 && j-1 > 0 && pas_de_place == false){

		for (int z = 0; z < invader.largeur; z++){// on supprime le vaisseau à son ancienne position
		    for (int y = 0; y < invader.longueur; y++){
		    	data(carte,b,a)= '0';
		    	b++;
		    }
		    b = old_j;
		    a++;
		}
		
		for (int z = 0; z < invader.largeur; z++){// on l affiche à sa nouvelle position
		    for (int y = 0; y < invader.longueur; y++){
	    		data(carte, j-1, i) = datainvader(invader, y, z);
		    	j++;
		    }
		    j = old_j;
		    i++;
		}
		return 0;
	}else return 1;
} 

int droiteEnn(Carte* carte, int i, int j, Invader invader){// depalement du vaisseau ennemie vers la droite

	bool pas_de_place = false;
	int old_j = j;
	int a = i, b = j;
	int new_i = i+invader.largeur;
	int new_j = j+invader.longueur; 

	for (int y = 0; y <=invader.largeur; y++){
    	if(data(carte,new_j,new_i) != '0' ){
    		data(carte,new_j,new_i) = '0';
    	}
    	new_i--;
    }

    /*new_i = i+invader.largeur; 

    for (int y = 0; y <=invader.longueur; y++){//ça permet de savoir si il y a une collision devant le vaissau 
    	if(data(carte,j+1,new_i) != '0' ){		//quand on fait un mvt droite mais je ne sais pas si je vais m en servir
    		 pas_de_place = true;
    	}
    	j++;
    }*/

	if(new_j == carte->longueur) pas_de_place = true;

    j = old_j;

	if (i != 0 && j+1 < carte->longueur-2 && pas_de_place == false){

		for (int z = 0; z < invader.largeur; z++){// on supprime le vaisseau à son ancienne position
		    for (int y = 0; y < invader.longueur; y++){
		    	data(carte,b,a) = '0';
		    	b++;
		    }
		    b = old_j;
		    a++;
		}

		for (int z = 0; z < invader.largeur; z++){// on l affiche à sa nouvelle position
		    for (int y = 0; y < invader.longueur; y++){
	    		data(carte, j+1, i) = datainvader(invader, y, z);
	    		j++;
		    }
		    j = old_j;
		    i++;
		}
		return 0;
	}else return 1;
}

//recuperer le temps au moment ou on appel la fonction et renvoie des mili seconde .
double getMili(){
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	double time_in_mili = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;		
	return time_in_mili;
}


int move(Carte* carte,Invader* invader,double vitesse,InvaderEnn* invaderEnn){

	int l = 99, m = carte->longueur/2, int_touch; 
	int old_m = m;
	int cl = 0;
	//int cm = 0;
	int n = 0;
	int new_l = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	int p = 0;
	int h = 0;
	int new_i = 0;
	int old_j = j;
	int t = 1;
	char* touch = malloc(sizeof(char));//la touche enfoncé par l'utilisateur

	for (int n = 0; n < invader[1].largeur; n++){// affichage du vaisseau joueur en fin de map
		for (int o = 0; o < invader[1].longueur; o++){
	   		data(carte,m,l) = datainvader(invader[1], o, n);
	    	m++;
		}
		m = old_m;
		l--;
	}

    l = 99;
    m = carte->longueur/2;

    while(t <= invaderEnn[0].nb_invader){//affichage des vaisseaux ennemies aau coordonnée donnée
        i = invaderEnn[t].posx;
        j = invaderEnn[t].posy;
        old_j = j;
		for (int z = 0; z < invaderEnn[t].invader->largeur; z++){
			for (int y = 0; y < invaderEnn[t].invader->longueur; y++){
			    data(carte, j, i) = datainvader(*invaderEnn[t].invader, y, z);
			    j++;
			}
			j = old_j;
			i++;
		}
		t++;
	}

	t = invaderEnn[0].nb_invader;
	/*POUR LE MODE NON CANONIQUE*/
	//On cree deux structure de type termios
	struct termios origine;
	struct termios new;
    //On recupere la configuration initial du terminal et on la copie dans la new structure, on modifie enfin le flag
	if (tcgetattr(STDIN_FILENO,& origine) < 0) perror("Erreur tcgetattr 1 : ");
	
	new = origine;
	//On le met en mode non canonique (ICANON pas positioné)
	new.c_lflag &= ~(ICANON | ECHO); 
	//et on veut 1 caractere par 1  caractere
	new.c_cc[VMIN] = 1;
	//temps qu"on a pas un caractere tapé on attend lis le man de termios vers le bas c bien expliqué, mtn on a plus besoin de taper entrer a chaque fois
	new.c_cc[VTIME] = 0;

	if (tcsetattr(STDIN_FILENO,TCSANOW,&new) < 0) perror("Erreur tcsetattr 1 : ");

	struct pollfd fds[1];
	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;

	double oldVitesse =vitesse;

	while(1){
		clear();
		affiche_carte(carte);//affichage continue de la carte
		
		//On recupere le temps avant le poll puis le poll decoule selon son timeOut si il y a un evenement alors on fait le calcul tout en bas du WHile sinon on remet la vitesse a la vitesse par defaut
		double beforePoll= getMili();
		int_touch = poll(fds, 1, vitesse);//execution de poll avec la vitesse de la map
		touch[0] = int_touch;

		if(touch[0] == 0){//si l'utilisateur ne touche aucun bouton 
			while(t != 0){// ici déplacement des vaisseaux ennemies par rapport à leurs cycle de déplacement
				if(invaderEnn[t].invader->life > 0){
		       	    i = invaderEnn[t].posx;
		       	    j = invaderEnn[t].posy;
		       	    /*
		       	    //Tire des missiles
		       	    cm = ((i + (invaderEnn[t].invader->largeur))+1); 

					while(cm < 100){
						if(downRock(carte,cm,j,*invaderEnn[t].invader) == 0){
							cm++;
						}else cm = 100;
					}
					data(carte,j,cm-1) = '0';*/

					if(invaderEnn[t].invader->depH[k] == 1 && invaderEnn[t].invader->depV[k] == 0){
						if(droiteEnn(carte, i, j, *invaderEnn[t].invader) == 0){
							j++;
						}
					}else if(invaderEnn[t].invader->depH[k] == (-1) && invaderEnn[t].invader->depV[k] == 0){
							if(gaucheEnne(carte, i, j, *invaderEnn[t].invader) == 0){
								j--;
							}
						  }else if(invaderEnn[t].invader->depH[k] == 1 && invaderEnn[t].invader->depV[k] == (-1)){
						  			if(droiteEnn(carte, i, j,*invaderEnn[t].invader) == 0){
									   j++;
									}
									i++;
									if(down(carte, i, j,*invaderEnn[t].invader) == 0){
									}
						 		}else if(invaderEnn[t].invader->depH[k] == (-1) && invaderEnn[t].invader->depV[k] == (-1)){
						 			  	if(gaucheEnne(carte, i, j,*invaderEnn[t].invader) == 0){
											j--;
							  		  	}
							  		  	i++;
							  		  	if(down(carte, i, j,*invaderEnn[t].invader) == 0){
									  	}
						 		}else if(invaderEnn[t].invader->depH[k] == 0 && invaderEnn[t].invader->depV[k] == (-1)){
						 			 	i++;
						 			 	if(down(carte, i, j,*invaderEnn[t].invader) == 0){
									  	}
						 			 }
					invaderEnn[t].posx = i;
		       	    invaderEnn[t].posy = j;

		       	    p = invaderEnn[t].posx;
		       	    h = invaderEnn[t].posy;
		       	   	new_i = i + invaderEnn[t].invader->largeur;
		       	   	old_j = j;

		       		for (int e = 0; e <= invaderEnn[t].invader->longueur; e++){// ici pour voir s'il y a missile qui a touché un vaisseau enemie, supprime le missile et on enlève sa vie 
	    				if(data(carte, j, new_i) != '0'){
	    					invaderEnn[t].invader->life = invaderEnn[t].invader->life - invader[1].power_shoot;
	    					if (invaderEnn[t].invader->life <= 0){
	    						for (int z = 0; z < invaderEnn[t].invader->largeur; z++){
									for (int y = 0; y < invaderEnn[t].invader->longueur+1; y++){
				    					data(carte, h, p) = '0';
				    					h++;
									}
									h = old_j;
									p++;
								}
								n++;
	    					}
	    					data(carte, j, new_i) = '0';
	    				} 
	    				j++;
	   		 		} 
					j = old_j;

		       	    t--;
		       	}else t--;
			}
			if(t == 0){
				if(k == invaderEnn[1].invader->long_cycl_depla){
						k = 0;
						t = invaderEnn[0].nb_invader;
				}else{
					t = invaderEnn[0].nb_invader;
					k++;
				}
			}
			if(n == invaderEnn[0].nb_invader){// s il n y a plus de vaisseau ennemie on passe à un autre partie du même niveau
				return 1;
			}
		}else read(0, touch, 1); 
		//sinon on recupere le mouvement à affectuer vaisseau joueur
		if (touch[0] == 68){// mouvement gauche du vaisseau joueur
			if(gauche(carte, l, m, invader[1]) == 0){
				m--;
			} 
		}

		if (touch[0] == 67){// mouvement droite du vaisseau joueur
			if(droite(carte, l, m, invader[1]) == 0){
				m++;
			}
		}

		if (touch[0] == 32){//tire un missile avec la touche "espaces"
			cl = ((l -(invader[1].largeur))-1);
			while(cl > 0){
				if(upRock(carte,cl,m,invader[1]) == 0){
					cl--;
				}else cl = 0;

			}
			if (cl == (0)) data(carte,m,cl+1) = '0'; 
		}


		new_l = l - invader[1].largeur;
	    old_m = m;

	    for (int e = 0; e <= invader[1].longueur; e++){//pour voir s il y a une collision entre un missile et vaisseau joueur
    		if(data(carte, m, new_l) != '0'){
    			for(int s = 2; s <= 5; s++){
    				if (*invader[s].symbol == data(carte, m, new_l)){			
    					invader[1].life = invader[1].life - invader[s].power_shoot;
    				}
    				if (invader[1].life <= 0){
    					tcsetattr(STDIN_FILENO,TCSANOW,& origine);
						printf("Merci d'avoir jouer.. \nFermeture\n");
						exit(EXIT_SUCCESS);
    				}
    			}
    			data(carte, m, new_l) = '0';
    		} 
    		m++;
   		} 

		m = old_m;

		if (touch[0] == 102){//touche "f" pour stoper le jeu
			tcsetattr(STDIN_FILENO,TCSANOW,& origine);
			printf("Merci d'avoir jouer.. \nFermeture\n");
			exit(EXIT_SUCCESS);
		}

		//on recuperer le temps apres les evenement géré , et si il a eu un evenement de Poll alors on fait le calcul pour la vitesse sinon on remet vitesse = oldVitesse
		double afterPoll= getMili();
		if(touch[0] != 0){
			vitesse = vitesse - (afterPoll-beforePoll);
		}else{
			vitesse = oldVitesse;
		}

	}
	return 0;
}