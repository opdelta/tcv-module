//malib.h
#ifndef __MALIB_H__
#define __MALIB_H__


typedef struct {
int timestamp;
int signature;
int id;
unsigned char  emetteurPow;
}id;

struct getIdentification{int _timestamp; int _signature; int _id; unsigned char  _emetteurPow;};

typedef struct {
int timestamp;
int signature;
float temp;
int error; //0 = no error 1 = error
}temperatureH;

struct getTemperatureH{int _timestamp; int _signature; float _temp; int _error;};

typedef struct {
int timestamp;
int signature;
float temp;
int error; // 0 = no error 1 = error
}temperatureA;

struct getTemperatureA{int _timestamp; int _signature; float _temp; int _error;};

typedef struct {
int timestamp;
int signature;
float pulse;
int error; //0 = no error 1 = error
}pulsation;

struct getPulsation{int _timestamp; int _signature; float _pulse; int _error;};

typedef struct {
int timestamp;
int signature;
signed short signalRSSI;
int id;
}rssiSignal;

struct getrssiSignal{int _timestamp; int _signature; signed short _signalRSSI; int _id;};

typedef struct {
int timestamp;
int signature;
int id;
int idpn [];
}echangeDonnees;

struct getEchangeDonnees{int _timestamp; int _signature; int _id; int idpn [];};

#endif