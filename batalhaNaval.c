#include <stdio.h>
#include <locale.h> // Permite o uso de acentos e caracteres especiais de acordo com a localidade definida (Português)

// Rotula a as palavras LINHA_TABULEIRO e COLUNA_TABULEIRO como referências aos valores associados
// Sem tipo, não ocupa espaço na memória
#define LINHA_TABULEIRO 10
#define COLUNA_TABULEIRO 10

// Inicialização da matriz com zeros de forma implícita
int tabuleiroBatalhaNaval[LINHA_TABULEIRO][COLUNA_TABULEIRO] = {
    {0}
};

void imprimirTabuleiro(int tabuleiro[LINHA_TABULEIRO][COLUNA_TABULEIRO]){
    // Impressão do tabuleiro com letras e números
    printf("   "); // Espaço para alinhar os números das colunas

    // Imprime os números das colunas (1 a 10)
    for (int j = 0; j < 10; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");

    // Impressão da matriz tabuleiroBatalhaNaval
    // Loop para percorrer as linhas
    for (int i = 0; i < 10; i++){
        printf(" %c ", 'A' + i); // Converte índice (0-9) para letra (A-J)

        // Loop para percorrer as colunas
        for (int j = 0; j < 10; j++){
            printf(" %d ", tabuleiro[i][j]);
        }
        // Pula uma linha após imprimir uma linha inteira.
        printf("\n"); 
    }
}

// Inicialização e atribuição de valores para os vetores que representam os navios
int navioAlphaHorizontal[3] = {3,3,3};
int navioBetaVertical[3] = {3,3,3};
int navioCeltaDiagonalPrincipal[3] = {3,3,3};
int navioDeltaDiagonalSecundaria[3] = {3,3,3};

// Função para inserir o navio Alpha Horizontal no tabuleiro
void inserirNavioAlphaHorizontal(int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiroBatalhaNaval[linha][coluna + i] = tamanho;  // Preenche com o tamanho do navio
    }
}

// Função para inserir o navio Beta Vertical no tabuleiro
void inserirNavioBetaVertical(int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiroBatalhaNaval[linha + i][coluna] = tamanho;  // Preenche com o tamanho do navio
    }
}

// Função para inserir o navio Celta Diagonal Principal no tabuleiro
void inserirNavioCeltaDiagonalPrincipal(int linha, int coluna, int tamanho){
    for (int i = 0; i < tamanho; i++){
        tabuleiroBatalhaNaval[linha + i][coluna + i] = tamanho;       
    }
    
}

// Função para inserir o navio Delta Diagonal Secundaria no tabuleiro
void inserirNavioDeltaDiagonalSecundaria(int linha, int coluna, int tamanho){
    for (int i = 0; i < tamanho; i++){
        tabuleiroBatalhaNaval[linha + i][coluna - i] = tamanho;       
    }
}

// Habilidade Especial Cone
void dispararHabilidadeEspecialCone(){
    // Cria uma cópia do tabuleiro original para que as habilidades especiais
    // sejam aplicadas na cópia, permitindo imprimir o resultado sem alterar
    // o estado do tabuleiro original.
    int tabuleiroResultado[LINHA_TABULEIRO][COLUNA_TABULEIRO];
    // Copiar o tabuleiro original para a matriz resultante
    for (int i = 0; i < LINHA_TABULEIRO; i++) {
        for (int j = 0; j < COLUNA_TABULEIRO; j++) {
            tabuleiroResultado[i][j] = tabuleiroBatalhaNaval[i][j];
        }
    }

    // Cria a matriz do cone atribuindo 0 a todos os índices
    int cone[3][5] = {0};

    // Preenche toda a estrutura usando loops aninhados
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {  
            cone[i][j] = 1; 
        }
    }

    // Imprime a matriz Cone
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf(" %d ", cone[i][j]);
        }
        printf("\n");
    }

    // Aplica a habilidade Cone no tabuleiro a partir da posição [0][0]
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {  
                if (tabuleiroResultado[i][j] == 3) {  
                    tabuleiroResultado[i][j] = 5;  // Se for navio (3), vira 5
                } else if (tabuleiroResultado[i][j] == 0) {  
                    tabuleiroResultado[i][j] = 1;  // Se for vazio (0), vira 1
                }
            }
        }
    }

    // Imprime o tabuleiroResultado após a sobreposição
    printf("\nTABULEIRO APÓS DISPARAR A HABILIDADE ESPECIAL CONE A PARTIR DA POSIÇÃO A-1:\n");
    imprimirTabuleiro(tabuleiroResultado);
}


