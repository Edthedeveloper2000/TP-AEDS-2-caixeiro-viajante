#include <time.h>
#include <stdlib.h>
#include "../headers/gerarValorAleatorio.h"

int gerarValorAleatorio(int minimo, int maximo){
    return minimo + rand() % (maximo - minimo + 1);
}