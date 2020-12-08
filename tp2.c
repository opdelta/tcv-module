#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include "malib.h"
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define BUFFER_SIZE 1000 //Buffer pour une ligne lue

unsigned int printVersion() {
  version_t *v = malloc(sizeof(version_t));
  getVersion(v);
  printf("%s%u.%u.%u\n","version #: ",v->major,v->minor,v->build);
  unsigned int versionBuild = v->build;
  free(v);
  return versionBuild;
}

void displayAverages(float _mTH, float _mTA, size_t _mPul) {
  printf("%d %.1f %.1f %zu\n", 21, _mTH, _mTA, _mPul);
}
void displayError(int _trans, size_t _invTH, size_t _invTA, size_t _invPul) {
  printf("%d %zu %zu %zu\n", _trans, _invTH/3, _invTA/3, _invPul/3);
}

int main(int _argc, char **_argv) {
  unsigned int ver = printVersion();
  int build = 0;
  if (ver > 1003) {
    build = 1;
  }
  char line[BUFFER_SIZE];
  char* signature;
  char fullLine[BUFFER_SIZE];
  Id* ident;
  int pow = 2;
  int tempHCount = 0;
  int tempACount = 0;
  int pulseCount = 0;
  size_t errHCount = 0;
  size_t errACount = 0;
  size_t errPCount = 0;
  size_t invHCount = 0;
  size_t invACount = 0;
  size_t invPCount = 0;
  float fullTempH = 0;
  float fullTempA = 0;
  float fullPulse = 0;
  int nbIdpn = 0;
  size_t idpn[2];
  signature = calloc(BUFFER_SIZE, sizeof(char));
  while (fgets(line, BUFFER_SIZE, stdin) != NULL) {
      if (line != NULL) {
        strcpy(fullLine, line);
        signature = getTransaction(line);
      } else {
        break;
      }
      if (signature != NULL) {
        if(strcmp(signature, "00") == 0) { //Signature identification
          ident = strToId(fullLine);
          pow = ident->emetteurPow;
        //End signature identification
        } else if(strcmp(signature, "01") == 0) { //Signature temperatureH
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errHCount++;
          } else if (temp != -1000) {
            if (temp < 100) {
              if (validerTH_1((int)temp*10)) {
              tempHCount++;
              fullTempH += temp;
              } else {
                invHCount++;
              }
            } else {
              if (validerTH_1((int)temp)) {
                tempHCount++;
                fullTempH += temp;
              } else {
              invHCount++;
              }
            }
            
          }
        //End signature TemperatureH
        } else if(strcmp(signature, "02") == 0) { //Signature temperatureA
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errACount++;
          } else if (temp != -1000) {
            if(build == 0) {
              if (validerTA_3((short)temp)) {
                tempACount++;
                fullTempA += temp;
              } else {
                invACount++;
              }
            } else {
              if (validerTA_1((int)temp)) {
                tempACount++;
                fullTempA += temp;
              } else {
                invACount++;
              }
            }
          }
        //End signature temperatureA
        } else if(strcmp(signature, "03") == 0) { //Signature pulsation
          float temp = strToTemp(fullLine);
          if (temp == -999) {
            errPCount++;
          } else if (temp != -1000) {
            if (build == 0) {
              if (validerPulsation_3((short)temp)) {
                pulseCount++;
                fullPulse += temp;
              } else {
                invPCount++;
              }
            } else {
               if(validerPulsation_1((int)temp)) {
                   pulseCount++;
                   fullPulse+=temp;
                } else {
                  invPCount++;
                }
            }
          }
        //End signature pulsation
        } else if(strcmp(signature, "04") == 0) { //Signature RSSI
          idpn[nbIdpn] = strToRssi(fullLine, pow);
          ++nbIdpn;

        //End signature RSSI
        } else if(strcmp(signature, "05") == 0) { //Signature data
          strToData(fullLine, ident, idpn);
        //End signature data
        }
      }
  }
  printf("%s","\n");
  displayAverages(fullTempH, fullTempA, fullPulse);
  displayError(22, errHCount, errACount, errPCount);
  printf("%d %zu %zu %zu\n", 23, invHCount, invACount, invPCount);
  free(ident);
  return 0;
}
