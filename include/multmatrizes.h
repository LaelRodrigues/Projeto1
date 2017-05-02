/**
 * @file	multmatrizes.h
 * @brief	implementacao das funcaes que realizam a multiplicacao 
 					entre duas matrizes e gera uma matriz resultando 
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/04/2017
 * @date	01/04/2017
 */


#ifndef MULTMATRIZ_H
#define MULTMATRIZ_H

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::exit;

/**
* @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma iterativa
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao
*/
template <typename T>
T** multiplicaI(T** A, T** B, int n){
	
	T **matrizResut = new T*[n];

	if(matrizResut == NULL) {
		cout << "Memoria nao alocada!!" << endl;
		exit(1);
	}
	
	for(int i = 0; i < n; i++){
		matrizResut[i] = new T[n];
		if(matrizResut[i] == NULL){
			cout << "Memoria nao alocada!!" << endl;
			exit(1); 
		}
	}
	
	T soma;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			soma = (T)0;
			for(int k = 0; k < n; k++){
				soma += A[i][k] * B[k][j]; 
			}
			matrizResut[i][j] = soma;
		}
	}
	return matrizResut;
}

 

/**
* @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma recursiva
* @param A Matriz de entrada
* @param B Matriz de entrada 
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao 
*/
template <typename T>
T** multiplicaR(T** A, T** B, int n){
     
    //Particionamento das matrizes
	T **A11 = new T*[n/2], **A12 = new T*[n/2], **A21 = new T*[n/2], **A22 = new T*[n/2];
	T **B11 = new T*[n/2], **B12 = new T*[n/2], **B21 = new T*[n/2], **B22 = new T*[n/2];
	T **C11 = new T*[n/2], **C12 = new T*[n/2], **C21 = new T*[n/2], **C22 = new T*[n/2];

	for(int i = 0; i < n/2; i++){
		A11[i] = new T[n/2], A12[i] = new T[n/2], A21[i] = new T[n/2], A22[i] = new T[n/2];
		B11[i] = new T[n/2], B12[i] = new T[n/2], B21[i] = new T[n/2], B22[i] = new T[n/2];
		C11[i] = new T[n/2], C12[i] = new T[n/2], C21[i] = new T[n/2], C22[i] = new T[n/2];
	}

	T **C = new T*[n];

	for(int i = 0; i < n; i++) {
		C[i] = new T[n];
	} 

	T **P1, **P2, **P3, **P4, **P5, **P6, **P7, **P8;
	//Caso base
	if(n == 1) {  
		for(int i=0; i<1; i++) {
			for(int j=0; j<1; j++) {
				T soma = (T)0;      
				for(int k=0; k<1; k++) {
	  				soma += A[i][k] * B[k][j];        
				}
				C[i][j] = soma;  
			}        
		}
	} 
	else {
		//Atribuicao dos valores das Matrizes A e B em suas respectivas sub-matrizes
		for(int i=0; i<n/2; i++) {
			for(int j=0; j<n/2; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j+n/2];
				A21[i][j] = A[i+n/2][j];
				A22[i][j] = A[i+n/2][j+n/2];	  
				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j+n/2];
				B21[i][j] = B[i+n/2][j];
				B22[i][j] = B[i+n/2][j+n/2];    
			}        
		}        

		//chamada recursiva para realizar a multiplicacao entre as sub-matrizes
		P1 = multiplicaR(A11, B11, n/2);
		P2 = multiplicaR(A12, B21, n/2);
		P3 = multiplicaR(A11, B12, n/2);
		P4 = multiplicaR(A12, B22, n/2);
		P5 = multiplicaR(A21, B11, n/2);
		P6 = multiplicaR(A22, B21, n/2);
		P7 = multiplicaR(A21, B12, n/2);
		P8 = multiplicaR(A22, B22, n/2);

		//Atribuicao dos produtos entre as sub-matrizes A e B nas sub-matrizes de C
		for(int i = 0; i < n/2; i++){
			for(int j = 0; j < n/2; j++){
				C11[i][j] = P1[i][j] + P2[i][j];
				C12[i][j] = P3[i][j] + P4[i][j];
				C21[i][j] = P5[i][j] + P6[i][j];
				C22[i][j] = P7[i][j] + P8[i][j];
			}
		}

		for(int i = 0; i < n/2; i++) {
			delete[] P1[i]; delete[] P2[i]; delete[] P3[i]; delete[] P4[i];
			delete[] P5[i]; delete[] P6[i]; delete[] P7[i]; delete[] P8[i];
		}

		delete[] P1; delete[] P2; delete[] P3; delete[] P4;
		delete[] P5; delete[] P6; delete[] P7; delete[] P8;

		//Unir as sub-matrizes de C a propria matriz C
		for(int i=0; i<n/2; i++) {
			for(int j=0; j<n/2; j++) {
		  		C[i][j] = C11[i][j];
		  		C[i][j+n/2] = C12[i][j];
				C[i+n/2][j] = C21[i][j];
				C[i+n/2][j+n/2] = C22[i][j];        
			}        
		}
	}
	
	for(int i = 0; i < n/2; i++){
		delete[] A11 [i]; delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
		delete[] B11 [i]; delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
		delete[] C11 [i]; delete[] C12[i]; delete[] C21[i]; delete[] C22[i];
	}

	delete[] A11; delete[] A12; delete[] A21; delete[] A22;
	delete[] B11; delete[] B12; delete[] B21; delete[] B22;
	delete[] C11; delete[] C12; delete[] C21; delete[] C22;

	return C;     
}

#endif
