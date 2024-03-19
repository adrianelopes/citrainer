#include <iostream>
#include "../includes/Aluno.h"
#include "../includes/Treino.h"
#include "../includes/Medidas.h"
#include <iomanip>

using namespace std;

Aluno::Aluno(){}
Aluno::~Aluno(){}

Aluno::Aluno(string nomeCompleto, int idade, string data, string bairro, string cidade, string rua, string cep, int numero, Medidas medidas, Treino treinos):Endereco(nomeCompleto, idade, data, bairro, cidade, rua, cep, numero)
{
  
  this->medidas = medidas;
  this->treinos = treinos;
}

void Aluno::exibir()
{
  cout << "------- Dados Pessoais -------\n";
  cout << "Nome: " << nomeCompleto << endl;
  cout << "Idade: " << idade << endl;
  cout << "Data de nascimento: " << dataDeNascimento << endl;
  exibirEndereco();
  medidas.exibir();
  treinos.exibir();
}

Medidas Aluno::getMedidas()
{
  return medidas;
}

void Aluno::setMedidas(Medidas medidas)
{
  this->medidas = medidas;
}

Treino Aluno::getTreino()
{
  return treinos;
}
  
void Aluno::setTreino(Treino treinos)
{
  this->treinos = treinos;
}


void Aluno::menu()
{
  int escolha;
  
  while(1)
  {
    
    cout << setw(40) << "MENU PRINCIPAL" << endl;
    cout << "---------------------------" << endl;

    cout << "   1 - Ver treinos"     << endl;
    cout << "   2 - Ver informações" << endl;
    cout << "   3 - Concluir treino" << endl;
    cout << "   4 - Sair"            << endl;

    cout << "---------------------------" << endl;

    cin >> escolha;

    if(escolha == 1){
      treinos.exibir();
    }

    else if(escolha == 2){
      cout << endl;
      cout << "------ Dados Pessoais -----" << endl;

      exibir();
      medidas.exibir();

      cout << endl;
    }
    
    else if(escolha == 3){

      if(treinoDoDia == 2)
        treinoDoDia = 0;

      else 
        treinoDoDia++;
        
      cout << "Muito bem! Esse é o treino de amanhã." << endl;
      treinos.treinoDoDia(treinoDoDia);
    }

    else if(escolha == 4){
        return;
    }

    else{
      cout << "Opção inválida. Insira uma opção válida." << endl;
    }
  }
}

string Aluno:: toStringAluno()
{
  string staluno = medidas.toStringMedidas() + "\n" + treinos.toStringTreino();

  return staluno;  
}