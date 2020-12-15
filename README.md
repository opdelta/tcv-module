# Travail pratique 3

![TP3 compilation](https://github.com/opdelta/inf3135-a2020/workflows/test-c/badge.svg)

![TP3 fonctionnel](https://github.com/opdelta/inf3135-a2020/workflows/test-f/badge.svg)


   ## Description

 TCV est un projet d'actualité, qui veut dire : tous contrent le virus (ou les virus). Ce logiciel permet de programmer un module (un Beacon) qui traite de l'information reçue
 et qui réagit en émettant à son tour des transactions.
 
 Le projet est réalisé dans le cadre du cours INF3135 à L'université du Québec à Montréal.

   ## Auteur

   Ziad Lteif (LTEZ18059802)

   ## Fonctionnement
   
Il faut d'abord récupérer le projet. Une fois récupéré, il suffit de lancer les commandes suivantes:

- La première commande est ```make lib```. Cette commande permet d'initialiser le dossier avec les fichiers nécessaires.

- Ensuite, il faut exécuter la commande ```make```. Cette commande permet de compiler le programme et créer un exécutable.

- l'exécutable tp2 prend en entrée standard des transactions et retourne en sortie standard des résultats. 

   ```bash
      $ cat file.dat | ./tp2

      $ ./script.sh | ./tp2

      $ head -n 100 file.txt | ./tp2
      ...
   ```
- 
   ## Contenu du projet

```tp2.c``` Le code source du tp2.

```MakeFile``` Fichier pour l'automatisation des commandes. Voici les cibles:

   - ```make lib``` initialise le dossier avec le programme TCV.

   - ```make clean``` nettoie le dossier pour garder que le nécessaire.
   
   - ```make debug``` compile le tp3.c avec les options de debug.
   
   - ```make``` compile le programme tp3.c pour créer un exécutable.

   - ```make tp3``` compile le programme tp3.c.
   
   - ```make test-tp1a``` lance les tests unitaires et affiche tout à l'écran.

   - ```make test-tp1b``` lance les tests unitaires et affiche les tests qui passent à l'écran.
   
   - ```make test-tp2``` lance le programme principal et prend en stdin les transactions et retourne en stdout les résultats.

```cp.txt```  contient le nom et le code permanent de l'auteur.

```.gitignore``` contient une liste de tous les fichiers à ignorer par Git. (Template utilisé: GitHub)

```README.md``` Contient les informations du répertoire courant.

```.github/workflows/``` Contient les fichiers yaml pour l'automatisation des tests.

- ```malib.c``` et ```malib.h``` contient les librairies ```malib``` en C.

- ```outil3.c``` et ```outil3.h``` contient les librairies ```outil3``` pour le TP3 en C.

   ## Références

   - https://github.com/guyfrancoeur/INF3135_A2020/
   
   - https://www.gnu.org/software/make/manual/make.html#How-Make-Works
   
   - http://cunit.sourceforge.net/doxdocs/group__Framework.html
   
   - https://www.gnu.org/software/make/manual/html_node/Errors.html
   
   
   ## Statut

Les tests unitaires ont cherché à tester chacune des fonctions présentes dans le TCV.h afin de comprendre un peu mieux lesquels sont fonctionnels et lesquels ne sont pas.

Les fonctions fonctionnelles sont les suivantes:
```bash
validerTH_1
validerTA_3
validerPulsation_3
validerSignal_2
```
   Au moins une fonction de chaque passe, ce qui pourrait être essentiel lors de la suite du développement.
   
   Chaque test cherchait à valider les bornes des fonctions, une valeur en plein milieu des bornes et des valeurs à l'extrême. Donc pour chaque test, il y avait à peu près 6 asserts.

Pour le TP2, le projet est complété. Mon livrable prend en considération l'entrée standard que ce soit un fichier fourni en argument ou directement lancé et va analyser chacune des lignes et traiter les commandes. J'ai été en mesure de faire les allocations de mémoire necéssaires pour que les lignes soient lues comme il faut en utilisant par moment un BUFFER_SIZE afin de d'éviter des allocations en trop.

Pour le TP3, les options fonctionnent correctement et aucun bug n'a été décelé lors des tests. Les options supportées sont: ```-d -i -t -s```.

Voici les cas et les traitements en fonction des options : 
 - option `-i` `information invalide`
   + Lorsqu'un code de transaction n'est reconnu;
   + Lorsque le timestamp est inférieur au temps précédent;
 - option `-d` `information détaillée`
   + Le nombre de transactions pour chacun des types de transactions;
 - option `-s` `information sommaire`
   + Le nombre total de transactions valides;
   + Le nombre total de transactions reçues;
 - option `-t` `mode tranquille`
   + Le mode tranquille n'affiche pas transaction en sortie;

[Lien vers le fichier de réflexion]:reflexion.md
