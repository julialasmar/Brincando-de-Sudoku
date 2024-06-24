#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define linha_matriz 9
#define coluna_matriz 9

int lista_matriz(int matriz[linha_matriz][coluna_matriz]) {
  for (int i = 0; i < linha_matriz; i++) {
    if (i > 0 && i % 3 == 0) {
      printf("\n");
    }
    for (int j = 0; j < coluna_matriz; j++) {
      if (j > 0 && j % 3 == 0) {
        printf("  ");
      }
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int repeticao_matriz(int matriz[linha_matriz][coluna_matriz], int indice_linha,
                     int indice_coluna) {

  int repetido = 0;

  // inicio do IF que lista repeticao na matriz toda
  if (indice_linha == 0 && indice_coluna == 0) {
    for (int i = 0; i < linha_matriz; i++) {
      for (int j = 0; j < coluna_matriz; j++) {
        for (int k = 0; k < linha_matriz; k++) {
          if (k != j && matriz[i][k] == matriz[i][j]) {
            repetido = 1;
            break;
          }
          if (k != i && matriz[k][j] == matriz[i][j]) {
            repetido = 1;
            break;
          }
        }
        if (repetido) {
          break;
        }
      }
      if (repetido) {
        break;
      }
    }
    // inicio do if que lista repeticao na linha
  } else if (indice_linha != 0 && indice_coluna == 0) {
    for (int i = 0; i < coluna_matriz; i++) {
      for (int j = i + 1; j < coluna_matriz; j++) {
        if (matriz[indice_linha][i] == matriz[indice_linha][j]) {
          repetido = 1;
          break;
        }
      }
    }
    // inicio que lista repeticao na coluna
  } else if (indice_linha == 0 && indice_coluna != 0) {
    for (int i = 0; i < linha_matriz; i++) {
      for (int j = i + 1; j < linha_matriz; j++) {
        if (matriz[i][indice_coluna] == matriz[j][indice_coluna]) {
          repetido = 1;
          break;
        }
      }
    }
  }

  if (repetido) {
    printf("S\n");
  } else {
    printf("N\n");
  }
}

int repeticao_quadrante(int matriz[linha_matriz][coluna_matriz], int startX,
                        int startY) {

  int contagem[10] = {0};
  int repetido = 0;
  for (int i = startX; i < startX + 3; i++) {
    for (int j = startY; j < startY + 3; j++) {
      int num = matriz[i][j];
      if (num < 1 || num > 9 || contagem[num] > 0) {
        repetido = 1;
        break;
      }
      contagem[num]++;
    }
  }
  if (repetido) {
    printf("S\n");
  } else {
    printf("N\n");
  }
}

int main() {

  int opcao = 1;
  int indice_linha = 0;
  int indice_coluna = 0;
  int indice_quadrante = 0;
  int linha_quandrante = 0;
  int coluna_quandrante = 0;
  int novo_valor = 0;
  int repetido = 0;
  int matriz[linha_matriz][coluna_matriz];

  for (int i = 0; i < linha_matriz; i++) {
    for (int j = 0; j < coluna_matriz; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
  while (opcao != 0) {

    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      break;

    case 1:
      // atualiza o indice
      scanf("%d", &indice_linha);
      scanf("%d", &indice_coluna);
      scanf("%d", &novo_valor);
      matriz[indice_linha][indice_coluna] = novo_valor;
      break;

    case 2:
      // verificar a linha
      scanf("%d", &indice_linha);
      repeticao_matriz(matriz, indice_linha, 0);
      break;

    case 3:
      // verificar a coluna
      scanf("%d", &indice_coluna);
      repeticao_matriz(matriz, 0, indice_coluna);
      break;

    case 4:
      // verificar o quadrante
      scanf("%d", &indice_quadrante);
      switch (indice_quadrante) {
      case 0:
        linha_quandrante = 0;
        coluna_quandrante = 0;
        break;
      case 1:
        linha_quandrante = 0;
        coluna_quandrante = 3;
        break;
      case 2:
        linha_quandrante = 0;
        coluna_quandrante = 6;
        break;
      case 3:
        linha_quandrante = 3;
        coluna_quandrante = 0;
        break;
      case 4:
        linha_quandrante = 3;
        coluna_quandrante = 3;
        break;
      case 5:
        linha_quandrante = 3;
        coluna_quandrante = 6;
        break;
      case 6:
        linha_quandrante = 6;
        coluna_quandrante = 0;
        break;
      case 7:
        linha_quandrante = 6;
        coluna_quandrante = 3;
        break;
      case 8:
        linha_quandrante = 6;
        coluna_quandrante = 6;
        break;
      default:
        linha_quandrante = 0;
        coluna_quandrante = 0;
      }
      repeticao_quadrante(matriz, linha_quandrante, coluna_quandrante);
      break;

    case 5:
      // verificar a matriz
      repeticao_matriz(matriz, 0, 0);
      break;

    default:
      lista_matriz(matriz);
      break;
    }
  }
  return 0;
}