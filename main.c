#include "main.h"    

char** menu(){
  int i=0;
  char buf2[1024];
  char *test[10];
  char buf[10];

  char * menu = "\t\tMenu\n";

  write(1,"\x1b[?25l",6); //On cache le curseur
  write(1,"\x1b[92m",5);  // menu en vert
  write(1,"\x1b[5m",4);//clignotement
  write(1,menu,strlen(menu));
  write(1,"\x1b[0m",4);

  DIR* rep;
  struct dirent *lire;
  rep = opendir("MOD");
  if (rep == NULL){ 
    perror("Impossible d'ouvrir le flux de MAP (menu.c ): 1");
    sleep(2);
    exit(EXIT_FAILURE);
  } 

  while((lire=readdir(rep))!=NULL){
    if(strcmp(lire->d_name,".")!=0 && strcmp(lire->d_name,"..")!=0){
        if((lire->d_type)&=DT_DIR){
        //On place dans notre tableau
        test[i]=lire->d_name;
        //On affiche le numero+1
        sprintf(buf,"%d",i+1);
        write(1,buf,strlen(buf));

        write(1," - ",3);
        //et on affiche le nom du mod
        write(1,test[i],strlen(test[i]));
        write(1,"\n",2);
      }
      i++;
    }
  }

  closedir(rep);

  write(1,"Quel mods voulez vous ? (f pour quitter )\n",43);

  read(STDIN_FILENO,buf,1);
  if(strcmp(buf,"f")==0){
    menu="                 FIN...Bye !\n";
    write(1,"\x1b[94m",5);
    write(1,menu,strlen(menu));
    write(1,"\x1b[0m",4);
    sleep(2);
    exit(EXIT_SUCCESS);
  }

  int mod;
  mod = atoi(buf)-1;
  if (chdir("MOD") == -1){
    perror("Erreur ouverture dossier MAP (menu.c): 2");
    sleep(2);
    exit(EXIT_FAILURE);
  }
  if(chdir(test[mod]) == -1){ 
    perror("Impossible d'ouvrire ce mode (menu.c): 3");       
    sleep(2); 
    exit(EXIT_FAILURE);
  }
  
  int fd = open("deroulement", O_RDONLY);
  read(fd,buf2,2024);

  i=0;// on stocke les informations contenut dans déroulement pour les parties du niveau
  int cmpt=0,j=0;
  while(buf2[i] != '\0'){
    if(buf2[i] == '\n') cmpt++;
    i++;
  }
  cmpt--;
  char **argv = malloc(sizeof(char*)*(cmpt+2));

  argv[cmpt+1]=NULL;
  char *prec=buf2;
  char *cur=buf2;
  while (cur!=NULL){
    cur=strpbrk(prec,"\n");
    argv[j]=prec;
    j++;
    if(cur != NULL){
      *cur=0;
      prec=cur+1;
    }
  } 

  close(fd);
  i = 0;

  write(1,test[mod],strlen(test[mod]));
  printf("\nChargement du niveau ...\n\n\n");

  sleep(1);
  return argv;
}



int main (int argc,char *argv[]){
	char** Vmenu = menu();//Ouverture du dossier contenant les fichiers niveaux

	int p = 6;
	int q = 5;
	double vitesse = (double) p / (double) q * 1000;// vitesse de la map
	
	Carte* carte = init_carte();//initialisation de la carte

	char n[1024];

	Invader* invader1 = malloc(sizeof(Invader) * argc);//allocation memoire pour la structure invader
	
	int indextype = 1;

	if(chdir("vaisseau") == -1) {// on rentre dans le répertoire vaisseau
    	perror("Impossible d'ouvrir dossier niveaux (menu.c): 3");      
    	sleep(2); 
    	exit(EXIT_FAILURE); 
  	}

	for(int j = 1; j <= 5 ; j++){// on stocke tous les informations des vaissaux dans une structure invader chacun
		sprintf(n,"%d",j);
		int fd2 = open(n,O_RDONLY);
		int i = 0;
		char *buf = malloc(sizeof(char)*BUF);
		char c[1], cptL = 0, cptH = 0;

		read(fd2,buf,1);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].longueur = atoi(buf);
		
		read(fd2,buf,1);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].largeur = atoi(buf);

		read(fd2,buf,2);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].long_cycl_depla = atoi(buf);

		buf = malloc(sizeof(char)*BUF);

		do {
			read(fd2,buf,1);
			lseek(fd2,1,SEEK_CUR);
			if(*buf == '-'){
				lseek(fd2,(-2),SEEK_CUR);
				read(fd2,buf,2);
				lseek(fd2,1,SEEK_CUR);
			}
			invader1[indextype].depH[i] = atoi(buf);
			
			buf = malloc(sizeof(char)*BUF);
			i++;
		}while(i < invader1[indextype].long_cycl_depla);

		
		i = 0;

		do {
			read(fd2,buf,1);
			lseek(fd2,1,SEEK_CUR);
			if(*buf == '-'){
				lseek(fd2,(-2),SEEK_CUR);
				read(fd2,buf,2);
				lseek(fd2,1,SEEK_CUR);
			}
			invader1[indextype].depV[i] = atoi(buf);
			
			buf = malloc(sizeof(char)*BUF);
			i++;
		}while(i < invader1[indextype].long_cycl_depla);

		read(fd2,buf,2);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].life = atoi(buf);

		buf = malloc(sizeof(char)*BUF);

		read(fd2,buf,3);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].freq_tir = atof(buf)*1000;

		buf = malloc(sizeof(char)*BUF);

		read(fd2,buf,1);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].vitesse_tir = atoi(buf);

		read(fd2,buf,1);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].power_shoot = atoi(buf);

		read(fd2,buf,1);
		lseek(fd2,1,SEEK_CUR);
		invader1[indextype].symbol = buf;

		invader1[indextype].data = malloc(sizeof(char) * invader1[indextype].largeur * invader1[indextype].longueur);// creation du champs data par les données de invader

		do{
		    read(fd2,c,1);//recuperation du forme de l invader
		    datainvader(invader1[indextype],cptH,cptL) = c[0];
			cptH++;
		    if(cptH == invader1[indextype].longueur){
				lseek(fd2, 1, SEEK_CUR);
				cptH = 0;
				cptL++;
			}
		} while (cptL < invader1[indextype].largeur);	

		indextype++;
	}

	if(chdir("../niveaux") == -1) {// on ouvre le répertoire niveau pour récupéré les différents parties
    	perror("Impossible d'ouvrir dossier niveaux (menu.c): 3");      
    	sleep(2); 
    	exit(EXIT_FAILURE); 
  	}

	int g = 1; 

	while(g != 4){
		int fd = open(Vmenu[g],O_RDONLY);// ouverture du fichier qui contient le niveau
		InvaderEnn* invaderEnn = init_invaderEnn(fd,invader1);// on stocke le type invader associer au coordonnée
		move(carte,invader1,vitesse,invaderEnn);// on fais les mouvements 
		g++; 
	    invaderEnn = NULL;
	    close(fd);
	}

	if(g == 4){
		exit(EXIT_SUCCESS);
	}

	return 0;
}