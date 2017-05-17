#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MaquinaEstados.h"

/*
    Aloca espaço na memória para a Máquina de Estados.
	Insere também o número de estados da máquina
*/
MAQ_ESTADOS* criar_maq_estados(int numEstados) {
	MAQ_ESTADOS* m = (MAQ_ESTADOS*) malloc(1 * sizeof(MAQ_ESTADOS));
	set_num_estados(m, numEstados);
	alocar_lista_estados(m);
	return(m);
}

/*
    Aloca espaço na memória para a estrutura da lista de
    estados
*/
void alocar_lista_estados(MAQ_ESTADOS* m) {
    m->listaEstados = (ESTADO*) malloc(get_num_estados(m) * sizeof(ESTADO));

    for(int i = 0; i < get_num_estados(m); i++) {
		m->listaEstados[i].identificador = -1;
		m->listaEstados[i].numPropriedades = -1;
		m->listaEstados[i].propriedades	= NULL;
		m->listaEstados[i].qtdProxEstados = -1;
    	m->listaEstados[i].proxEstados = NULL;
    }
}

/*
    Libera o espaço de memória alocado para a lista de estados
*/
void desalocar_lista_estados(MAQ_ESTADOS *m) {
	for(int i = 0; i < get_num_estados(m); i++) {
		
		for(int j = 0; j < m->listaEstados[i].numPropriedades; j++) {
			if(m->listaEstados[i].propriedades[j] != NULL) {
				free(m->listaEstados[i].propriedades[j]);
			}
		}

		if(m->listaEstados[i].propriedades != NULL) {
			free(m->listaEstados[i].propriedades);
		}

		if(m->listaEstados[i].proxEstados != NULL) {
			free(m->listaEstados[i].proxEstados);
		}
	}

	free(m->listaEstados);
}

/*
    Libera o espaço de memória alocado para a máquina
*/
void destruir_maq_estados(MAQ_ESTADOS* m) {
	desalocar_lista_estados(m);
	if(m != NULL) {
		free(m);
	}
}

/*
    Insere o número de estados da máquina
*/
void set_num_estados(MAQ_ESTADOS* m, int numEstados) {
    m->numEstados = numEstados;
}

/*
    Retorna o número de estados da máquina
*/
int get_num_estados(MAQ_ESTADOS* m) {
    return(m->numEstados);
}

/*
	Insere o identificador em 'estado'
*/
void set_ident_estado(MAQ_ESTADOS* m, int estado, int identificador) {
	m->listaEstados[estado].identificador = identificador;
}

/*
	Insere o numero de propriedades que 'estado' possui
*/
void set_num_prop_estado(MAQ_ESTADOS* m, int estado, int numPropriedades) {
	m->listaEstados[estado].numPropriedades = numPropriedades;
	m->listaEstados[estado].propriedades = (char**) malloc(numPropriedades * sizeof(char*));
}

/*
	Insere uma propriedade em um estado
*/
void add_prop_estado(MAQ_ESTADOS* m, int estado, int posPropriedade, char* propriedade) {
	int propLength = strlen(propriedade);
	m->listaEstados[estado].propriedades[posPropriedade] = (char*) malloc((propLength+1) * sizeof(char));
	strcpy(m->listaEstados[estado].propriedades[posPropriedade], propriedade);
}

/*
	Insere a quantidade de prox. estados que 'estado' tem
*/
void set_qtd_prox_estados(MAQ_ESTADOS* m, int estado, int qtdProxEstados) {
	m->listaEstados[estado].qtdProxEstados = qtdProxEstados;
	m->listaEstados[estado].proxEstados = (int*) malloc(qtdProxEstados * sizeof(int));
}

void add_prox_estado(MAQ_ESTADOS* m, int estado, int posProxEstado, int proxEstado) {
	m->listaEstados[estado].proxEstados[posProxEstado] = proxEstado;
}

void imprimir_infos_maquina(MAQ_ESTADOS* m) {
	printf("%d\n", m->numEstados);

	for(int i = 0; i < m->numEstados; i++) {
		printf("%d ", m->listaEstados[i].identificador);
		printf("%d ", m->listaEstados[i].numPropriedades);

		for(int j = 0; j < m->listaEstados[i].numPropriedades; j++) {
			printf("%s ", m->listaEstados[i].propriedades[j]);
		}

		printf("%d ", m->listaEstados[i].qtdProxEstados);

		for(int k = 0; k < m->listaEstados[i].qtdProxEstados; k++) {
			printf("%d ", m->listaEstados[i].proxEstados[k]);
		}

		printf("\n");
	}
}