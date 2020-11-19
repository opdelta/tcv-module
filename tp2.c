#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include "malib.h"
#include <math.h>
#include <string.h>
#include <stddef.h>

#define BUFFER_SIZE 1000
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

char* getTransaction(char _line[]) {
   char *signature;
   signature = calloc(BUFFER_SIZE, sizeof(char));
   if (_line != NULL) {
    signature = strtok(_line, " ");
    signature = strtok(NULL," ");
   }
   return signature;
}
int strToId(char _line[]) {
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
      case 0:
        if (args[i] != NULL) {
          timestamp = (size_t)atoi(args[i]);
        }
        break;
      case 1:
        if (args[i] != NULL) {
          signature = (size_t)atoi(args[i]);
        }
        break;
      case 2:
        if (args[i] != NULL) {
          id = atof(args[i]);
        }
        break;
      case 3:
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
  free(ident);
  return pow;
}
float distanceCalc(signed short _signal, int _pow) {
  float temp1 = -69 - _signal;
  float temp2 = 10 * _pow;
  float temp3 = temp1/temp2;
  float distance = pow(10,temp3);
  return distance;
}
void strToRssi(char _line[], int _pow) {
  size_t timestamp = 0;
  size_t signature = 0;
  signed short signal = -69;
  size_t id = 0;
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
      case 0:
        if (args[i] != NULL) {
          timestamp = (size_t)atoi(args[i]);
        }
        break;
      case 1:
        if (args[i] != NULL) {
          signature = (size_t)atoi(args[i]);
        }
        break;
      case 2:
        if (args[i] != NULL) {
           signal = (signed short)atoi(args[i]);
        }
        break;
      case 3:
        if (args[i] != NULL) {
          id = (size_t)atoi(args[i]);
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
}
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
  if (strlen(args[2]) > 6) {
    temp = -999;
  } else {
    temp = atof(args[2]);
  }
  free(args);
  return temp;
}

float average(float _fullTemp, int _count) {
  float av = _fullTemp/_count;
  return av;
}

void displayAverages(float _mTH, float _mTA, size_t _mPul) {
  printf("%d %.1f %.1f %zu\n", 21, _mTH, _mTA, _mPul);
}
void displayError(int _trans, size_t _invTH, size_t _invTA, size_t _invPul) {
  printf("%d %zu %zu %zu\n", _trans, _invTH/3, _invTA/3, _invPul/3);
}


void strToData(char _line[]) {
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
      case 0:
        if (args[i] != NULL) {
          timestamp = (size_t)atoi(args[i]);
        }
        break;
      case 1:
        if (args[i] != NULL) {
          signature = (size_t)atoi(args[i]);
        }
        break;
      case 2:
        if (args[i] != NULL) {
          id = (size_t)atoi(args[i]);
        }
        break;
    }
    ++i;
  }
  EchangeDonnees *data = getEchangeDonnees(timestamp, signature, id, NULL);
  printf("%d %zu %zu %zu", 15, data->timestamp, data->signature, data->id);
  for (int j = 3; j < size; ++j) {
    printf(" %s", args[j]);
  }
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
          pow = strToId(fullLine);
        //End signature identification
        } else if(strcmp(signature, "01") == 0) { //Signature temperatureH
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errHCount++;
          } else {
            if (validerTH_1((int)temp) == 0) {
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
            }
          }
        //End signature pulsation
        } else if(strcmp(signature, "04") == 0) { //Signature RSSI
          strToRssi(fullLine, pow);
        //End signature RSSI
        } else if(strcmp(signature, "05") == 0) { //Signature data
          strToData(fullLine);
        //End signature data
        }
      }
  }
  displayAverages(fullTempH, fullTempA, fullPulse);
  displayError(22, errHCount, errACount, errPCount);
  displayError(23, invHCount, invACount, invPCount);
  return 0;
}
