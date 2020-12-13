#ifndef __OUTIL3_H__
#define __OUTIL3_H__
#include <stddef.h>
#include <stdio.h>
float distance(int _signal, int _pow);

typedef struct {
    size_t trx01;
    size_t trx02;
    size_t trx03;
    size_t trx04;
    size_t trx05;
} DetailTrx;

DetailTrx* getDetailsTrx(size_t _trx1, size_t _trx2, size_t _trx3, size_t _trx4, size_t _trx5);
int cmd(char* arg);
DetailTrx* infoDetailTrx(int _argc, FILE* fp);
#endif