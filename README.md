# Travail pratique 1

   ## Description

 TCV est un projet d'actualité, qui veut dire : tous contrent le virus (ou les virus). Ce logiciel permet de programmer un module (un Beacon) qui traite de l'information reçue
 et qui réagit en émettant à son tour des transactions.
 
 Le projet est réalisé dans le cadre du cours INF3135 à L'université du Québec à Montréal.

   ## Auteur

   Ziad Lteif (LTEZ18059802)

   ## Fonctionnement
   
Il faut d'abord récupérer le projet. Une fois récupéré, il suffit de lancer les commandes suivantes en ordre:

- La première commande est ```make lib```. Cette commande permet d'initialiser le dossier avec les fichiers nécessaires.

- Ensuite, il faut exécuter la commande ```make```. Cette commande permet de compiler le programme et créer un exécutable.

- Finalement, il suffit de lancer la commande ```make test```. Les tests unitaires devraient s'exécuter et afficher à l'écran un ensemble de tests réussis et échoués.

   ## Contenu du projet

```tp1.c``` Le code source des tests unitaires pour les méthodes fournis du programme TCV.

```MakeFile``` Fichier pour l'automatisation des commandes. Voici les cibles:

   - ```make lib``` initialise le dossier avec le programme TCV.

   - ```make clean``` nettoie le dossier pour garder que le nécessaire.
   
   - ```make``` compile le programme TP1.c pour créer un exécutable.
   
   - ```make test``` lance les tests unitaires et affiche à l'écran uniquement les tests qui réussissent.
   
   - ```cp.txt```  contient le nom et le code permanent de l'auteur.

   - ```.gitignore``` contient une liste de tous les fichiers à ignorer par Git. (Template utilisé: GitHub)

   - ```README.md``` Contient les informations du répertoire courant.

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
   
   ## Réponse
   
   ```Q1:``` Les ordinateurs fonctionne en base de 2 (0 et 1). Un système binaire est plus facile à traiter pour un ordinateur que les coder en base 10. Les décimales sont nocives simplement, car le temps necéssaire pour traiter une valeur décimale en BCD (Binary-coded decimal). Il fonctionne en transformant des séquences binaires de manière à pouvoir être interprêté en base 10 et décimales.
   
   ```Q2:``` Les types de données dont importantes à respecter, car dans le cas contraire, on se retrouve avec un overflow (une surcharge) et des valeurs non voulues peuvent être représentés. Un type de donnée qui supporte que des valeurs de -127 à 127 peut agir de manière non voulue lorsqu'on ne respecte pas son type et qu'on lui passe en paramètre un nombre plus gros ou plus petit. 
   
   ## Autoévaluation
   

| Critère | Sous-critère | Points |
| ------- |:------------ | ------:|
| Fonctionnabilité  | tests seront lancés (comparaison binaire)      | 3.0 |
| Bash              | script qui liste les fonctions parfaites       | 0.5 |
| Compilation       | sans avertissement ni erreur                   | 1.0 |
| Récupération      | récupération sans problème et dépôt privée     | 1.0 |
| Branche (git)     | nommée testunitaire (branche de développement) | 1.0 |
| Makefile          | <ul><li>make</li><li>make clean</li><li>make lib</li><li>make test</li></ul> | <ul><li>0.5</li><li>0.5</li><li>0.5</li><li>0.25</li></ul> |
| Markdown          | README.md                                      | 0.5 |
| Professionnel     | :wink: (simple et sans mystère)                | 0.5 |
| **Total**         |                                                | 9.25  |
