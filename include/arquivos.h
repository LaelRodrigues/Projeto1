/**
 * @file	arquivos.h
 * @brief	implementacao de funcoes para realizam munipulacao 
 *					em arquivos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	30/04/2017
 * @date	01/05/2017
 */

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
 * @param entrada Variavel que referencia o arquivo de entrada
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
void testaArquivo(T &arquivo, string nome) {
	if(!arquivo) {
		cout << "Erro ao abrir o arquivo " << nome << endl;
		cout << "Programa finalizado." << endl;
		exit(1);
	}
}

#endif