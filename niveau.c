#include "niveau.h"

InvaderEnn* init_invaderEnn(int fd,Invader* invader1){
	
	char* buf = malloc(sizeof(char)*BUF);
	InvaderEnn* invaderEnn = malloc(sizeof(InvaderEnn));
	
	read(fd,buf,2);
	lseek(fd,1,SEEK_CUR);
	invaderEnn[0].nb_invader = atoi(buf);

	buf = malloc(sizeof(char)*BUF);
   
   for(int i = 1; i <= invaderEnn[0].nb_invader;i++){//on lit le fichier niveau et on associe chaque coordoonée à son type de niveau

	   	read(fd,buf,1);
		lseek(fd,1,SEEK_CUR);
		invaderEnn[i].invader = &invader1[atoi(buf)];
		
		buf = malloc(sizeof(char)*BUF);

		read(fd,buf,1);
		lseek(fd,1,SEEK_CUR);
		invaderEnn[i].temps = atoi(buf);

		read(fd,buf,2);
		lseek(fd,1,SEEK_CUR);
		invaderEnn[i].posx = atoi(buf);

		buf = malloc(sizeof(char)*BUF);

		read(fd,buf,2);
		lseek(fd,1,SEEK_CUR);
		invaderEnn[i].posy = atoi(buf);

		buf = malloc(sizeof(char)*BUF);
   }

	return invaderEnn;
}

