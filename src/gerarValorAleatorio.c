#include <time.h>
#include <stdlib.h>
#include "gerarValorAleatorio.h"

int gerarValorAleatorio(int minimo, int maximo){
    return minimo + rand() % (maximo - minimo + 1);
}