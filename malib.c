//malib.c
#include "malib.h"
#include <stdio.h>
#include <stdlib.h>

Id* getIdentification(int _timestamp, int _signature, float _id, unsigned char _emetteurPow) {

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

TemperatureH* getTemperatureH(int _timestamp, int _signature, float _temp, int _error) {
    TemperatureH *tempH = malloc(sizeof(TemperatureH));
    tempH->timestamp = _timestamp;
    tempH->signature = _signature;
    if (_error == 0) {
        tempH->temp = _temp;
    }

    return tempH;
}

TemperatureA* getTemperatureA(int _timestamp, int _signature, float _temp, int _error) {
    TemperatureA *tempA = malloc(sizeof(TemperatureA));
    tempA->timestamp = _timestamp;
    tempA->signature = _signature;
    if (_error == 0) {
        tempA->temp = _temp;
    }

    return tempA;
}

Pulsation* getPulsation(int _timestamp, int _signature, float _pulse, int _error) {
    Pulsation *pulseParM =malloc(sizeof(Pulsation));
    pulseParM->timestamp = _timestamp;
    pulseParM->signature = _signature;
    if (_error == 0) {
        pulseParM->pulse = _pulse;
    }
   
   return pulseParM;
}

EchangeDonnees* getEchangeDonnees(int _timestamp, int _signature, int _id, int _idpn []) {
    EchangeDonnees *data = malloc(sizeof(EchangeDonnees));
    data->timestamp = _timestamp;
    data->signature = _signature;
    data->id = _id;
    
    return data;
}