#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct Paciente{
  char nome[50];
  char cpf[11];
  char vacina[20];
  char data[10];
  char lote[15];
};
struct Paciente save[9999];

int stand = 0; /*variável "stand" representando index*/

void escolha(int option);

void Ler_e_cadastrar(struct Paciente save[]);

void listar(struct Paciente save[]);

void procurar();

void pesquisa_em_vetor(char* busca);

int main(){ 
  int option = 0;
  setlocale(LC_ALL, "Portuguese");
  do{
    printf("\n\n");
    printf("Digite uma opção\n");
    printf("1 - Cadastrar Vacinação\n");
    printf("2 - Listar Aplicações\n");
    printf("3 - Consultar por CPF\n");
    printf("4 - Sair\n\n");
    scanf("%d", &option);
    escolha(option);}
    while(option != 4);
    return 0;
};

void escolha(int option){
  switch (option){
      case 1:{
        Ler_e_cadastrar(&save[stand]);
        stand++;
        break;
      }
      case 2:{
        listar(&save[stand]);
        break;
      }
      case 3:{
        procurar(&save[stand]);
        break;
      }
      case 4:{
        printf("Finalizando.\n");
        break;
      }
      default:{
        printf("Opção inválida.\n");
        break;
      }
    };
}

void Ler_e_cadastrar(struct Paciente save[]){
  system("clear");

  printf("Digite o nome do paciente.\n");
  fflush(stdin);
  scanf(" %50[^\n]s",save[stand].nome);

  printf("Digite o CPF do Paciente.\n");
  fflush(stdin);
  scanf(" %s", save[stand].cpf);

  printf("Digite o nome da Vacina.\n");
  fflush(stdin);
  scanf(" %20[^\n]s",save[stand].vacina);

  printf("Digite a data no formato \"DD/MM/AAAA\".\n");
  fflush(stdin);
  scanf(" %s", save[stand].data);

  printf("Digite o lote da vacina.\n");
  fflush(stdin);
  scanf(" %s", save[stand].lote);
};

void listar(struct Paciente save[]){
  system("clear");
  int i;
  if(stand == 0){
    printf("Ainda não há nenhum paciente cadastrado\n");
  }
  else{
    for(i = 0; i < stand; i++)
    {
      printf("---------------------------------------------------------------------\n");
      printf("Código : %d\n", i);
      printf("Nome: %s\n", save[i].nome);
      printf("CPF : %s\n", save[i].cpf);
      printf("Vacina: %s\n", save[i].vacina);
      printf("Data : %s\n", save[i].data);
      printf("Lote : %s\n", save[i].lote);
      printf("---------------------------------------------------------------------\n");
    }
  }
}

void procurar(){
  system("clear");
  char busca[11];
  printf("Digite o CPF:\n");
  fflush(stdin);
  scanf(" %s", busca);
  pesquisa_em_vetor(busca);
}

void pesquisa_em_vetor(char* busca){
  int i, achei;
  achei = 0;
  while((achei == 0) && (i < stand)){
    if(strcmp(save[i].cpf, busca))
    {
      achei = 1;
    }
    else
    {
      i++;
    }
  }
  if(achei == 1){
      printf("---------------------------------------------------------------------\n");
      printf("Encontrado, registrado no stand %d sobre o nome de %s", i, save[i].nome);
      printf("---------------------------------------------------------------------\n");
  }
  else{
    printf("Não foi encontrado nenhum registro desse CPF.");
  }
};
