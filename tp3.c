#include "malib.h"
#include "outil3.h"
#include "tcv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
    int (*pt)(int, char**) = &main1;
    (*pt)(argc, argv);
    return 0;
}