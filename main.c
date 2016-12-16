#include <stdio.h>
#include <stdlib.h>

struct lista {
    char label [TAM_MAX_LINHA];
	char codigo_op [3];
	int teste;
	unsigned char operando;
	unsigned char pos_memoria;
	struct Lista *prox_elemento;o
};

typedef lista_t struct lista *;

void panico(const char *msg){
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}

lista_t lista_criar(){
    lista_t cabeca = malloc( sizeof(struct lista) );
    if( !cabeca ){
        panico("Falta de memoria");
    }
    cabeca->p = NULL;
    return cabeca;
}

lista_t lista_incluir(lista_t lista, int info){
    if(!lista)
        return NULL;
    lista_t no = malloc( sizeof(struct lista) );
    if (!no){
        panico("Falta de memoria");
    }
    no->info = info;
    no->p = NULL;
    lista_t no_atual = lista;
    while(no_atual->p != NULL)
        no_atual = no_atual->p;
    no_atual->p = no;
    return no;
}

void lista_imprimir(lista_t lista){
    if (!lista)
        return;

    lista_t no_atual = lista->p;
    while(no_atual) {
        printf("%d ", no_atual->info);
        no_atual = no_atual->p;
    }
    printf("\n");
}

void lista_destruir(lista_t lista){
    if(!lista)
        return;
    lista_t no, no_atual = lista->p;
    while(no_atual){
        no = no_atual->p;
        free(no_atual);
        no_atual=no;
    }
    free(lista);
}

int ler_operando(int argc, char *argv[])
{
    char *line = NULL;

    size_t len = 16;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1){

        if (read > 0)


    }
    free (line);

    return 0;
}

void lerLabel(char *linha){
    char *tmp = linha;
    char *al;

    while(linha =! ":")
    al == linha;
    print(al);

    free(*tmp);
    free(*al);
}

int ler_instrucao(int argc, char *argv[])
{
    char *line = NULL;

    size_t len = 16;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1){

        if (read > 0){

        }

    }
    free (line);

    return 0;
}

void idendifica(unsigned char temp) {
	switch (temp) {
	case 0x00: //NOP
		codigo_op [3] = "NOP";
		break;

	case 0x10: //STA
		codigo_op [3] = "STA";
		break;

	case 0x20: //LDA
		codigo_op [3] = "LDA";
		break;

	case 0x30: //ADD
		codigo_op [3] = "ADD";
		break;

	case 0x40: //OR
		codigo_op [3] = "OR";
		break;

	case 0x50: //AND
		codigo_op [3] = "AND";
		break;

	case 0x60: //NOT
		codigo_op [3] = "NOT";
		break;

	case 0x80: //JMP
		codigo_op [3] = "JMP";
		break;

	case 0x90: //JN
		codigo_op [3] = "JN";
		break;

	case 0xA0: //JZ
		codigo_op [3] = "JZ";
		break;

	case 0xF0: //HLT
		codigo_op [3] = "HLT";
		break;

	case 0xFF: //Quebra linha
		codigo_op [3] = "\n";
		break;

	default:
        codigo_op [3] = "?";
        break;
    }
}

int main(void){
    lista_t lst = lista_criar(), l;
	char saida[TAM_MAX_LINHA];
	unsigned char temp;
	int verifica = 1;
	int i = 0;
	FILE *arquivo_saida;
	FILE *arquivo = fopen(argv[1], "rb");
	if (arquivo == NULL) {
		printf("Erro ao carregar arquivo.\n");
		return 0;
	}

	fseek(arquivo, 0L, SEEK_END);
	int fSize = ftell(arquivo);
	rewind(arquivo);
	printf("Tamanho: %d\n", fSize);

	unsigned char *buffer = (malloc(fSize));

	fread(buffer, fSize, 1, arquivo);
	fclose(arquivo);
}