// Habilidade Especial Cruz
void dispararHabilidadeEspecialCruz(){

    // Cria uma cópia do tabuleiro original para que as habilidades especiais
    // sejam aplicadas na cópia, permitindo imprimir o resultado sem alterar
    // o estado do tabuleiro original.
    int tabuleiroResultado[LINHA_TABULEIRO][COLUNA_TABULEIRO];
    // Copiar o tabuleiro original para a matriz resultante
    for (int i = 0; i < LINHA_TABULEIRO; i++) {
        for (int j = 0; j < COLUNA_TABULEIRO; j++) {
            tabuleiroResultado[i][j] = tabuleiroBatalhaNaval[i][j];
        }
    }

    int cruz[3][5] = {0};

    // Preenche a cruz com 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 1 || j == 2) {  // Preenche somente a linha e coluna central formando a cruz
                cruz[i][j] = 1;
            }
        }
    }

    // Imprime a matriz Cruz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf(" %d ", cruz[i][j]);
        }
        printf("\n");
    } 

    // Aplica a habilidade Cruz no tabuleiro a partir da posição [0][5]
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = i;              // Linha Inicial do tabuleiro
            int coluna = j + 5;         // Coluna Inicial do tabuleiro (adicionando 5 para começar da coluna 5)

            if (cruz[i][j] == 1) {  
                if (tabuleiroResultado[linha][coluna] == 3) {  
                    tabuleiroResultado[linha][coluna] = 5;  // Se for navio (3), vira 5
                } else if (tabuleiroResultado[linha][coluna] == 0) {  
                    tabuleiroResultado[linha][coluna] = 1;  // Se for vazio (0), vira 1
                }
            }
        }
    }

    // Imprime o tabuleiro após a sobreposição
    printf("\nTABULEIRO APÓS DISPARAR A HABILIDADE ESPECIAL CRUZ A PARTIR DA POSIÇÃO A-6:\n");
    imprimirTabuleiro(tabuleiroResultado);
}

// Habilidade Especial Octaedro
void dispararHabilidadeEspecialOctaedro(){

    // Cria uma cópia do tabuleiro original para que as habilidades especiais
    // sejam aplicadas na cópia, permitindo imprimir o resultado sem alterar
    // o estado do tabuleiro original.
    int tabuleiroResultado[LINHA_TABULEIRO][COLUNA_TABULEIRO];
    // Copiar o tabuleiro original para a matriz resultante
    for (int i = 0; i < LINHA_TABULEIRO; i++) {
        for (int j = 0; j < COLUNA_TABULEIRO; j++) {
            tabuleiroResultado[i][j] = tabuleiroBatalhaNaval[i][j];
        }
    }

    int octaedro[3][5] = {0};

    // Preenche o formato octaedro usando loop aninhado e condicional if
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if (
                (i == 0 && j == 2) ||
                (i == 1 && (j >= 1 && j <= 3)) ||
                (i == 2 && j == 2)
                ){
                octaedro[i][j] = 1;
            } 
        }
    }

    // Imprime a matriz Octaedro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf(" %d ", octaedro[i][j]);
        }
        printf("\n");
    }

    // Aplica a habilidade Octaedro no tabuleiro a partir da posição [][]
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = i + 4;              // Linha Inicial do tabuleiro (adicionando 4 para começar da linha 4)
            int coluna = j + 3;         // Coluna Inicial do tabuleiro (adicionando 3 para começar da coluna 3)

            if (octaedro[i][j] == 1) {  
                if (tabuleiroResultado[linha][coluna] == 3) {  
                    tabuleiroResultado[linha][coluna] = 5;  // Se for navio (3), vira 5
                } else if (tabuleiroResultado[linha][coluna] == 0) {  
                    tabuleiroResultado[linha][coluna] = 1;  // Se for vazio (0), vira 1
                }
            } 
        }
    }

    // Imprime o tabuleiro após a sobreposição
    printf("\nTABULEIRO APÓS DISPARAR A HABILIDADE ESPECIAL OCTAEDRO A PARTIR DA POSIÇÃO E-3:\n");
    imprimirTabuleiro(tabuleiroResultado);
}

int main(){
    // Define a localidade para o português do Brasil
    setlocale(LC_ALL, "pt_BR.utf8");  
    
    // Inserindo o navio Alpha definindo a posição em hardcoding
    inserirNavioAlphaHorizontal(1, 2, navioAlphaHorizontal[0]);

    // Inserindo o navio Beta definindo a posição em hardcoding
    inserirNavioBetaVertical(4, 6, navioBetaVertical[0]);

    // Inserindo o navio Celta definindo a posição em harcoding
    inserirNavioCeltaDiagonalPrincipal(6,1, navioCeltaDiagonalPrincipal[0]);

    // Inserindo o navio Delta definindo a posição em harcoding
    inserirNavioDeltaDiagonalSecundaria(0,9, navioDeltaDiagonalSecundaria[0]);

    printf("\n### BEM VINDO AO ESPETACULAR JOGO DE BATALHA NAVAL ###\n\n");

    printf("LEGENDA:\n0 = ÁGUA\n1 = AÇÃO DA HABILIDADE ESPECIAL\n3 = NAVIO\n5 = NAVIO ATINGIDO PELA HABILIDADE\n\n");

    printf("TABULEIRO BATALHA NAVAL COM NAVIOS POSICIONADOS\n");
    imprimirTabuleiro(tabuleiroBatalhaNaval);
    
    printf("\n");

    printf("*** HABILIDADE ESPECIAL CONE ***\n");
    dispararHabilidadeEspecialCone();

    printf("\n");

    printf("*** HABILIDADE ESPECIAL CRUZ ***\n");
    dispararHabilidadeEspecialCruz();

    printf("\n");

    printf("*** HABILIDADE ESPECIAL OCTAEDRO ***\n");
    dispararHabilidadeEspecialOctaedro();

    printf("\nOBRIGADO POR JOGAR!\n");

    // Encerra o programa
    return 0;
}
