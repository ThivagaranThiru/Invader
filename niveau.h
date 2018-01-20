#ifndef __NIVEAU_H__
#define __NIVEAU_H__


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include "invader.h"

#define BUF 1024

typedef struct InvaderEnn{
  int nb_invader;
  Invader* invader;
  int temps;
  int posx, posy;
}InvaderEnn;

InvaderEnn* init_invaderEnn(int fd, Invader* invader);
#endif