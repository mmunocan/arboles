#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include "libs/AVL.hpp"
#include "libs/RBT.hpp"
#include "libs/BST.hpp"

using namespace std;

// Hipóstesis 3:
//	El BST presenta un tiempo de inserción mayor que los árboles
//	balanceados al insertar datos en secuencia creciente. El AVL 
//	tarda menos tiempo que BST y más que RBT en el mismo escenario.

// La prueba se realiza con arreglos de valores generados de manera 
// secuencial que luego se mezclan
// Se consideran elementos de x*(10^5), con x de 1 a 10.
double * tomarTiempos(int cantValores);

int main(int argc, char const *argv[]){
	double* aux;
	cout << "%n*10^5\tbst\tavl\trbt" << endl;
	int cantValores;
	for(int i=1; i<=10; i++){
		cantValores = i * 100000;
		aux = tomarTiempos(cantValores);
		cout << i << "\t" << aux[0] << "\t" << aux[1] << "\t" << aux[2] << endl;
		free(aux);
	}
	return 0;
}

double * tomarTiempos(int cantValores){
	// Declaración de las estructuras de árbol
	BST arbolBB;
	AVL arbolAVL;
	RBT arbolRN;	

	// Arreglo con los tiempos
	double* ms = (double*) malloc(sizeof(double)*3);
	ms[0] = 0.0;
	ms[1] = 0.0;
	ms[2] = 0.0;

	// Toma de tiempo en inserciones sobre BST
	clock_t t_0 = clock();
	for(int i=1; i <= cantValores; i++){
		arbolBB.insert(i);
	}
	ms[0] = (double)(clock() - t_0) / CLOCKS_PER_SEC;

	// Toma de tiempo en inserciones sobre AVL
	clock_t t_1 = clock();
	for(int i=1; i <= cantValores; i++){
		arbolAVL.insert(i);
	}
	ms[1] = (double)(clock() - t_1) / CLOCKS_PER_SEC;

	// Toma de tiempo en inserciones sobre RBT
	clock_t t_2 = clock();
	for(int i=1; i <= cantValores; i++){
		arbolRN.insert(i);
	}
	ms[2] = (double)(clock() - t_2) / CLOCKS_PER_SEC;

	// Transformar valores de segundos a milisegundos
	ms[0] = ms[0]*1000;
	ms[1] = ms[1]*1000;
	ms[2] = ms[2]*1000;

	return ms;
}