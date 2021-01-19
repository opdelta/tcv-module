# Reflexion

   ## Description

 Court document sur la réflexion  derrière les prises de décisions.

   ## Auteur

   Ziad Lteif (LTEZ18059802)

   ## Malib.c malib.h

   Les libraires ```malib.h``` et ```malib.c``` contiennent les différentes structures à utiliser dans le cadre du TP. 
   Pour chacune des transactions, j'ai fait un ```typedef``` sur une ```struct``` avec les informations nécessaires sur la transaction.
   (Identification, température humaine, ambiante, pulsations, RSSI et l'échange de données);

   Dans le ```tp2.c```, chaque ligne lue par stdin est envoyée à une méthode qui extrait la signature de celle-ci et la retourne au ```main```. 
   Dès lors, lorsque la signature est retournée, nous savons exactement quelle transaction effectuer. Au début de chaque transaction, on passe en paramètre
   la ligne complète de la signature et un court algorithme extrait les différents arguments nécessaire à la transaction (timestamp, id, etc). 

   Pour ce qui est des transactions ERREUR, la méthode retourne une valeur arbitraire ```-999``` au ```main``` qui comprend alors qu'il faut incrémenter le compteur valeur erreur.
   Pour la troisième occurrence, on ne fait que diviser les compteur par 3. 
   Pour les valeurs invalides, dépendamment de la version, les bonnes méthodes de validation sont utilisés.

   Pour la gestion des timestamps, une variable globale initialisée à 0 contient le dernier timestamp utilisé dans le programme. Lorsqu'une transaction est lue, le programme effectue la comparaison suivante pour chaque transaction:

   ```c
   if (timestamp >= lastStamp) {
       ...
       lastStamp = timestamp;
   }
   ```

   Si la comparaison passe, alors le programme affiche la transaction demandée, sinon elle l'ignore. Si la comparaison passe, on égale ```lastStamp``` avec ```timestamp```.

  ## outil3.c outil3.h
  Pour le TP3, le refactoring du tp2 était de loin la partie la plus longue. J'ai procédé de la même façon que le TP2 pour le TP3. Je me suis cependant rendu compte que je ne pouvais pas utiliser l'entrée en ```stdin``` des données plus d'une fois. J'ai donc enregistré le ```stdin``` dans un ```FILE * input``` que j'utilisais donc pour donner à mes fonctions pour la lecture des informations et le traitement. 