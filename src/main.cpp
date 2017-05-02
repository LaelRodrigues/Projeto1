/** 
 * @file	main.cpp
 * @brief   Codigo fonte para teste das funcoes 
 * 			
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	30/04/2017
 * @date	01/05/2017
 */

#include <sstream>
using std::ostringstream;

#include <cstdlib>
using std::atoi;
using std::exit;

#include "estatisticas.h"
#include "multmatrizes.h"
#include "arquivos.h"

/**
 * @brief Funcao principal
 */
int main(int argc, char* argv[]){
	

	if(argc != 11){
		cout << "Erro na execucao" << endl;
		cout << "Digite: ./multimat e depois 10 valores potencia de 2 elevado a n(para n>0 e n<=10)" << endl;
		exit(1);
	}	

	int cont = 0;
	int paramentro;

	
	for(int i = 1; i < argc; i++){
	
		paramentro = atoi(argv[i]);

		if(paramentro <= 1 || paramentro > 1024){
			cout << "Erro na execucao" << endl;
			cout << "Digite: ./multimat e depois 10 valores potencia de 2 elevado a n(para n>0 e n<=10)";
			exit(1);
		}
		while(paramentro != 2) {
			paramentro = paramentro / 2;
			if(paramentro % 2 != 0){
				cont++;
				break;
			} 
		}
		if(cont != 0){
			cout << "Erro na execucao" << endl;
			cout << "Digite: ./multimat e depois 10 valores potencia de 2 elevado a n(para n>0 e n<=10)" << endl;
			exit(1);
		}
	}

	int tam;
	for(int i = 1; i < argc; i++) {
		
		tam = atoi(argv[i]);

		int **A = new int*[tam];
  		int **B = new int*[tam];
		for(int j = 0; j < tam; j++){
    		A[j] = new int[tam];
    		B[j] = new int[tam];
  		}    
  		
  		int **C = NULL;
  		ostringstream n;

  		n << tam;
  		string arquivo = "../input/A"+n.str()+"x"+n.str()+".txt";
  		ifstream arqMatrizA(arquivo.c_str());
  		testaArquivo(arqMatrizA);
  		lerMatriz(arqMatrizA, A, tam);

  		arqMatrizA.close();

  		arquivo = "../input/B"+n.str()+"x"+n.str()+".txt";
  		ifstream arqMatrizB(arquivo.c_str());
  		testaArquivo(arqMatrizB);
		lerMatriz(arqMatrizB, B, tam);

		arqMatrizB.close();

		C = multiplicaR(A, B, tam);

		arquivo = "../output/C"+n.str()+"x"+n.str()+".txt";
		ofstream saidaMatrizC(arquivo.c_str());
		testaArquivo(saidaMatrizC);
		gerar_matriz_arquivo(saidaMatrizC, C, tam);

		saidaMatrizC.close();

		gerarEstatisticas(A, B, tam);

		for(i = 0; i < tam; i++) {
			delete [] A[i];
			delete [] B[i];
			delete [] C[i];
		}
		delete [] A;
		delete [] B;
		delete [] C;
	}
}
