#include "malib.h"
#include "outil3.h"
#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define BUFFER_SIZE 1000
int main(int _argc, char **_argv) {
    unsigned int ver = 0; char in[BUFFER_SIZE]; int fD = 0, fI = 0, fT = 0, fS = 0, fE = 0;size_t lastStampRead = 0;
    if (_argc > 5) { 
        fE = 1; 
        fprintf(stderr, "\nErreur dans les arguments. 4 arguments maximum. Arguments valides: -d -i -t -s\n");
        return -1;  
    } else {
        for (int i = 1; i < _argc; ++i) {
            if(cmd(_argv[i]) == -1) {fE = 1;}
            else if(cmd(_argv[i]) == 0) {fD = 1;}
            else if(cmd(_argv[i]) == 1) {fI = 1;}
            else if(cmd(_argv[i]) == 2) {fT = 1;}
            else if(cmd(_argv[i]) == 3) {fS = 1;}
        }
    }
    if (fE == 1) { 
        fprintf( stderr, "\nErreurs dans les arguments. Arguments valides: -d -i -t -s\n"); 
        return -1;
    }
    FILE* input;
    input = fopen("input.data", "w");
    if (input == NULL) {
        fclose(input);
        exit(-1);
    }
    while (fgets(in, BUFFER_SIZE, stdin) != NULL) {
        fputs(in, input);
    }
    fclose(input);
    if (fT != 1) {
        input = fopen("input.data", "r");
        ver = infoDetail(_argc, input);
        fclose(input);
    } else { 
        ver = printVersion();
    }
    if (fI == 1) {
        Stamps* stamps = getStamps(0,0,0);
        fopen("input.data", "r");
        stamps = getInfoStamp(input);
        printf("information invalide\n  trx non reconnue : %zu\n  trx avec ts non sequentiel : %zu\n", stamps->nrTrx, stamps->nonSeqStamps);
        lastStampRead = stamps->lastStampRead;
        free(stamps);
        fclose(input);

    }
    if (fD == 1) {
        input = fopen("input.data", "r");
        DetailTrx* details = getDetailsTrx(0,0,0,0,0);
        details = infoDetailTrx(_argc, input);
        printf("information detaillee\n  trx01 : %zu\n  trx02 : %zu\n  trx03 : %zu\n  trx04 : %zu\n  trx05 : %zu\n  le dernier ts lu : %zu\n", details->trx01, details->trx02, details->trx03, details->trx04, details->trx05, lastStampRead);
        free(details);
        fclose(input);
    }
    if (fS == 1) {
        input = fopen("input.data", "r");
        TrxNb* trx = getTotalTrx(0,0);
        trx = getNbTrx(ver, input);
        printf("information sommaire\n  nbr trx valides : %zu\n  nrb trx (total) : %zu\n", trx->validTrx, trx->totalTrx);
        free(trx);
        fclose(input);
    }
    remove("input.data");
    return 0;
}