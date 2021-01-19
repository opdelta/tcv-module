#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "tcv.h"
#include "outil3.h"
#include <stddef.h>
#include "malib.h"
#define BUFFER_SIZE 1000
DetailTrx* getDetailsTrx(size_t _trx1, size_t _trx2, size_t _trx3, size_t _trx4, size_t _trx5) {
    DetailTrx *details = malloc(sizeof(DetailTrx));
    details->trx01 = _trx1;details->trx02 = _trx2;details->trx03 = _trx3;details->trx04 = _trx4;details->trx05 = _trx5;
    return details;
}
Stamps* getStamps(size_t _nsst, size_t _lsr, size_t _nrTrx) {
    Stamps* stamp = malloc(sizeof(Stamps));
    stamp->nonSeqStamps = _nsst;stamp->lastStampRead = _lsr;stamp->nrTrx = _nrTrx;
    return stamp;
}
float distance(int _signal, int _pow) {
  float temp1 = -69 - _signal;float temp2 = 10 * _pow;float temp3 = temp1/temp2;
  float distance = pow(10,temp3);
  return distance;
}
TrxNb* getTotalTrx(size_t _totalTrx, size_t _validTrx) {
    TrxNb* trx = malloc(sizeof(TrxNb));
    trx->totalTrx = _totalTrx;
    trx->validTrx = _validTrx;
    return trx;
}
int cmd(char* arg) {
    if (strcmp(arg, "-d") != 0 && strcmp(arg, "-i") != 0 && strcmp(arg, "-t") != 0 && strcmp(arg, "-s") != 0) {
        return -1;
    } else {
        if (strcmp(arg, "-d") == 0) {
            return 0;
        } else if (strcmp(arg, "-i") == 0) {
            return 1;
        } else if (strcmp(arg, "-t") == 0) {
            return 2;
        } else {
            return 3;
        }
    }
}

TrxNb* getNbTrx(unsigned int _ver, FILE* _input) {
    char* line; char* signature; signature = calloc(BUFFER_SIZE, sizeof(char)); char* (*pt)(char []) = &getTransaction; float (*pf)(size_t, char[]) = &strToTemp;
    int build = 0; line = calloc(BUFFER_SIZE, sizeof(char)); size_t totalTrx = 0; size_t validTrx = 0; char fullLine[BUFFER_SIZE]; size_t lastStamp = 0; float temp = 0;
    if (_ver > 1003) build = 1;
    while (fgets(line, BUFFER_SIZE, _input) != NULL) {
        if (line != NULL) {
            strcpy(fullLine,line);
            signature = (*pt)(line);
        } else {
            break;
        }
        totalTrx++;
        switch (atoi(signature)) {
            case 0: validTrx++; break;
            case 1: temp = (*pf)(lastStamp, fullLine);
                if (!(temp == -999) && temp != -1000) {
                    if (validerTH_1((int)temp*10)) validTrx++;
                }
                break;
            case 2: temp = (*pf)(lastStamp, fullLine);
                if (!(temp == -999) && temp != -1000) {
                    switch(build) 
                    {
                    case 0:
                        if (validerTA_3((short)temp)) validTrx++;
                    break;
                    default: 
                        if (validerTA_1((int)temp)) validTrx++;
                    }
                }
                break;
            case 3: temp = (*pf)(lastStamp, fullLine);
                if (!(temp == -999) && temp != -1000) {
                    if (build == 0) {
                        if (validerPulsation_3((short)temp)) validTrx++;
                    } else {
                        if(validerPulsation_1((int)temp)) validTrx++;
                    }
                }
                break;
            case 4: validTrx++; break;
            case 5: validTrx++; break;
        }
    }
    TrxNb* trxStruct = getTotalTrx(totalTrx, validTrx);
    return trxStruct;
}
Stamps* getInfoStamp(FILE* _input) {
    size_t arr[4] = {0, 0, 0, 0}; //arr[0] = nonSeqStamp arr[1] = lastStampRead arr[2] = all stamps arr[3] = nrTrx
    char* line; Stamps* stamp = NULL; line = calloc(BUFFER_SIZE, sizeof(char)); char *signature; signature = calloc(BUFFER_SIZE, sizeof(char)); char* (*pt)(char []) = &getTransaction;
    char* sign; sign = calloc(BUFFER_SIZE, sizeof(char)); char fullLine[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, _input) != NULL) {
        if (line != NULL) {
            strcpy(fullLine, line);
            signature = strtok(line, " ");
            sign = (*pt)(fullLine);
        } else {
            break;
        }
        if (atoi(signature) >= 0) arr[2] = arr[2]+1;
        if (!(atoi(signature) >= arr[1])) arr[0] = arr[0] + 1;
        if (atoi(sign) < 0 || atoi(sign) > 5) arr[3] = arr[3] + 1;
        arr[1] = (size_t)(atoi(signature));
    }
    stamp = getStamps(arr[0],arr[1], arr[3]);
    return stamp;
}

DetailTrx* infoDetailTrx(int _argc, FILE* _fp) {
    char* line; line = calloc(BUFFER_SIZE, sizeof(char)); char* signature; char fullLine[BUFFER_SIZE];
    size_t trxNb[5] = {0,0,0,0,0}; //trxNb[0] = trx 01, trxNb[1] = trx 02, trxNb[2] = trx 03, trxNb[3] = trx 04, trx[4] = trx 05
    signature = calloc(BUFFER_SIZE, sizeof(char)); char* (*pt)(char []) = &getTransaction;
    while (fgets(line, BUFFER_SIZE, _fp) != NULL) {
        if (line != NULL) {
            strcpy(fullLine, line);
            signature = (*pt)(line);
        } else {
            break;
        } //End line
            switch (atoi(signature))
            {
                case 1: trxNb[0] = trxNb[0] + 1; break;
                case 2: trxNb[1] = trxNb[1] + 1; break;
                case 3: trxNb[2] = trxNb[2] + 1; break;
                case 4: trxNb[3] = trxNb[3] + 1; break;
                case 5: trxNb[4] = trxNb[4] + 1; break;
            }
    }
        DetailTrx* details = getDetailsTrx(trxNb[0],trxNb[1],trxNb[2],trxNb[3],trxNb[4]);
        return details;
}