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
    details->trx01 = _trx1;
    details->trx02 = _trx2;
    details->trx03 = _trx3;
    details->trx04 = _trx4;
    details->trx05 = _trx5;
    return details;
}
float distance(int _signal, int _pow) {
  float temp1 = -69 - _signal;
  float temp2 = 10 * _pow;
  float temp3 = temp1/temp2;
  float distance = pow(10,temp3);
  return distance;
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

DetailTrx* infoDetailTrx(int _argc, FILE* fp) {
    char* line;
    line = calloc(BUFFER_SIZE, sizeof(char));
    char* signature;
    char fullLine[BUFFER_SIZE];
    size_t trxNb[5] = {0,0,0,0,0}; //trxNb[0] = trx 01, trxNb[1] = trx 02, trxNb[2] = trx 03, trxNb[3] = trx 04, trx[4] = trx 05
    signature = calloc(BUFFER_SIZE, sizeof(char));
    char* (*pt)(char []) = &getTransaction;
    while (fgets(line, BUFFER_SIZE, fp) != NULL) {
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