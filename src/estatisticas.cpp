/**
 * @file	estatisticas.cpp
 * @brief	implementacao das funcoes que calculam estatisticas
					em relacao a tempo de execucao de algoritmos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	01/05/2017
 * @date	01/05/2017
 */


#include "estatisticas.h"


/**
 * @brief Funcao que retorna o maior tempo de execucao
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				                           
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Maior tempo de execucao
 */
float max(int tam, float tempos[SEQUENCIA]) {

	float maior = tempos[0];
	for(int i = 1; i < tam; i++) {
		if(tempos[i] > maior) {
			maior = tempos[i];
		}
	}
	return maior;
}


/**
 * @brief Funcao que retorna o menor tempo de execucao
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Menor tempo de execucao
 */
float min(int tam, float tempos[SEQUENCIA]) {

	float menor = tempos[0];
	for(int i = 1; i < tam; i++) {
		if(tempos[i] <  menor) {
			menor = tempos[i];
		}
	}
	return menor;
}


/**
 * @brief Funcao que retorna a media dos tempos de execucoes
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Media do tempo de execucao
 */
float media(int tam, float tempos[SEQUENCIA]) {

	float soma = 0.0;
	for(int i = 0; i < tam; i++) {
		soma = soma + tempos[i];
	}

	return (float)soma/tam; 
}


/**
 * @brief Funcao que retorna o desvio padrao dos tempos de execucoes
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Desvio padrao do tempo de execucao
 */
float desv_padrao(int tam, float tempos[SEQUENCIA]) {

	float m = media(tam, tempos);
	float dp = 0.0;

	for(int i = 0; i < tam; i++) {
		dp += pow(tempos[i] - m, 2);
	}

	return (float)sqrt(dp/tam);
}
