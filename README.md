# PIPEX

### Apprendre les fonctions : 

- access  ❌
- dup2  ❌
- execve  ❌ 
- fork  ❌
- unlink  ❌
- pipe  ❌
- wait  ❌
- Exit  ❌

### Comprendre l'importance de fork dans ce projet 

- Comprendre pourquoi utiliser fork  ❌ 

Commencons : 

1. Comprendre ce que doit faire pipex. ❌
Explication :
./pipex infile cat cat outfile 

Ici le programme vas cat ce qu'il y dans infile (le fichier d'entrer ) et l'autre commande cat va cat ce qui a ete cat dans infile et le met dans outfile. 
les deux cat (les deux processus doivent pouvoir communiquer entre eux 0 et pour cela on utile un pipe. 
Vous verez il y a un ordre dans les excutions des commandes et sur le fait que l'un doit attendre l'autre terminer pour pouvoir s'executer.
Imaginer si tout les cat s'executer en meme temps sa serait un beau bordel. 

2. Garder toujours a l'esprit que la commande a taper dans le terminal c'est : ❌
./pipex infile cmd1 cmd2 outfile
Donc vous pouvez deja fait une petite verife si le nombre d'argument n'est pas le bon on affiche un
message d'erreur avec un Exit  

3. Pour pouvoir utiliser les fichiers il faut donc forcement les ouvrir. ❌
   Infile on est d'accord qu'on veut juste lire le contenu et outfile on veut pouvoir ecrire dedans,
   le cree si il n'existe pas et eface le contenu avant d'ecrire dedans.
Si il y a une erreur dans outfile on fait quoi ?

4. Est ce que tu sais c'est quoi une variable d'environnement ? C'est un fichier system ( un fichier qui ❌ n'est pas stocker sur ton ordi mais plutot sur ton psyteme d'exploitation.
   int main(int argc, char **argv , char *envp[]
Si tu veux voir a quoi sa ressemble sa serait une TRES BONNE IDEE d'imprimer le double tableau envp.

5. Apres l'avoir imprimer vous devez voir pleins de lignes et dans une de ses lignes il y a un chemin qui ❌ il y a un chemin vers le system que vous aurez besoin, celui ou il y a toute les fonctions pour les commandes, comme ls , cat etc...

SHELL=/bin/bash
TERM=xterm
USER=demouser
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca:...
MAIL=/var/mail/demouser
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games
PWD=/home/demouser
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/demouser
LOGNAME=demouser
LESSOPEN=| /usr/bin/lesspipe %s
LESSCLOSE=/usr/bin/lesspipe %s %s
_=/usr/bin/printenv

6. Vous voulez savoir c'est lequel ? A vous de chercher c'est laquel qui vous faut. ❌ 
Ps : Je suis pas loin si vous avez besoin.

7. Quand vous pensez savoir c'est laquel il faut l'isoler , sa serait une bonne idee ou pas a vous de voir
de l'isoler avec par quoi elle commence par exemple.
En effet c'est une seul variable que vous avez besoin. ❌







✅   ❌




a toujours garder en tete :
- ./pipex infile cmd1 cmd2 outfile 
- Tout ce qui est ouvert doit etre fermer !
Vous ouvrez 3 fd il faut fermer ses 3 fd.
- Le pipe a deux parti, pipe[0] sa concerne la lecture (quand on veut lire dedans) et le pipe[1] l'ecriture ( c'est quand on veut ecrire dedans).















EN CONSTRUCTION !!! 







### Creation de la struct 

- Creer la struct  ✅

### Faire un Makefile 

- Makefile ✅

### PARSING

- Verifier si il y a le bon nombres d'arguments   ✅
- Verifier si j'ai le droit d'ouvrir le premier fichier   ✅
- Verifier si j'ai le droit d'ouvrir le deuxieme fichier ✅

### TROUVER LE CHEMIN ET VOIR SI LA COMMANDE EST VALIDE

- Verifier si la commande est valid : ✅
	. trouver si le chemin existe (path envp)  ✅
	. separer le path (ils sont separer par : donc utiliser split) ✅
	. isoler la parti de la commande qu'il me faut ✅
	. Creer une function qui :
		. verifier avec quel parti du path la commande est executable (X_OK) ✅ 
		. rassemble la commande **arg_cmd1 avec le lien corespondant. ✅
		. trouver le chemin executable ✅
		. mettre une valeur dans arg_cmd1[0]✅
		. Mettre la valeur dans arg_cmd2[0] ✅

### Initialiser les arg_cmd

- Initialiser arg_cmd1 ✅
- Initialiser arg_cmd2 ✅

### Envoyer les valeurs aux arg_cmd 

- L'envoyer a arg_cmd1[0] ✅
- L'envoyer a arg_cmd2[0] ✅


### Processus enfant 

- Capture la sortie standard et le mettre dans un tube ✅
- Fermer l'autre bout du tube. ✅
- Le rediriger vers un fichier d'entrée ✅
- La commande argv[2] la decouper en deux et la stock dans un tab ✅
- Verifier si on trouve le bon chemin pour la commande ✅
- Gestion des cas d'erreur ✅
- free + message d'erreur + exit ✅
- Execve (remplace le processus actuel par le nouveau executable, le chemin complet) ✅


### Questions diverses 

- Comprendre pourquoi le l'enfant lis ✅
- Comprendre pourquoi le parent ecris ✅
- Comprendre le processus parent ❌

### BONUS

- Savoir ce que c'est un heredoc ❌
- Faire les bonus ❌

### LEAKS

- Gerer tous les leaks ✅

# NORME 
- Faire la norme : 
	. Decouper mes fonctions ✅

# Testeur

- Valider au testeur ❌

# Gestion divers bugs 

- Find paths cuted ✅
- Init_arg with split ✅
- Refaire le pathfinder ✅
- Refaire le parsing  ✅

   ✅ ❌
 
 
> [!IMPORTANT]
> Source : https://reactive.so/post/42-a-comprehensive-guide-to-pipex
