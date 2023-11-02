#include <time.h>
#include <stdlib.h>
#include "../headers/gerarValorAleatorio.h"
/**
 * Gera um valor aleatório dentro do intervalo dado.
*/
int gerarValorAleatorio(int minimo, int maximo){
    return minimo + rand() % (maximo - minimo + 1);
}