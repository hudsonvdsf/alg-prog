#include <stdio.h>

#define TAMANHO 24

// Função para gerar valores simulando o consumo da maquina ao longo do dia
void gerarValores(int valores[]) {
  int max = 200;
  int min = 20;
  int mid = TAMANHO / 2;

  for (int i = 0; i < mid; i++) {
    valores[i] = min + (max - min) * i / (mid - 1);
  }
  for (int i = mid; i < TAMANHO; i++) {
    valores[i] = valores[TAMANHO - i - 1];
  }
}

// Função para encontrar o valor máximo em um array
int encontrarMaximo(int valores[], int tamanho) {
  int max = valores[0];
  for (int i = 1; i < tamanho; i++) {
    if (valores[i] > max) {
      max = valores[i];
    }
  }
  return max;
}

// Função para encontrar o valor mínimo em um array
int encontrarMinimo(int valores[], int tamanho) {
  int min = valores[0];
  for (int i = 1; i < tamanho; i++) {
    if (valores[i] < min) {
      min = valores[i];
    }
  }
  return min;
}

// Função para imprimir os valores gerados
void imprimirValores(int valores[], int tamanho) {
 printf("\nValores de consumo ao longo do dia:\n");
 for (int i = 0; i < tamanho; i++) {
 printf("Hora %2d, valor= %3d\n", i, valores[i]);
 }
}

// Função para desenhar o eixo X do gráfico
void desenharEixoX(int tamanho) {
 printf(" ");
 for (int i = 0; i < tamanho; i++) {
 printf("---");
 }
 printf("\n ");
 for (int i = 0; i < tamanho; i++) {
 printf("%2d ", i);
 }
}

// Função para desenhar o gráfico de consumo
void desenharGrafico(int valores[], int tamanho) {
 int max = encontrarMaximo(valores, tamanho);
 for (int i = max; i >= 0; i -= 10) {
 printf("%4d | ", i);
 for (int j = 0; j < tamanho; j++) {
 if (valores[j] >= i) {
 printf(" * ");
 } else {
 printf(" ");
 }
 }
 }
 desenharEixoX(tamanho);
}

int main() {
 int valores[TAMANHO];

 // Gera os valores simulando o consumo ao longo do dia
 gerarValores(valores);

 // Imprime os valores gerados
 imprimirValores(valores, TAMANHO);

 // Desenha o gráfico
 printf("Grafico dos valores de consumo registrados ao longo do dia: ");
 desenharGrafico(valores, TAMANHO);

 // Encontra e imprime o valor máximo e mínimo
 int max = encontrarMaximo(valores, TAMANHO);
 int min = encontrarMinimo(valores, TAMANHO);
 printf("Valor maximo de consumo: %d\n", max);
 printf("Valor minimo de consumo: %d\n", min);

 return 0;
}
