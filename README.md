# Invader
 * PROJET 2016/2017	UPEC				THIRUCHELVAM Thivagaran
 * Cours Systeme d'exploitation - Mr P.VANIER
 
Pour lancer faire make puis "xterm -ge 100x100 -e ./invader" et lancez le niveau normal :)

La touche "f" met fin au jeu n'importe quand

Pour déplacer le vaisseau joueur utilisées les touches directionnes du clavier : 
Gauche	: "Aller vers la gauche"
Droite	: "Aller vers la droite"
Espace  : "Pour tirer des missiles"

La limite de mon jeu, vous pouvez tirer des missiles et si un des vaisseaux est détruit les autres du même type ne bougent plus alors que les autres types de vaisseaux bougent. Le plus gros problème c'est avec le poll, par exemple quand je bougais le vaisseau joueur avec les touches des claviers les vaisseaux ennemies ne bougaient plus. Après quelques recherchent, j ai trouvé qu il fallait utiliser un gettimeofday et une struct timeval. 


