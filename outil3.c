#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
float distance(int _signal, int _pow) {
  float temp1 = -69 - _signal;
  float temp2 = 10 * _pow;
  float temp3 = temp1/temp2;
  float distance = pow(10,temp3);
  return distance;
}
/*
int cmd(int _nbr_args, char** _arguments) {
    int flagI = 0;
    int flagD = 0;
    int flagT = 0;
    int flagS = 0;
    char* argFound;
    for (int i = 1; i < _nbr_args ++i) {
        argFound = _arguments[i];
        if (strcmp(argFound, "-d") != 0 && strcmp(argFound, "-i") != 0 && strcmp(argFound, "-t") != 0 && strcmp(argFound, "-s") != 0) {
            return -1;
        } else {
            if (strcmp(argFound, "-d") == 0 && flagD == 0) {
                flagD = 1;
                check_i();
            } else if (strcmp(argFound, "-i") == 0 && flagI == 0) {
                flagI = 1;
                check_d();
            } else if (strcmp(argFound, "-t") == 0 && flagT == 0) {
                flagT = 1;
                check_t();
            } else if (strcmp(argFound, "-s") == 0 && flagS == 0) {
                flagS = 1;
                check_s();
            }
        }
    }
    return 0;
}
void check_d(char** _arguments) {

}
void check_i() {

}
void check_t(int _nbr_arguments, char** _arguments,  int _position) {

}
void check_s(int _nbr_arguments, char** _arguments,  int _position) {

}
*/