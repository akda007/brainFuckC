#include <stdio.h>
#include <string.h>


typedef struct {
  char nome[50];
  int ano;

} Carro;


int main() {

  Carro carros[10];

  
  strcpy(carros[0].nome, "Fusca");
  carros[0].ano = 1982;

  strcpy(carros[1].nome, "Compass");
  carros[1].ano = 2018;

  for (int i = 0; i < 10; i++) {
    printf("%s | %d\n", carros[i].nome, carros[i].ano);
  }

  return 0;
}
