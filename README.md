# PIPEX

> [!IMPORTANT]
> Ce Read-me est regulierement mis a jour
> derniere mise a jour vendredi 23/02/2024 a 11h27

>Faite moi des retours que je puisse rendre plus compressible ce readme. 



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
les deux processus (la dans cette exemple les deux cat) communiquent entre grace au pipe. Sans pipe il n'y a pas de possibilités de faire communiquer deux commandes. 
Vous verrez par la suite que vous devez dire qu'elle commande doit s'excuser avant et qu'elle commande doit attendre l'autre.

❌ 2.la commande a taper dans le terminal c'est : 
./pipex infile cmd1 cmd2 outfile
Donc vous pouvez deja fait une petite verife si le nombre d'argument n'est pas le bon on affiche un
message d'erreur avec un Exit. 

❌ 3. Pour pouvoir utiliser les fichiers il faut donc forcement les ouvrir. 
   Infile on veut juste lire le contenu et outfile on veut pouvoir ecrire dedans,
   le cree si il n'existe pas et eface le contenu avant d'ecrire dedans.
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

# **pipex**

## Introduction

Le projet **pipex** consiste à recréer une partie des fonctionnalités de la commande shell suivante : 

```bash
< infile cmd1 | cmd2 > outfile
```

L'objectif est d'utiliser des concepts de programmation avancés en C, tels que les processus, les redirections, et les pipes. Ce projet permet de mieux comprendre la communication inter-processus.

---

## Fonctionnalités

Votre programme devra être lancé avec les arguments suivants :

```bash
./pipex infile cmd1 cmd2 outfile
```

### Explication
- **infile** : Fichier d'entrée, contenant les données à traiter.
- **cmd1** : Première commande qui lit les données depuis le fichier **infile**.
- **cmd2** : Deuxième commande qui utilise la sortie de **cmd1** comme entrée.
- **outfile** : Fichier de sortie dans lequel les résultats de **cmd2** seront écrits.

### Exemple :
```bash
./pipex infile "cat" "wc -l" outfile
```

---

## Étapes pour réussir le projet

### 1. **Comprendre le fonctionnement de pipex**

Votre programme doit recréer cette commande shell : 
```bash
< infile cmd1 | cmd2 > outfile
```
Voici ce qui se passe :
1. Le fichier **infile** est ouvert et son contenu est envoyé à **cmd1**.
2. La sortie de **cmd1** est redirigée vers **cmd2** grâce à un pipe.
3. Enfin, la sortie de **cmd2** est écrite dans le fichier **outfile**.

---

### 2. **Les fonctions à apprendre**

Vous devez comprendre et utiliser les fonctions suivantes :
- `access`
- `dup2`
- `execve`
- `fork`
- `pipe`
- `wait`
- `exit`

Prenez le temps de lire leur documentation et de tester de petits exemples pour comprendre leur fonctionnement.

---

### 3. **Validation des arguments**

Commencez par vérifier que le programme est appelé avec le bon nombre d'arguments :
```bash
./pipex infile cmd1 cmd2 outfile
```
- Si ce n'est pas le cas, affichez un message d'erreur et terminez le programme proprement.

---

### 4. **Gestion des fichiers**

- **Ouvrir infile et outfile** :
  - **infile** doit être ouvert en lecture seulement.
  - **outfile** doit être ouvert en écriture. S'il n'existe pas, créez-le. S'il existe déjà, écrasez son contenu.
- Gérez les erreurs si l'ouverture de ces fichiers échoue.

---

### 5. **Comprendre les variables d'environnement**

Dans la fonction `main`, vous recevez une variable `envp`. Il s'agit d'un tableau contenant les variables d'environnement du système. 

Imprimez ce tableau pour comprendre son contenu. Recherchez une ligne qui commence par `PATH`, car elle contient les chemins nécessaires pour trouver les exécutables des commandes (`cmd1`, `cmd2`).

---

### 6. **Isoler le chemin PATH**

- Extraire la ligne qui commence par `PATH`.
- Découpez les différents chemins en utilisant `:` comme séparateur.
- Ajoutez un `/` à la fin de chaque chemin pour faciliter la recherche des commandes.

---

### 7. **Vérifier l'accès aux commandes**

- Combinez chaque chemin du `PATH` avec la commande (`cmd1` ou `cmd2`) et utilisez la fonction `access` pour vérifier si la commande existe.
- Gérez les cas où la commande n'est pas valide.

---

### 8. **Créer des processus avec `fork`**

Utilisez `fork` pour créer un processus enfant :
- Si `fork` échoue, terminez le programme proprement.
- Si le processus est un enfant (PID = 0), gérez les redirections (entrée/sortie) et exécutez la commande avec `execve`.
- Si le processus est le parent, attendez la fin de l'exécution de l'enfant avec `wait`.

---

### 9. **Utiliser des pipes pour la communication**

Un pipe est un moyen de communication entre deux processus :
- `pipe[0]` est utilisé pour lire.
- `pipe[1]` est utilisé pour écrire.
- Configurez correctement les redirections avec `dup2` pour relier la sortie de **cmd1** à l'entrée de **cmd2**.

---

### 10. **Exécuter les commandes avec `execve`**

- `execve` remplace le processus en cours par une commande à exécuter.
- Si `execve` fonctionne, elle termine le processus.
- Si elle échoue, affichez une erreur et libérez toutes les ressources avant de quitter.

---

### 11. **Gérer les erreurs et les fuites mémoire**

- Fermez tous les descripteurs de fichiers ouverts.
- Libérez toute mémoire allouée dynamiquement.
- Affichez des messages d'erreur clairs et précis en cas de problème.

---

## Conseils importants

1. **Respectez le format d'appel :**
   ```bash
   ./pipex infile cmd1 cmd2 outfile
   ```
2. **Redirections des pipes :**
   - `pipe[0]` pour la lecture.
   - `pipe[1]` pour l'écriture.
3. **Fermez tout ce que vous ouvrez :**
   - Chaque descripteur de fichier ouvert doit être fermé avant de quitter le programme.

---

## Bonus

Si vous avez terminé la partie obligatoire, ajoutez des fonctionnalités bonus comme :
- Gérer plusieurs pipes (plus de deux commandes).
- Gérer des arguments avec des guillemets ou des espaces.
- Gérer les commandes shell intégrées comme `echo` ou `cd`.

---

## Ressources utiles

- [Documentation sur les pipes](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [Guide sur les processus en C](https://www.geeksforgeeks.org/fork-system-call/)
- [Tutoriel sur execve](https://linux.die.net/man/2/execve)

---

Bonne chance pour votre projet **pipex** ! N'oubliez pas de bien tester votre programme avec différents scénarios pour vérifier sa robustesse.

 
