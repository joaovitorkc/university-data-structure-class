#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_ITENS 100
#define MAX_PEDIDOS 100

typedef struct {
    char nome[50];
    int quantidade;
} Item;

Item listaCompras[MAX_ITENS];
int totalItens = 0;

typedef struct {
    int id;
    char cliente[50];
} Pedido;

Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;

void adicionarItem(char nome[], int qtd) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(listaCompras[i].nome, nome) == 0) {
            listaCompras[i].quantidade += qtd;
            return;
        }
    }
    strcpy(listaCompras[totalItens].nome, nome);
    listaCompras[totalItens].quantidade = qtd;
    totalItens++;
}

void removerItem(char nome[]) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(listaCompras[i].nome, nome) == 0) {
            for (int j = i; j < totalItens - 1; j++)
                listaCompras[j] = listaCompras[j + 1];
            totalItens--;
            return;
        }
    }
    printf("Item nao encontrado!\n");
}

void listarCompras() {
    if (totalItens == 0) {
        printf("Lista de compras vazia!\n");
        return;
    }
    printf("Lista de Compras:\n");
    for (int i = 0; i < totalItens; i++)
        printf("%s: %d\n", listaCompras[i].nome, listaCompras[i].quantidade);
}

void cadastrarPedido(int id, char cliente[]) {
    pedidos[totalPedidos].id = id;
    strcpy(pedidos[totalPedidos].cliente, cliente);
    totalPedidos++;
}

void entregarPedido(int id) {
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == id) {
            for (int j = i; j < totalPedidos - 1; j++)
                pedidos[j] = pedidos[j + 1];
            totalPedidos--;
            return;
        }
    }
    printf("Pedido nao encontrado!\n");
}

void listarPendentes() {
    if (totalPedidos == 0) {
        printf("Nenhum pedido pendente!\n");
        return;
    }
    printf("Pedidos pendentes:\n");
    for (int i = 0; i < totalPedidos; i++)
        printf("ID: %d | Cliente: %s\n", pedidos[i].id, pedidos[i].cliente);
}

int main() {
    int opcao;
    do {
        system("clear"); 
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Adicionar item na lista de compras\n");
        printf("2. Remover item da lista de compras\n");
        printf("3. Listar compras\n");
        printf("4. Cadastrar pedido delivery\n");
        printf("5. Entregar pedido delivery\n");
        printf("6. Listar pedidos pendentes\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char nome[50];
            int qtd;
            printf("Nome do item: ");
            scanf("%s", nome);
            printf("Quantidade: ");
            scanf("%d", &qtd);
            adicionarItem(nome, qtd);
        } else if (opcao == 2) {
            char nome[50];
            printf("Nome do item para remover: ");
            scanf("%s", nome);
            removerItem(nome);
        } else if (opcao == 3) {
            listarCompras();
            printf("\nPressione enter para continuar...");
            getchar(); getchar();
        } else if (opcao == 4) {
            int id;
            char cliente[50];
            printf("ID do pedido: ");
            scanf("%d", &id);
            printf("Nome do cliente: ");
            scanf("%s", cliente);
            cadastrarPedido(id, cliente);
        } else if (opcao == 5) {
            int id;
            printf("ID do pedido entregue: ");
            scanf("%d", &id);
            entregarPedido(id);
        } else if (opcao == 6) {
            listarPendentes();
            printf("\nPressione enter para continuar...");
            getchar(); getchar();
        }
    } while (opcao != 0);

    return 0;
}
