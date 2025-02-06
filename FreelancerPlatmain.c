#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100
#define MAX_USERS 100

typedef struct {
    char nome[MAX_STR];
    char area[MAX_STR];
    char habilidades[MAX_STR];
    char localizacao[MAX_STR];
    float avaliacao;
} Freelancer;

typedef struct {
    char nome[MAX_STR];
    char necessidade[MAX_STR];
    char localizacao[MAX_STR];
} Cliente;

typedef struct {
    char cliente[MAX_STR];
    char freelancer[MAX_STR];
    float valor;
    char forma_pagamento[MAX_STR];
} Pagamento;

Freelancer freelancers[MAX_USERS];
Cliente clientes[MAX_USERS];
Pagamento pagamentos[MAX_USERS];
int numFreelancers = 0, numClientes = 0, numPagamentos = 0;

void cadastrarFreelancer() {
    if (numFreelancers >= MAX_USERS) {
        printf("Limite de freelancers alcançado.\n");
        return;
    }
    Freelancer f;
    printf("Nome: "); scanf("%s", f.nome);
    printf("Área: "); scanf("%s", f.area);
    printf("Habilidades: "); scanf("%s", f.habilidades);
    printf("Localização: "); scanf("%s", f.localizacao);
    f.avaliacao = 0.0;
    freelancers[numFreelancers++] = f;
}

void cadastrarCliente() {
    if (numClientes >= MAX_USERS) {
        printf("Limite de clientes alcançado.\n");
        return;
    }
    Cliente c;
    printf("Nome: "); scanf("%s", c.nome);
    printf("Necessidade: "); scanf("%s", c.necessidade);
    printf("Localização: "); scanf("%s", c.localizacao);
    clientes[numClientes++] = c;
}

void buscarFreelancers() {
    char area[MAX_STR], local[MAX_STR];
    printf("Área desejada: "); scanf("%s", area);
    printf("Localização: "); scanf("%s", local);
    int found = 0;
    for (int i = 0; i < numFreelancers; i++) {
        if (strcmp(freelancers[i].area, area) == 0 && strcmp(freelancers[i].localizacao, local) == 0) {
            printf("Nome: %s, Habilidades: %s, Avaliação: %.1f\n", freelancers[i].nome, freelancers[i].habilidades, freelancers[i].avaliacao);
            found = 1;
        }
    }
    if (!found) {
        printf("Nenhum freelancer encontrado.\n");
    }
}

void registrarPagamento() {
    if (numPagamentos >= MAX_USERS) {
        printf("Limite de pagamentos alcançado.\n");
        return;
    }
    Pagamento p;
    printf("Nome do Cliente: "); scanf("%s", p.cliente);
    printf("Nome do Freelancer: "); scanf("%s", p.freelancer);
    printf("Valor: "); scanf("%f", &p.valor);
    printf("Forma de Pagamento: "); scanf("%s", p.forma_pagamento);
    pagamentos[numPagamentos++] = p;
}

void exibirPagamentos() {
    if (numPagamentos == 0) {
        printf("Nenhum pagamento registrado.\n");
        return;
    }
    for (int i = 0; i < numPagamentos; i++) {
        printf("Cliente: %s, Freelancer: %s, Valor: %.2f, Pagamento: %s\n", pagamentos[i].cliente, pagamentos[i].freelancer, pagamentos[i].valor, pagamentos[i].forma_pagamento);
    }
}

int main() {
    int opcao;
    do {
        printf("\n1. Cadastrar Freelancer\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Buscar Freelancers\n");
        printf("4. Registrar Pagamento\n");
        printf("5. Exibir Pagamentos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarFreelancer(); break;
            case 2: cadastrarCliente(); break;
            case 3: buscarFreelancers(); break;
            case 4: registrarPagamento(); break;
            case 5: exibirPagamentos(); break;
        }
    } while (opcao != 0);
    return 0;
}