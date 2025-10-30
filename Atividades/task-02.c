#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 10

typedef struct {
    char nomes[TAM_MAX][50];
    int inicio;
    int fim;
    int qtd;
} FilaCircular;

void inicializarFila(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

int filaCheia(FilaCircular *f) {
    return f->qtd == TAM_MAX;
}

int filaVazia(FilaCircular *f) {
    return f->qtd == 0;
}

void entrarFila(FilaCircular *f, char *nome) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar %s.\n", nome);
        return;
    }
    strcpy(f->nomes[f->fim], nome);
    f->fim = (f->fim + 1) % TAM_MAX;
    f->qtd++;
    printf("%s entrou na fila.\n", nome);
}

void atenderFila(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Ninguém para atender.\n");
        return;
    }
    printf("Atendendo: %s\n", f->nomes[f->inicio]);
    f->inicio = (f->inicio + 1) % TAM_MAX;
    f->qtd--;
}

void listarFila(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila de atendimento:\n");
    int i, idx = f->inicio;
    for (i = 0; i < f->qtd; i++) {
        printf(" %d. %s\n", i + 1, f->nomes[idx]);
        idx = (idx + 1) % TAM_MAX;
    }
}

typedef struct {
    char caixas[TAM_MAX][50];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == TAM_MAX - 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char *nome) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia! Não é possível empilhar %s.\n", nome);
        return;
    }
    strcpy(p->caixas[++p->topo], nome);
    printf("%s empilhada.\n", nome);
}

void desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Nenhuma caixa para desempilhar.\n");
        return;
    }
    printf("Desempilhando: %s\n", p->caixas[p->topo--]);
}

void topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Topo: %s\n", p->caixas[p->topo]);
}

void listarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Caixas na pilha (do topo à base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf(" %d. %s\n", p->topo - i + 1, p->caixas[i]);
    }
}

/* ---------------------- MAIN ---------------------- */
int main() {
    FilaCircular fila;
    Pilha pilha;
    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int opcao;
    char nome[50];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Entrar na Fila\n");
        printf("2 - Atender Fila\n");
        printf("3 - Listar Fila\n");
        printf("4 - Empilhar Caixa\n");
        printf("5 - Desempilhar Caixa\n");
        printf("6 - Mostrar Topo da Pilha\n");
        printf("7 - Listar Pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar o buffer

        switch (opcao) {
            case 1:
                printf("Nome do cliente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                entrarFila(&fila, nome);
                break;
            case 2:
                atenderFila(&fila);
                break;
            case 3:
                listarFila(&fila);
                break;
            case 4:
                printf("Nome da caixa: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                empilhar(&pilha, nome);
                break;
            case 5:
                desempilhar(&pilha);
                break;
            case 6:
                topoPilha(&pilha);
                break;
            case 7:
                listarPilha(&pilha);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
