#ifndef MAQUINA_DE_ESTADOS_INCLUDED
#define MAQUINA_DE_ESTADOS_INCLUDED

// -- Estrutura de um estado da máquina --
struct estado {	
	int identificador;			// Identificador do estado
	int numPropriedades;		// Número de propriedades do estado
	char** propriedades;		// Lista de propriedades
	int qtdProxEstados;			// Quantidade de estados adjacentes
	int *proxEstados;			// Ponteiro para aos próximos estados
};

typedef struct estado ESTADO;

// -- Estrutura da máquina de estados representada como um grafo direcionado em lista de adj. --
struct maq_estados {
	int numEstados;			// Número de estados da máquina
	ESTADO* listaEstados;	// Lista de estados da máquina
};

typedef struct maq_estados MAQ_ESTADOS;

// -- Funções utilizadas pelo TAD MAQ_ESTADOS --

MAQ_ESTADOS* criar_maq_estados(int numEstados);     	// Cria a estrutura da máquina de estados

void alocar_lista_estados(MAQ_ESTADOS* m);		// Aloca espaço na memória para a lista de estados
void desalocar_lista_estados(MAQ_ESTADOS* m);	// Libera o espaço na memória alocado para a lista de estados
void destruir_maq_estados(MAQ_ESTADOS* m);		// Libera o espaço na memória alocado para a máquina

void set_num_estados(MAQ_ESTADOS* m, int numEstados);	// Insere o número de estados que a máquina possui
int get_num_estados(MAQ_ESTADOS* m);                  	// Retorna o número de estados que a máquina possui

void set_ident_estado(MAQ_ESTADOS* m, int estado, int identificador);						// Insere o identificador em um estado
void set_num_prop_estado(MAQ_ESTADOS* m, int estado, int numPropriedades);					// Insere o número de propriedades em um estado
void add_prop_estado(MAQ_ESTADOS* m, int estado, int posPropriedade, char* propriedade);	// Adiciona uma propriedade em um estado
void set_qtd_prox_estados(MAQ_ESTADOS* m, int estado, int qtdProxEstados);					// Insere a quantidade de prox. estados que um estado tem
void add_prox_estado(MAQ_ESTADOS* m, int estado, int posProxEstado, int proxEstado);		// Adiciona um estado na lista de prox. estados do estado

void imprimir_infos_maquina(MAQ_ESTADOS* m);

#endif // MAQUINA_DE_ESTADOS_INCLUDED
