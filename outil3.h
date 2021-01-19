#ifndef __OUTIL3_H__
#define __OUTIL3_H__
#include <stddef.h>
#include <stdio.h>
float distance(int _signal, int _pow);
typedef struct {
    size_t totalTrx;
    size_t validTrx;
} TrxNb;
typedef struct {
    size_t nonSeqStamps;
    size_t lastStampRead;
    size_t nrTrx;
} Stamps;
typedef struct {
    size_t trx01;
    size_t trx02;
    size_t trx03;
    size_t trx04;
    size_t trx05;
} DetailTrx;
TrxNb* getTotalTrx(size_t _totalTrx, size_t _validTrx);
Stamps* getStamps(size_t _nsst, size_t _lsr, size_t _nrTrx);
Stamps* getInfoStamp(FILE* _input);
DetailTrx* getDetailsTrx(size_t _trx1, size_t _trx2, size_t _trx3, size_t _trx4, size_t _trx5);
int cmd(char* arg);
DetailTrx* infoDetailTrx(int _argc, FILE* fp);
size_t getInvalidTrx(FILE* _input);
TrxNb* getNbTrx(unsigned int _ver, FILE* _input);
#endif