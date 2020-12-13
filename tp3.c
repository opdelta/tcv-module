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
    char in[BUFFER_SIZE];
    int fD = 0, fI = 0, fT = 0, fS = 0, fE = 0;
    if (_argc > 5) {
        fE = 1;
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
    if (fI == 1) {
        //TODO
    }
    if (fT != 1) {
        input = fopen("input.data", "r");
        infoDetail(_argc, input);
        fclose(input);
    } else { 
        printVersion();
    }
    if (fD == 1) {
        input = fopen("input.data", "r");
        DetailTrx* details = getDetailsTrx(0,0,0,0,0);
        details = infoDetailTrx(_argc, input);
        printf("information detaillee\n  trx01: %zu\n  trx02: %zu\n  trx03: %zu\n  trx04: %zu\n  trx05: %zu\n", details->trx01, details->trx02, details->trx03, details->trx04, details->trx05);
        //TODO lastStamp read
        free(details);
        fclose(input);
    }
    if (fS == 1) {
        //TODO
    }
    remove("input.data");
    return 0;
}