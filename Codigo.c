#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// Estrutura da sala (nó da árvore)
// -----------------------------
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// -----------------------------
// Função para criar uma sala
// -----------------------------
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// -----------------------------
// Exploração interativa da árvore
// -----------------------------
void explorarSalas(Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está na sala: **%s**\n", atual->nome);

        // Nó-folha (fim do caminho)
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Você chegou ao fim do caminho desta ala da mansão.\n");
            return;
        }

        printf("Escolha o caminho:\n");
        if (atual->esq != NULL) printf("  e - Ir para a esquerda (%s)\n", atual->esq->nome);
        if (atual->dir != NULL) printf("  d - Ir para a direita (%s)\n", atual->dir->nome);
        printf("  s - Sair da exploração\n");
        printf("> ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        }
        else if (opcao == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        }
        else if (opcao == 's') {
            printf("Saindo da mansão...\n");
            return;
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}

// -----------------------------
// Monta a árvore e inicia o jogo
// -----------------------------
int main() {
    // Criando salas
    Sala* hall        = criarSala("Hall de Entrada");
    Sala* salaJantar  = criarSala("Sala de Jantar");
    Sala* salaEstar   = criarSala("Sala de Estar");
    Sala* cozinha     = criarSala("Cozinha");
    Sala* biblioteca  = criarSala("Biblioteca");
    Sala* jardim      = criarSala("Jardim Interno");

    // Estrutura da árvore
    //
    //                Hall
    //              /       \
    //      Sala Jantar   Sala Estar
    //        /     \         /     \
    //   Cozinha  Biblioteca  NULL  Jardim

    hall->esq = salaJantar;
    hall->dir = salaEstar;

    salaJantar->esq = cozinha;
    salaJantar->dir = biblioteca;

    salaEstar->dir = jardim;

    printf("=== Mansão Assombrada: Exploração ===\n");

    explorarSalas(hall);

    return 0;
}
