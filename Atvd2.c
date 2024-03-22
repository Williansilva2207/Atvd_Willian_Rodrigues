#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10

void imprimirMatriz(int matriz[][COLUNAS], int linhas, int colunas);
void preencherMatriz(int matriz[][COLUNAS], int linhas, int colunas);
void preencherMatrizAleatoria(int matriz[][COLUNAS], int linhas, int colunas);
void somColuMatriz(int matriz[][COLUNAS], int v[], int linhas, int colunas);
void imprimirVetorComSoma(int v[], int colunas);
int main() {
  int linhas, colunas;
  int matriz[LINHAS][COLUNAS];
  int v[COLUNAS];

  srand(time(NULL));

  do
  {
    printf("Qual a quantidade de linhas? (valor entre 1 e %d): ", LINHAS);
    scanf("%d", &linhas);
  } while (linhas < 1 || linhas > LINHAS);

  do {
    printf("Qual a quantidade de colunas? (valor entre 1 e %d): ", COLUNAS);
    scanf("%d", &colunas);
  } while (colunas < 1 || colunas > COLUNAS);

  preencherMatriz(matriz, linhas, colunas);
  imprimirMatriz(matriz, linhas, colunas);
  somColuMatriz(matriz, v, linhas, colunas);
  imprimirVetorComSoma(v, colunas);
  return 0;
}

// void imprimirVetor(int v[], int qtd) {
//   printf("[");
//   if (qtd > 0) {
//     printf("%d", v[0]);
//     for (int i = 1; i < qtd; ++i) {
//       printf(", %d", v[i]);
//     }
//   }
//   printf("]\n");
// }

void imprimirMatriz(int matriz[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      printf("%4d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void preencherMatriz(int matriz[][COLUNAS], int linhas, int colunas) {
  printf("Digite os valores para preencher a matriz\n");
  for (int i = 0; i < linhas; ++i)
  {
    for (int j = 0; j < colunas; ++j) {
      printf("matriz[%d][%d] = ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void preencherMatrizAleatoria(int matriz[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      matriz[i][j] = rand() % (2 * linhas * colunas) + 1;
    }
  }
}

void somColuMatriz(int matriz[][COLUNAS], int v[], int linhas, int colunas){
    for(int i = 0; i < colunas; i++){
        int acumulador = 0;
        for(int j = 0; j < linhas; j++){
            acumulador += matriz[j][i];
            v[i] = acumulador;
        }
    }
    for(int i = 0; i < linhas; i++){
        matriz[i][colunas-1] = v[i];
    }
}
void imprimirVetorComSoma(int v[], int colunas) {
  printf("Subtotais:\n");
  for (int i = 0; i < colunas; ++i){
    if(i==0){
        printf("%d", v[i]);
    }
    else{
        printf(",%d", v[i]);
    }
  }
  printf("\n");
}