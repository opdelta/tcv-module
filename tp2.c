#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include "malib.h"
#include <math.h>
#include <string.h>

void printVersion() {
  version_t *v = malloc(sizeof(version_t));
  getVersion(v);
  printf("%s","version #: ");
  printf("%u.",v->major);
  printf("%u.",v->minor);
  printf("%u\n",v->build);
  free(v);
}

char* getTransaction(char _line[]) {
   char* signature = strtok(_line, " ");
   if (_line != NULL) {
    signature = strtok(NULL," ");
   }
   return signature;
}
void strToId(char _line[]) {
  int timestamp = 0;
  int signature = 0;
  float id = 0;
  unsigned char pow = 0;
  char* arg = strtok(_line, " ");
  char ** args = NULL;
  int size = 0;
  int i = 0;
  /*Separe la ligne en tokens et les ajoute au tableau dynamique args */
  while (arg) {
    args = realloc (args, sizeof (char*) * ++size);
    args[size-1] = arg;
    arg = strtok(NULL, " ");
  }
  while (i < size) {
    switch(i)
    {
      case 0:
        if (args[i] != NULL) {
          timestamp = atoi(args[i]);
        }
        break;
      case 1:
        if (args[i] != NULL) {
          signature = atoi(args[i]);
        }
        break;
      case 2:
        if (args[i] != NULL) {
          id = atof(args[i]);
        }
        break;
      case 3:
        if (args[i] != NULL) {
          pow = (unsigned char)strtol(args[i],NULL,10);
        }
        break;
    }
    ++i;
  }
  Id *ident = getIdentification(timestamp, signature, id, pow);
  printf("\ntype: %d\ntimestamp: %d\nsignature: %02d\nid: %.0f\npower: %d\n", 10, ident->timestamp, ident->signature, ident->id, ident->emetteurPow);
  /* Libere la memoire allouee */
  free (args);
  free(ident);
}

int main(int _argc, char **_argv) {
  printVersion();
  FILE *input = fopen(_argv[1], "r");
  char line[256];
  char* signature;
  char fullLine[256];
  while (fgets(line, sizeof(line), input)) {
    strcpy(fullLine, line);
    signature = getTransaction(line);

      if(strcmp(signature, "00") == 0) {
        printf("%s", "Identification entry: ");
        strToId(fullLine);
      } else if(strcmp(signature, "01") == 0) {
        printf("%s", "TemperatureH entry: ");
      } else if(strcmp(signature, "02") == 0) {
        printf("%s", "TemperatureA entry: ");
      } else if(strcmp(signature, "03") == 0) {
        printf("%s", "Pulsation entry: ");
      } else if(strcmp(signature, "04") == 0) {
        printf("%s", "RSSI entry: ");
      } else if(strcmp(signature, "05") == 0) {
        printf("%s", "Data entry: ");
      } else {
        printf("%s\n", "Nothing happened...");
        printf("%s", signature);
      }
      printf("%s", fullLine);
    }
  fclose(input);
  return 0;
}
