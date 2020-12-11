#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include "malib.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "outil3.h"
#define BUFFER_SIZE 1000 //Buffer pour une ligne lue
size_t lastStamp = 0;
char** strToArray(char* _line) {
    char* arg = strtok(_line, " ");
    int size = 0;
    char ** args = NULL;
    while (arg) {
        args = realloc (args, sizeof (char*) * ++size);
        args[size-1] = arg;
        arg = strtok(NULL, " ");
    }
    return args;
}
Id* getIdentification(size_t _timestamp, size_t _signature, float _id, unsigned char _emetteurPow) {
    if (_id == 0) {
        _id = 9999;
    }
    if (_emetteurPow == 0) {
        _emetteurPow = 2;
    }
    Id *identification = malloc(sizeof(Id));
    identification->timestamp = _timestamp;
    identification->signature = _signature;
    identification->id = _id;
    identification->emetteurPow = _emetteurPow;
    return identification;
}
TemperatureH* getTemperatureH(size_t _timestamp, size_t _signature, float _temp, int _error) {
    TemperatureH *tempH = malloc(sizeof(TemperatureH));
    tempH->timestamp = _timestamp;
    tempH->signature = _signature;
    if (_error == 0) {
        tempH->temp = _temp;
    }
    return tempH;
}
TemperatureA* getTemperatureA(size_t _timestamp, size_t _signature, float _temp, int _error) {
    TemperatureA *tempA = malloc(sizeof(TemperatureA));
    tempA->timestamp = _timestamp;
    tempA->signature = _signature;
    if (_error == 0) {
        tempA->temp = _temp;
    }
    return tempA;
}
Pulsation* getPulsation(size_t _timestamp, size_t _signature, float _pulse, int _error) {
    Pulsation *pulseParM =malloc(sizeof(Pulsation));
    pulseParM->timestamp = _timestamp;
    pulseParM->signature = _signature;
    if (_error == 0) {
        pulseParM->pulse = _pulse;
    }
   return pulseParM;
}
EchangeDonnees* getEchangeDonnees(size_t _timestamp, size_t _signature, size_t _id, size_t _idpn []) {
    EchangeDonnees *data = malloc(sizeof(EchangeDonnees));
    data->timestamp = _timestamp;
    data->signature = _signature;
    data->id = _id;
    return data;
}
RssiSignal* getrssiSignal(size_t _timestamp, size_t _signature, signed short _signalRSSI, size_t _id) {
    RssiSignal *rssi = malloc(sizeof(RssiSignal));
    rssi->timestamp = _timestamp;
    rssi->signature = _signature;
    rssi->signalRSSI = _signalRSSI;
    rssi->id = _id;
    return rssi;
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
Id* strToId(char _line[]) {
  char** args = strToArray(_line);
  size_t timestamp = (size_t)atoi(args[0]);
  size_t signature = (size_t)atoi(args[1]);
  float id = atof(args[2]);
  unsigned char pow = (unsigned char)strtol(args[3],NULL,10);
  Id *ident = getIdentification(timestamp, signature, id, pow);
  if (timestamp >= lastStamp) {
    printf("%d %zu %.0f %d\n", 10, ident->timestamp, ident->id, ident->emetteurPow);
    lastStamp = timestamp;
  }
  free (args);
  return ident;
}
size_t strToRssi(char _line[], int _pow) {
  signed short signal = -69;
  char** args = strToArray(_line);
  size_t timestamp = (size_t)atoi(args[0]);
  size_t signature = (size_t)atoi(args[1]);
  signal = (signed short)atoi(args[2]);
  size_t id = (size_t)atoi(args[3]);
  size_t ids = id;
  float (*pt)(int, int) = &distance;
  float dist = (*pt)((int)signal, _pow);
  RssiSignal *rssi = getrssiSignal(timestamp, signature, signal, id);
  if (timestamp >= lastStamp) {
    printf("%d %zu %zu %.1f\n", 14, rssi->timestamp, rssi->id, dist);
    lastStamp = timestamp;
  }
  free (args);
  free(rssi);
  return ids;
}
float strToTemp(char _line[]) {
  char** args = strToArray(_line);
  float temp = 0;
  if (strlen(args[2]) > 6) { //Si l'argument 2 est "ERREUR"
    temp = -999;
  } else {
    temp = atof(args[2]);
  }
  if ((size_t)atoi(args[0]) < lastStamp) {
    temp = -1000;
  }
  free(args);
  return temp;
}
void strToData(char _line[], Id* _ident, size_t _idpn[]) {
  char** args = strToArray(_line);
  size_t signature = (size_t)atoi(args[1]);
  size_t timestamp = (size_t)atoi(args[0]);
  size_t id = (size_t)atoi(args[3]);
  EchangeDonnees *data = getEchangeDonnees(timestamp, signature, id, NULL);
  if (timestamp >= lastStamp) {
    printf("%d %zu %zu", 15, data->timestamp, (size_t)_ident->id);
    for (int j = 0; j < 2; ++j) {
      printf(" %ld", _idpn[j]);
    }
    lastStamp = timestamp;
  }
  free(data);
}
unsigned int printVersion() {
  version_t *v = malloc(sizeof(version_t));
  getVersion(v);
  printf("%s%u.%u.%u\n","version #: ",v->major,v->minor,v->build);
  unsigned int versionBuild = v->build;
  free(v);
  return versionBuild;
}
int main1(int _argc, char **_argv) {
    unsigned int ver = printVersion();
  int build = 0;
  if (ver > 1003) {
    build = 1;
  }
  char line[BUFFER_SIZE];
  char* signature;
  char fullLine[BUFFER_SIZE];
  Id* ident = NULL;
  int pow = 2;
  int nbIdpn = 0;
  size_t idpn[2];
  size_t errs[6] = {0,0,0,0,0,0}; //0 = errHCount, 1 = errACount, 2 = errPCount, 3 = invHCount, 4 = invACount, 5 = invPCount
  int tempCounts[3] = {0,0,0}; //0 = tempHCount, 1 = tempACount, 2 = pulseCount
  float fullTemps[3] = {0,0,0}; //0 = fullTempH, 1 = fullTempA, 2 = fullPulse
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
        } else if(strcmp(signature, "01") == 0) { //Signature temperatureH
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errs[0] = errs[0] + 1;
          } else if (temp != -1000) {
            if (temp < 100) {
              if (validerTH_1((int)temp*10)) {
              tempCounts[0] = tempCounts[0] + 1;
              fullTemps[0] += temp;
              } else {
                errs[3] = errs[3] + 1;
              }
            } else {
              if (validerTH_1((int)temp)) {
               tempCounts[0] = tempCounts[0] + 1;
                fullTemps[0] += temp;
              } else {
              errs[3] = errs[3] + 1;
              }
            }
          }
        } else if(strcmp(signature, "02") == 0) { //Signature temperatureA
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errs[1] = errs[1] + 1;
          } else if (temp != -1000) {
            if(build == 0) {
              if (validerTA_3((short)temp)) {
                tempCounts[1] = tempCounts[1] + 1;
                fullTemps[1] += temp;
              } else {
                errs[4] = errs[4] + 1;
              }
            } else {
              if (validerTA_1((int)temp)) {
                tempCounts[1] = tempCounts[1] + 1;
                fullTemps[1] += temp;
              } else {
                errs[4] = errs[4] + 1;
              }
            }
          }
        } else if(strcmp(signature, "03") == 0) { //Signature pulsation
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errs[2] = errs[2] + 1;
          } else if (temp != -1000) {
            if (build == 0) {
              if (validerPulsation_3((short)temp)) {
                tempCounts[2] = tempCounts[2] + 1;
                fullTemps[2] += temp;
              } else {
                errs[5] = errs[5] + 1;
              }
            } else {
                if(validerPulsation_1((int)temp)) {
                  tempCounts[2] = tempCounts[2] + 1;
                  fullTemps[2] += temp;
                } else {
                  errs[5] = errs[5] + 1;
                }
            }
          }
        } else if(strcmp(signature, "04") == 0) { //Signature RSSI
          size_t(*pt)(char [], int) = &strToRssi;
          idpn[nbIdpn] = (*pt)(fullLine, pow);
          ++nbIdpn; //End signature RSSI
        } else if(strcmp(signature, "05") == 0) { //Signature data
          strToData(fullLine, ident, idpn);
        } //End signature data
      }
  }
  printf("\n%d %.1f %.1f %.1f\n", 21, fullTemps[0]/tempCounts[0], fullTemps[1]/tempCounts[1], fullTemps[2]/tempCounts[2]);
  printf("%d %zu %zu %zu\n", 22, errs[0]/3, errs[1]/3, errs[2]/3);
  printf("%d %zu %zu %zu\n", 23, errs[3], errs[4], errs[5]);
  free(ident);
  return 0;
}