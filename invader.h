#ifndef __BRIQUE_H__
#define __BRIQUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>       
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define BUF 1024

typedef struct Invader{//structure Invader
  int largeur, longueur;
  int long_cycl_depla;
  int depH [BUF];
  int depV [BUF];
  int life;
  float freq_tir;
  int vitesse_tir;
  int power_shoot;
  char *symbol;
  char* data;
}Invader;

#define datainvader(invader,i,j) ((invader).data[(j) * (invader).longueur + (i)])//renvoi les données situant dans invader[i][j]

Invader* init_invader(int fd);
void affiche_invader(Invader *c);

#endif
