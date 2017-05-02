/**
 * @file	arquivos.h
 * @brief	implementacao de funcoes para realizam munipulacoes
 *					em arquivos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	30/04/2017
 * @date	01/05/2017
 */


#include "estatisticas.h"
#include "multmatrizes.h"

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <string>
using std::string;
using std::getline;

#include <cstdlib>
using  std::exit;

#include <iostream>
using std::endl;
using std::cout;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <chrono>
using std::ratio;


/**
 * @brief Funcao que realiza a leitura de dados de um arquivo
 *				e armazena em uma matriz 
 * @param entrada Variavel que referencia o arquivo de entrada
 * @param matriz Matriz que armazenara os dados lidos
 * @param n Dimensoes da matriz
 */
template<typename T>
void lerMatriz(ifstream &entrada, T **matriz, int n) {

	string linha1;

	getline(entrada, linha1);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			entrada >> matriz[i][j];
		}
	}
}

/**
 * @brief Funcao que imprimi em um arquivo os elementos
 *				de uma matriz
 * @param saida Variavel que referencia o arquivo de saida
 * @param matriz Matriz que armazenara os dados lidos
 * @param n Dimensoes da matriz
 */
template<typename T>
void gerar_matriz_arquivo(ofstream &saida, T **matriz, int n) {

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			saida << matriz[i][j] << " ";
		}
		saida << endl;
	}
}


/**
 * @brief Funcao para testar se o arquivo eh valido
 * @param arquivo stream de entrada ou saida
 */
template <typename T>
void testaArquivo(T &arquivo) {
	if(!arquivo) {
		cout << "Erro ao abrir o arquivo " << endl;
		cout << "Programa finalizado." << endl;
		exit(1);
	}
}


/**
 * @brief Funcao para gerar estatisticas em relacao ao tempo
 *				de execucao dos algoritmos recursivo e iterativo
 * @param A Matriz de entrada
 * @param B Matriz de entrada 
 * @param tam Dimensao das matrizes
 */
template <typename T>
void gerarEstatisticas(T **A, T**B, int tam) {

	ofstream arqIterativo("../output/stats-ite.dat");
	testaArquivo(arqIterativo);

	float tempos[SEQUENCIA];
	int **C;

	for(int i = 0; i < SEQUENCIA; i++) {

		auto tempo_ini = std::chrono::high_resolution_clock::now();
		C = multiplicaI(A, B, tam);
		auto tempo_fim = std::chrono::high_resolution_clock::now();
		tempos[i] = std::chrono::duration<double, ratio<60>>(tempo_fim - tempo_ini).count();
	}

	float maior, menor, md, desv;
	
	maior = max(SEQUENCIA, tempos);
	menor = max(SEQUENCIA, tempos);
	md = media(SEQUENCIA, tempos);
	desv = desv_padrao(SEQUENCIA, tempos);

	arqIterativo << tam << " " << maior << " " << menor;
	arqIterativo << md << " " << desv << endl;

	arqIterativo.close();

	ofstream arqRecursivo("../output/stats-rec.dat");
	testaArquivo(arqRecursivo);

	for(int i = 0; i < SEQUENCIA; i++) {
		auto tempo_ini = std::chrono::high_resolution_clock::now();
		C = multiplicaR(A, B, tam);
		auto tempo_fim = std::chrono::high_resolution_clock::now();
		tempos[i] = std::chrono::duration<double, ratio<60>>(tempo_fim - tempo_ini).count();
	}

	for(int i = 0; i < tam; i++) {
		delete [] C[i];
	}

	delete [] C;

	maior = max(SEQUENCIA, tempos);
	menor = max(SEQUENCIA, tempos);
	md = media(SEQUENCIA, tempos);
	desv = desv_padrao(SEQUENCIA, tempos);

	arqRecursivo << tam << " " << maior << " " << menor;
	arqRecursivo << md << " " << desv << endl;

	arqRecursivo.close();
}
#endif
