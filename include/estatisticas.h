/**
 * @file	estatisticas.h
 * @brief	arquivo cabecalho com os prototipos das funcoes que calculam 
					 estatisticas em relacao a tempo de execucao de algoritmos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	01/05/2017
 * @date	01/05/2017
 */


#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <cmath>
using std::pow;
using std::sqrt;

#define SEQUENCIA 20   						/**< Valor de tempos de execucao*/


/**
 * @brief Funcao que retorna o maior tempo de execucao
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				                           
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Maior tempo de execucao
 */
float max(int tam, float tempos[SEQUENCIA]);


/**
 * @brief Funcao que retorna o menor tempo de execucao
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Menor tempo de execucao
 */

float min(int tam, float tempos[SEQUENCIA]);


/**
 * @brief Funcao que retorna a media dos tempos de execucoes
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Media do tempo de execucao
 */
float media(int tam, float tempos[SEQUENCIA]);


/**
 * @brief Funcao que retorna o desvio padrao dos tempos de execucoes
 *					gasto pelo o algoritmo 	
 * @param tam Tamanho do vetor				
 * @param tempos Vetor com os valores dos tempos gastos
 * @return Desvio padrao do tempo de execucao
 */
float desv_padrao(int tam, float tempos[SEQUENCIA]);

#endif