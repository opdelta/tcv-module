#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include "malib.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define BUFFER_SIZE 1000 //Buffer pour une ligne lue

/**
*
* Methode pour imprimer la version courante de la libraire
*
**/
unsigned int printVersion() {
  version_t *v = malloc(sizeof(version_t));
  getVersion(v);
  printf("%s","version #: ");
  printf("%u.",v->major);
  printf("%u.",v->minor);
printf("%u\n",v->build);
  unsigned int versionBuild = v->build;
  free(v);
  return versionBuild;
}
/**
*
* Methode pour retourner la signature de la ligne fournie en parametre.
*
* @param _line Chaine de caracteres a extraire.
**/
char* getTransaction(char _line[]) {
   char *signature;
   signature = calloc(BUFFER_SIZE, sizeof(char));
   if (_line != NULL) {
    signature = strtok(_line, " ");
    signature = strtok(NULL," ");
   }
   return signature;
}
/**
*
* Methode principale pour la gestion de l'identification.
* Alloue un espace memoire pour l'id et affiche a l'ecran les informations
* de l'identifiant de la pastille.
*
* @param _line Chaine de caractere a extraire.
* @return La puissance de l'emetteur de la pastille.
**/
Id* strToId(char _line[]) {
  size_t timestamp = 0;
  size_t signature = 0;
  float id = 0;
  unsigned char pow = 0;
  char* arg = strtok(_line, " ");
  char ** args = NULL;
  int size = 0;
  int i = 0;
  /*Separe la ligne en tokens et les ajoute au tableau dynamique args */
  while (arg) {
    args = realloc (args, sizeof (char*) * ++size);
    args[size-1] = arg;
    arg = strtok(NULL, " ");
  }
  while (i < size) {
    switch(i)
    {
      case 0: //timestamp
        if (args[i] != NULL) {
          timestamp = (size_t)atoi(args[i]);
        }
        break;
      case 1: //signature
        if (args[i] != NULL) {
          signature = (size_t)atoi(args[i]);
        }
        break;
      case 2: //id
        if (args[i] != NULL) {
          id = atof(args[i]);
        }
        break;
      case 3: //puissance emetteur
        if (args[i] != NULL) {
          pow = (unsigned char)strtol(args[i],NULL,10);
        }
        break;
    }
    ++i;
  }
  Id *ident = getIdentification(timestamp, signature, id, pow);
  printf("%d %zu %.0f %d\n", 10, ident->timestamp, ident->id, ident->emetteurPow);
  /* Libere la memoire allouee */
  free (args);
  return ident;
}
/**
*
* Methode pour le calcul de la distance entre deux recepteurs.
*
* @param _signal le signal entre deux pastilles
* @param _pow Puissance de l'emetteur
*
**/
float distanceCalc(signed short _signal, int _pow) {
  float temp1 = -69 - _signal;
  float temp2 = 10 * _pow;
  float temp3 = temp1/temp2;
  float distance = pow(10,temp3);
  return distance;
}
size_t strToRssi(char _line[], int _pow) {
  size_t timestamp = 0;
  size_t signature = 0;
  signed short signal = -69;
  size_t id = 0;
  char* arg = strtok(_line, " ");
  char ** args = NULL;
  int size = 0;
  int i = 0;
  size_t ids = 0;
  /*Separe la ligne en tokens et les ajoute au tableau dynamique args */
  while (arg) {
    args = realloc (args, sizeof (char*) * ++size);
    args[size-1] = arg;
    arg = strtok(NULL, " ");
  }
  while (i < size) {
    switch(i)
    {
      case 0: //timestamp
        if (args[i] != NULL) {
          timestamp = (size_t)atoi(args[i]);
        }
        break;
      case 1: //signature
        if (args[i] != NULL) {
          signature = (size_t)atoi(args[i]);
        }
        break;
      case 2: //signal
        if (args[i] != NULL) {
           signal = (signed short)atoi(args[i]);
        }
        break;
      case 3: //id
        if (args[i] != NULL) {
          id = (size_t)atoi(args[i]);
          ids = id;
        }
        break;
    }
    ++i;
  }
  
  float distance = distanceCalc(signal, _pow);

  RssiSignal *rssi = getrssiSignal(timestamp, signature, signal, id);
  printf("%d %zu %zu %.1f\n", 14, rssi->timestamp, rssi->id, distance);
  
  /* Libere la memoire allouee */
  free (args);
  free(rssi);
  return ids;
}
/**
*
* Methode de gestion des temperatures humaines, ambiantes et les pulsations.
* N'affiche rien a l'ecran, mais retourne les temperatures/pulsations trouvees.
*
* @param _line Ligne a traiter contenant les informations de temperature ou de pulsation
* @return Un float contenant la temperature ou la pulsation trouvee.
*
**/
float strToTemp(char _line[]) {
  char* arg = strtok(_line, " ");
  char ** args = NULL;
  int size = 0;
  float temp = 0;
  /*Separe la ligne en tokens et les ajoute au tableau dynamique args */
  while (arg) {
    args = realloc (args, sizeof (char*) * ++size);
    args[size-1] = arg;
    arg = strtok(NULL, " ");
  }
  if (strlen(args[2]) > 6) { //Si l'argument 2 est "ERREUR"
    temp = -999;
  } else {
    temp = atof(args[2]);
  }
  free(args);
  return temp;
}
/**
*
* Methode qui calcule la moyenne.
*
* @param _fullTemp La somme de tous les elements
* @param _count Le nombre total d'elements
* @return La moyenne en float
*
**/

