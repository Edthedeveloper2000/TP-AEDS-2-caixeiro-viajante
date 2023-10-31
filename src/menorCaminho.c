int menorCaminho(int **matriz, int **result, int totalPermutations, int N, int X) {
    int menorDistancia = -1; // Valor inicial para comparar e encontrar o menor

    for (int i = 0; i < totalPermutations; i++) {
        int somaDistancias = 0;

        // Calcular a soma das distâncias para a permutação atual
        for (int j = 0; j < N - 1; j++) {
            int cidadeOrigem = result[i][j];
            int cidadeDestino = result[i][j + 1];
            somaDistancias += matriz[cidadeOrigem][cidadeDestino];
        }
        
        // Distância de X até a primeira cidade da permutação
        somaDistancias += matriz[X][result[i][0]];
        // Distância da última cidade de volta para X (rota circular)
        somaDistancias += matriz[result[i][N - 1]][X];

        // Verificar se é a menor distância ou se é a primeira iteração
        if (menorDistancia == -1 || somaDistancias < menorDistancia) {
            menorDistancia = somaDistancias;
        }
    }

    return menorDistancia;
}
