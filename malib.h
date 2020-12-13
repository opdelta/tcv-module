//malib.h
#ifndef __MALIB_H__
#define __MALIB_H__
#include <stddef.h>
#include <stdio.h>

typedef struct {
size_t timestamp;
size_t signature;
float id;
unsigned char  emetteurPow;
}Id;

Id* getIdentification(size_t _timestamp, size_t _signature, float _id, unsigned char _emetteurPow);

typedef struct {
size_t timestamp;
size_t signature;
float temp;
int error; //0 = no error 1 = error
}TemperatureH;

TemperatureH* getTemperatureH(size_t _timestamp, size_t _signature, float _temp, int _error);

typedef struct {
size_t timestamp;
size_t signature;
float temp;
int error; // 0 = no error 1 = error
}TemperatureA;

TemperatureA* getTemperatureA(size_t _timestamp, size_t _signature, float _temp, int _error);

typedef struct {
size_t timestamp;
size_t signature;
float pulse;
int error; //0 = no error 1 = error
}Pulsation;

Pulsation* getPulsation(size_t _timestamp, size_t _signature, float _pulse, int _error);

typedef struct {
size_t timestamp;
size_t signature;
signed short signalRSSI;
size_t id;
}RssiSignal;

RssiSignal* getrssiSignal(size_t _timestamp, size_t _signature, signed short _signalRSSI, size_t _id);

typedef struct {
size_t timestamp;
size_t signature;
size_t id;
size_t idpn [];
}EchangeDonnees;

EchangeDonnees* getEchangeDonnees(size_t _timestamp, size_t _signature, size_t _id, size_t _idpn []);

char** strToArray(char* _line);
char* getTransaction(char _line[]);
Id* strToId(size_t _lastStamp, char _line[]);
float distance(int _signal, int _pow);
size_t strToRssi(size_t _lastStamp, char _line[], int _pow);
float strToTemp(size_t _lastStamp, char _line[]);
float average(float _fullTemp, int _count);
void strToData(size_t _lastStamp, char _line[], Id* _ident, size_t _idpn[]);
void infoDetail(int _argc, FILE* fp);
unsigned int printVersion();
#endif