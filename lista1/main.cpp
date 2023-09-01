/*
João Marcos Brito Matias - 494952
Matemática e fis para jogos

Programa compilado com as seguintes flags
g++ -Wall -Wextra -std=c++17 -pedantic

A primeira função responde a questão 4
A segunda função responde a questão 5
A terceira função e a main respondem a questão 6

*/

#include <cmath>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

/*
Ideia para converter qualquer número de uma base para outra:
        Transformar primeiro a entrada em decimal
        Depois tranforma o decimal na base da saida desejada
*/

// QUESTÃO 4
int converter_para_decimal(string entrada, int base) {
  int resultado = 0;
  int n = entrada.size();
	int valor;
	
  // Cada posição do numéro é multplicado por sua base elevada pela sua posição
  // (começando a contar do zero) Depois esses valores são somados
  for (int i = n - 1; i >= 0; i--) {

    if ((int)entrada[i] - 48 > 9) {
      valor = (int)toupper(entrada[i]) - 55;
    }

    else
      valor = (int)entrada[i] - 48;

    resultado = resultado + valor * pow(base, n - i - 1);
  }

  return resultado;
}

// QUESTÃO 5
string converter_decimal(int entrada, int base) {
  string saida;
	char valor;
	
  // Equanto o valor não chegar a zero,
  // o resto da divisão do valor pela base será armazenada a primeira posição da
  // string e o valor é atualizado para a divisão inteira dele com a base
  while (entrada != 0) {

		if(entrada%base > 9) {valor = (char)(entrada % base + 55);}
		else valor = (char)(entrada % base + 48);
		
    saida.insert(saida.begin(), valor);
    entrada = (int)(entrada / base);
  }
  return saida;
}

// QUESTÃO 6
string converter(string entrada, int base_entrada, int base_saida) {

  // Retornando o resultado de convertear a entrada para decimal
  //    e decimal para a base que foi solicitada como saida
  return converter_decimal(converter_para_decimal(entrada, base_entrada),
                           base_saida);
}

int main() {
	int base;
  string entrada;
  int base_saida;


  //Recendo as entradas
  cout << "Conversor de números\n\n";

  cout << "Digite a base do valor da entrada (maior que 1): ";
  cin >> base;

  if (base <= 1) {cout << "A base não é válida\n"; return 1;}

  cout << "Digite o valor na base " << base << ": ";
  cin >> entrada;

  cout << "Digite a base do valor de saída(maior que 1): ";
  cin >> base_saida;

  if (base_saida <= 1){ cout << "A base não é válida\n"; return 1;}

  //Imprimindo o resultado da converção
  cout << "Resultado: " << 	converter(entrada,base,base_saida) << "\n";
  

}