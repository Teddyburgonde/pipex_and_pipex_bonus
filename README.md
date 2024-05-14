# PIPEX

> [!IMPORTANT]
> Ce Read-me est regulierement mis a jour
> derniere mise a jour vendredi 23/02/2024 a 11h27

>Faites-moi des retours que je puisse rendre plus comprehensible ce readme. 



### Apprendre les fonctions : 

- access  ❌
- dup2  ❌
- execve  ❌ 
- fork  ❌
- unlink  ❌
- pipe  ❌
- wait  ❌
- Exit  ❌

### Commencons : 

 ❌ 1. Comprendre ce que doit faire pipex. 
Explication :
./pipex infile cat cat outfile 

Ici, le programme va cat ce qu'il y dans infile (le fichier d'entrer) et l'autre commande cat va  recuperer ce qui a été cat au début dans infile et il le redirigeait dans outfile. 
les deux processus (la dans cette exemple les deux cat) communiquent entre eux grace au pipe. Sans pipe il n'y a pas de possibilités de faire communiquer deux commandes. 
Vous verrez par la suite que vous devez dire quelle commande doit s'excuser avant et quelle commande doit attendre l'autre.

❌ 2.la commande a taper dans le terminal c'est : 
./pipex infile cmd1 cmd2 outfile
Donc vous pouvez deja fait une petite verife si le nombre d'argument n'est pas le bon on affiche un
message d'erreur avec un Exit. 

❌ 3. Pour pouvoir utiliser les fichiers il faut donc forcement les ouvrir. 
   Infile on veut juste lire le contenu et outfile on veut pouvoir ecrire dedans,
   le cree s'il n'existe pas et effacer le contenu avant d'ecrire dedans.
Si il y a une erreur dans outfile on fait quoi ?

❌ 4. Une variable d'environnement ? C'est un fichier system ( un fichier qui n'est pas stocker sur ton ordi mais plutot sur ton systeme d'exploitation.
   int main(int argc, char **argv , char *envp[]
Si tu veux voir a quoi sa ressemble sa serait une TRES BONNE IDEE d'imprimer le double tableau envp.

❌ 5. Vous devez voir pleins de lignes et dans une de ses lignes il y a le chemin fichier que vous aurez besoin, celui ou il y a toute les fonctions pour les commandes, comme ls , cat etc...

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

❌ 6. Vous voulez savoir c'est lequel ? A vous de chercher =). 
Ps : Je suis pas loin si vous avez besoin.

❌ 7. Vous l'avez trouver ? Alors isoler la ! Peut etre que strncmp peut faire cela.

❌ 8. Cela serait bien d'avoir une petite verif pour voir si il y a bien quelque chose dedans le path vous pensez pas ?

❌ 9. La parti un peu difficile c'est de decouper le chemin de maniere qu'il soit exactement comme on veut.
par exemple :
une variable comme cela : 
dbz = /manga/japon/super:/manga/color/red:
et nous on a juste besoin de manga/japon/super/
il faut bien le decouper et ajouter le petit baton "/". ft_split et ft_strjoin font cela tres bien. 

❌ 10. Fini le decoupage ? tester pour voir si vous avez access , que votre commande est une commande
existante.
La fonction access est la pour cela.

❌ 11. Bien sur si ce n'est pas un chemin valide , quitte le programme de maniere propre ( gestion leak , message error etc...)

❌ 12. Fais un fork pour separer tes processus
si pid == -1 on quitte le propramme
si pid == 0 sa sera l'enfant
else sa veut dire qu'on est dans le parent.

❌ 13. Dans l'enfant on doit faire les bonnes redirections avec dup2.
STDIN_FILENO c'est entrer standard du terminal.
STDOUT_FILENO c'est pour la sorti du terminal. 

❌ 14. Utiliser execve permet d'excetuter votre commande.
Garder a l'esprit que exerve si elle fonctionne elle ferme le processus en cours ( par exemple l'enfant).
Donc le programme ne lira pas ce qu'il y a apres exerve. 
Si elle fonctionne pas , tout ce qui y a appres sera lu , sa serait une bonne idee de mettre les close et des free apres. 

❌ 15. Faites la meme chose avec le processus parent.

a toujours garder en tete :
- ./pipex infile cmd1 cmd2 outfile 
- Tout ce qui est ouvert doit etre fermer !
Vous ouvrez 3 fd il faut fermer ses 3 fd.
- Le pipe a deux parti, pipe[0] sa concerne la lecture (quand on veut lire dedans) et le pipe[1] l'ecriture ( c'est quand on veut ecrire dedans).


✅ ❌
 
 
