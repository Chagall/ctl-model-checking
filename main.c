#include <stdio.h>
#include <stdlib.h>
#include "MaquinaEstados.h"

int main(int agrc, char* argv[]) {
    // Variáveis auxiliares para leitura do arquivo de entrada
    int numEstados = -1;
    int identEstado = -1;
    int numProp = -1;
    char nomeProp[32];
    int numProxEstados = -1;;
    char CTL[256];
    MAQ_ESTADOS* maqEstados = NULL;

    // Leitura do Número de Estados
    scanf("%d", &numEstados);

    // Verificação se máquina de estados tem pelo menos um estado
    if(numEstados <= 0) {
        printf("A maquina de estados deve possuir pelo menos um estado.\n");
        return(-1);
    }
    
    // Cria a máquina de estados
    maqEstados = criar_maq_estados(numEstados);

    // Verificação se máquina de estados foi criada com sucesso
    if(maqEstados == NULL) {
        printf("Ocorreu um erro ao criar a maquina de estados.\n");
        return(-1);
    }
    
    // Loop para adicionar informações de cada estado
    for(int i = 0; i < numEstados; i++) {
        // Inserir o identificador no estado
        scanf("%d", &identEstado);
        set_ident_estado(maqEstados, i, identEstado);

        // Inserir o número de propriedades no estado
        scanf("%d", &numProp);
        set_num_prop_estado(maqEstados, i, numProp);

        // Leitura das propriedades do estado
        for(int j = 0; j < numProp; j++) {
            // Inserir o nome de cada propriedade na lista de propriedades do estado
            scanf("%s", nomeProp);
            add_prop_estado(maqEstados, i, j, nomeProp);
        }

        // Inserir a quantidade de próximos estados do estado
        scanf("%d", &numProxEstados);
        set_qtd_prox_estados(maqEstados, i, numProxEstados);

        // Leitura dos próximos estados
        for(int k = 0; k < numProxEstados; k++){
            // inserir 'identEstado' na lista de adjacencias do estado
            scanf("%d", &identEstado);
            add_prox_estado(maqEstados, i, k, identEstado);
        }
    }
    
    // Leitura da expressão CTL
    scanf("%s", CTL);

    imprimir_infos_maquina(maqEstados);
    printf("%s\n", CTL);

    // Libera espaço de memória alocado para a máquina de estados
    destruir_maq_estados(maqEstados);

    return 0;
}