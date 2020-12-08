#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include "malib.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
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
  size_t timestamp = 0;
  size_t signature = 0;
  float id = 0;
  unsigned char pow = 0;
  int i = 0;
  char** args = strToArray(_line);
  if (args[0] != NULL) {
    timestamp = (size_t)atoi(args[i]);
  }
  if (args[1] != NULL) {
    signature = (size_t)atoi(args[i]);
  }
  if (args[2] != NULL) {
    id = atof(args[i]);
  }
  if (args[3] != NULL) {
    pow = (unsigned char)strtol(args[i],NULL,10);
  }
  Id *ident = getIdentification(timestamp, signature, id, pow);
  if (timestamp >= lastStamp) {
    printf("%d %zu %.0f %d\n", 10, ident->timestamp, ident->id, ident->emetteurPow);
    lastStamp = timestamp;
  }
  free (args);
  return ident;
}
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
  char** args = strToArray(_line);
  int i = 0;
  size_t ids = 0;
  if (args[0] != NULL) {
    timestamp = (size_t)atoi(args[i]);
  }
  if (args[1] != NULL) {
    signature = (size_t)atoi(args[i]);
  }
  if (args[2] != NULL) {
    signal = (signed short)atoi(args[i]);
  }
  if (args[3] != NULL) {
    id = (size_t)atoi(args[i]);
    ids = id;
  }
  float distance = distanceCalc(signal, _pow);
  RssiSignal *rssi = getrssiSignal(timestamp, signature, signal, id);
  if (timestamp >= lastStamp) {
    printf("%d %zu %zu %.1f\n", 14, rssi->timestamp, rssi->id, distance);
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
float average(float _fullTemp, int _count) {
  float av = _fullTemp/_count;
  return av;
}

void strToData(char _line[], Id* _ident, size_t _idpn[]) {
  char** args = strToArray(_line);
  int i = 0;
  size_t signature;
  size_t timestamp;
  size_t id;
  if (args[0] != NULL) {
    timestamp = (size_t)atoi(args[i]);
  }
  if (args[1] != NULL) {
    signature = (size_t)atoi(args[i]);
  }
  if (args[2] != NULL) {
    id = (size_t)atoi(args[i]);
  }
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

