void menorCaminho(int **distancias, int **caminhos, int quantidadeDistancias, int quantidadeCaminhos) {
    for(int i=0; i< quantidadeCaminhos; i++) {
        int dist = 0;
        for(int j=0; j<quantidadeDistancias - 1; j++) {
            if(j< quantidadeCaminhos) {
                int cidadeA = caminhos[i][j];
                int cidadeB = caminhos[i][j+1];

                dist += distancias[cidadeA][cidadeB];
            }
        }
    }
}