float average(float _fullTemp, int _count) {
  float av = _fullTemp/_count;
  return av;
}
/**
*
* Methode qui affiche les moyennes des temperatures humaines et ambiantes ainsi que la pulsation.
*
* @param _mTH Moyenne des temperatures humaines
* @param _mTA Moyenne des temperatures ambiantes
* @param _mPul Moyenne des pulsations
**/
void displayAverages(float _mTH, float _mTA, size_t _mPul) {
  printf("%d %.1f %.1f %zu\n", 21, _mTH, _mTA, _mPul);
}
/**
*
* Methode qui affiche le nombre d'entrees invalides de temperature humaines et ambiante ainsi que le pulsation.
*
* @param _trans Numero de transaction a afficher
* @param _invTH Nombre de temperature humaine invalides
* @param _invTA Nombre de temperature ambiante invalides
* @param _invPul NOmbre de pulsations invalides
*/
void displayError(int _trans, size_t _invTH, size_t _invTA, size_t _invPul) {
  printf("%d %zu %zu %zu\n", _trans, _invTH/3, _invTA/3, _invPul/3);
}

/**
*
* Methode principale pour la gestion des contacts des pastilles (les echanges de donnees).
* La methode affiche a l'ecran les donnees echangees.
*
* @param _line Ligne contenant les informations d'echanges
*
**/
void strToData(char _line[], Id* _ident, size_t _idpn[]) {
  char* arg = strtok(_line, " ");
  char ** args = NULL;
  int size = 0;
  int i = 0;
  size_t signature;
  size_t timestamp;
  size_t id;
  
  /*Separe la ligne en tokens et les ajoute au tableau dynamique args */
  while (arg) {
    args = realloc (args, sizeof (char*) * ++size);
    args[size-1] = arg;
    arg = strtok(NULL, " ");
  }
  while (i < size) {
    switch(i)
    {
      case 0: //timestamp
        if (args[i] != NULL) {
          timestamp = (size_t)atoi(args[i]);
        }
        break;
      case 1: //signature
        if (args[i] != NULL) {
          signature = (size_t)atoi(args[i]);
        }
        break;
      case 2: //id
        if (args[i] != NULL) {
          id = (size_t)atoi(args[i]);
        }
        break;
    }
    ++i;
  }
  EchangeDonnees *data = getEchangeDonnees(timestamp, signature, id, NULL);
  printf("%d %zu %zu", 15, data->timestamp, (size_t)_ident->id);
  for (int j = 0; j < 2; ++j) {
    printf(" %ld", _idpn[j]);
  }
/*Libere l'allocation de memoire pour les donnees*/
  free(data);
}



int main(int _argc, char **_argv) {
  unsigned int ver = printVersion();
  int build = 0;
  if (ver > 1003) {
    build = 1;
  }
  char line[BUFFER_SIZE];
  char* signature;
  char fullLine[BUFFER_SIZE];
  Id* ident;
  int pow = 2;
  int tempHCount = 0;
  int tempACount = 0;
  int pulseCount = 0;
  size_t errHCount = 0;
  size_t errACount = 0;
  size_t errPCount = 0;
  size_t invHCount = 0;
  size_t invACount = 0;
  size_t invPCount = 0;
  float fullTempH = 0;
  float fullTempA = 0;
  float fullPulse = 0;
  int nbIdpn = 0;
  size_t idpn[2];
  signature = calloc(BUFFER_SIZE, sizeof(char));
  while (fgets(line, BUFFER_SIZE, stdin) != NULL) {
      if (line != NULL) {
        strcpy(fullLine, line);
        signature = getTransaction(line);
      } else {
        break;
      }
      if (signature != NULL) {
        if(strcmp(signature, "00") == 0) { //Signature identification
          ident = strToId(fullLine);
          pow = ident->emetteurPow;
        //End signature identification
        } else if(strcmp(signature, "01") == 0) { //Signature temperatureH
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errHCount++;
          } else {
            if (validerTH_1((int)temp)) {
              tempHCount++;
              fullTempH += temp;
            } else {
              invHCount++;
            }
            
          }
        //End signature TemperatureH
        } else if(strcmp(signature, "02") == 0) { //Signature temperatureA
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errACount++;
          } else {
            if(build == 0) {
              if (validerTA_3((short)temp)) {
                tempACount++;
                fullTempA += temp;
              } else {
                invACount++;
              }
            } else {
              if (validerTA_1((int)temp)) {
                tempACount++;
                fullTempA += temp;
              } else {
                invACount++;
              }
            }
          }
        //End signature temperatureA
        } else if(strcmp(signature, "03") == 0) { //Signature pulsation
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errPCount++;
          } else {
            if (build == 0) {
              if (validerPulsation_3((short)temp)) {
                pulseCount++;
                fullPulse += temp;
              } else {
                invPCount++;
              }
            } else {
               if(validerPulsation_1((int)temp)) {
                   pulseCount++;
                   fullPulse+=temp;
                } else {
                  invPCount++;
                }
            }
          }
        //End signature pulsation
        } else if(strcmp(signature, "04") == 0) { //Signature RSSI
          idpn[nbIdpn] = strToRssi(fullLine, pow);
          ++nbIdpn;

        //End signature RSSI
        } else if(strcmp(signature, "05") == 0) { //Signature data
          strToData(fullLine, ident, idpn);
        //End signature data
        }
      }
  }
  printf("%s","\n");
  displayAverages(fullTempH, fullTempA, fullPulse);
  displayError(22, errHCount, errACount, errPCount);
  printf("%d %zu %zu %zu\n", 23, invHCount, invACount, invPCount);
  free(ident);
  return 0;
}
