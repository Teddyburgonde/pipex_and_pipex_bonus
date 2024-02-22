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

8. Cela serait bien d'avoir une petite verif pour voir si il y a bien quelque chose dedans le path vous pensez pas ?

9. La parti un peu difficile c'est de decouper le chemin de maniere qu'il soit exactement comme on veut.
par exemple :
une variable comme cela : 
dbz = /manga/japon/super:/manga/color/red:
et nous on a juste besoin de manga/japon/super/
il faut bien le decouper. ft_split fais cela tres bien.

10. Quand vous avez decouper , il faut tester pour voir si vous avez access , que votre commande est une commande❌
existante.
La fonction access est la pour cela.

11. Bien sur si ce n'est pas un chemin valide , quitte le programme de maniere propre ( gestion leak , message ❌error etc...)

12. Fais un fork pour separer tes processus❌
si pid == -1 on quitte le propramme
si pid == 0 sa sera l'enfant
else sa veut dire qu'on est dans le parent.

13. Dans l'enfant on doit faire les bonnes redirections avec dup2.❌
STDIN_FILENO c'est entrer standard du terminal.
STDOUT_FILENO c'est pour la sorti du terminal. 

14. Utiliser execve permet d'excetuter votre commande.❌
Garder a l'esprit que exerve si elle fonctionne elle ferme le processus en cours ( par exemple l'enfant).
Donc le programme ne lira pas ce qu'il y a apres exerve. 
Si elle fonctionne pas , tout ce qui y a appres sera lu , sa serait une bonne idee de mettre les close et des free apres. 

15. Faites la meme chose avec le processus parent.❌

a toujours garder en tete :
- ./pipex infile cmd1 cmd2 outfile 
- Tout ce qui est ouvert doit etre fermer !
Vous ouvrez 3 fd il faut fermer ses 3 fd.
- Le pipe a deux parti, pipe[0] sa concerne la lecture (quand on veut lire dedans) et le pipe[1] l'ecriture ( c'est quand on veut ecrire dedans).


✅ ❌
 
 
> [!IMPORTANT]
> Source : https://reactive.so/post/42-a-comprehensive-guide-to-pipex
