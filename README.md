# Travail pratique 3

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
   
   - ```make``` compile le programme tp2.c pour créer un exécutable.
   
   - ```make test-tp1a``` lance les tests unitaires et affiche tout à l'écran.

   - ```make test-tp1b``` lance les tests unitaires et affiche les tests qui passent à l'écran.
   
   - ```make test-tp2``` lance le programme principal et prend en stdin les transactions et retourne en stdout les résultats.

   - ```cp.txt```  contient le nom et le code permanent de l'auteur.

   - ```.gitignore``` contient une liste de tous les fichiers à ignorer par Git. (Template utilisé: GitHub)

   - ```README.md``` Contient les informations du répertoire courant.

   - ```.github/workflows/tp2.yml``` Contient le fichier yaml pour l'automatisation des tests.

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


[Lien vers le fichier de réflexion]:reflexion.md
