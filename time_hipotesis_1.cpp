#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include "libs/AVL.hpp"
#include "libs/RBT.hpp"
#include "libs/BST.hpp"

using namespace std;

// Hipóstesis 1:
//	El AVL presenta un tiempo de consulta menor que RBT cuando los datos se insertan de manera aleatoria.

// La prueba se realiza con arreglos de valores generados de manera 
// secuencial que luego se mezclan
// Se consideran elementos de x*(10^6), con x de 1 a 10.
// La cantidad de consultas depende del argumento entregado
double * tomarTiempos(int cantValores, int cantConsultas);

int main(int argc, char const *argv[]){
	clock_t t_0 = clock();
	if(argc < 2){
		printf("Error! Faltan argumentos.\n");
		printf("Usage: %s <cantidad_consultas>\n", argv[0]);
		printf("Salida: tiempoBST tiempoAVL tiempoRBT.\n");
		return -1;
	}
	int cantConsultas = (int) atoi(argv[1]);

	double* aux;
	cout << "%n*10^6\tbst\tavl\trbt" << endl;
	int cantValores;
	for(int i=1; i<=10; i++){
		cantValores = i * 1000000;
		aux = tomarTiempos(cantValores, cantConsultas);
		cout << i << "\t" << aux[0] << "\t" << aux[1] << "\t" << aux[2] << endl;
		free(aux);
	}
	return 0;
}

double * tomarTiempos(int cantValores, int cantConsultas){
	// Arreglo con los valores a insertar de 1 a cantValores
	int* valores = (int*) malloc(sizeof(int)*cantValores);
	if(valores == NULL){
		cout << "Error en la reserva de memoria." << endl;
		return NULL;
	}
	for(int i=0; i<cantValores; i++){
		valores[i] = i+1;
	}
	random_shuffle(valores, valores + cantValores);

	// Inserción de valores en los árboles
	BST arbolBB;
	AVL arbolAVL;
	RBT arbolRN;
	for(int i=0; i<cantValores; i++){
		arbolBB.insert(valores[i]);
		arbolAVL.insert(valores[i]);
		arbolRN.insert(valores[i]);
	}

	free(valores);

	// Arreglo con valores de consultas con valores entre 1 y cantValores
	int* consultas = (int*) malloc(sizeof(int)*cantConsultas);
	srand (time(NULL));
	for(int i=0; i<cantConsultas; i++){
		consultas[i] = rand() % cantValores + 1;
	}

	// Arreglo con los tiempos
	double* ms = (double*) malloc(sizeof(double)*3);
	ms[0] = 0.0;
	ms[1] = 0.0;
	ms[2] = 0.0;

	// Toma de tiempo en consultas sobre BST
	clock_t t_0 = clock();
	for(int i=0; i<cantConsultas; i++){
		arbolBB.isInserted(consultas[i]);
	}
	ms[0] = (double)(clock() - t_0) / CLOCKS_PER_SEC;

	// Toma de tiempo en consultas sobre AVL
	clock_t t_1 = clock();
	for(int i=0; i<cantConsultas; i++){
		arbolAVL.isInserted(consultas[i]);
	}
	ms[1] = (double)(clock() - t_1) / CLOCKS_PER_SEC;

	// Toma de tiempo en consultas sobre RBT
	clock_t t_2 = clock();
	for(int i=0; i<cantConsultas; i++){
		arbolRN.isInserted(consultas[i]);
	}
	ms[2] = (double)(clock() - t_2) / CLOCKS_PER_SEC;

	// Transformar valores de segundos a milisegundos
	ms[0] = ms[0]*1000;
	ms[1] = ms[1]*1000;
	ms[2] = ms[2]*1000;

	free(consultas);
	return ms;
}