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

   Le TP1 est presque complété.
   
   Section TODO.
   
   ## Réponse
   
   <s'il y a des questions répondre ici>
   
   ## Autoévaluation
   
   <mon travail vaut quelques points en fonction du barème>
