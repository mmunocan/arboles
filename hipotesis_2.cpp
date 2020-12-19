#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include "libs/AVL.hpp"
#include "libs/RBT.hpp"
#include "libs/BST.hpp"

using namespace std;

// Hipóstesis 2:
//	El BST presenta una altura mayor que los árboles balanceados, cuando 
//	los datos se insertan de manera aleatoria. El AVL tendrá una altura 
//	menor que el RBT.

// La prueba se realiza con arreglos de valores generados de manera 
// secuencial que luego se mezclan
// Se consideran elementos de x*(10^5), con x de 1 a 10.
// La cantidad de repeticiones depende del argumento entregado
int * medirAlturas(int cantValores);

int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("Error! Faltan argumentos.\n");
		printf("Usage: %s <repeticiones>\n", argv[0]);
		printf("Salida: tiempoBST tiempoAVL tiempoRBT.\n");
		return -1;
	}
	int repeticiones = (int) atoi(argv[1]);

	int* aux;
	double alturas[] = {0.0,0.0,0.0};
	cout << "%n*10^5\tbst\tavl\trbt" << endl;
	int cantValores;
	for(int i=1; i<=10; i++){
		cantValores = i * 100000;
		for(int j=0; j<repeticiones; j++){
			aux = medirAlturas(cantValores);
			alturas[0] += aux[0];
			alturas[1] += aux[1];
			alturas[2] += aux[2];
		}
		cout << i << "\t" << (alturas[0]/repeticiones) << "\t" << (alturas[1]/repeticiones) << "\t" << (alturas[2]/repeticiones) << endl;
		free(aux);
	}
	return 0;
}

int * medirAlturas(int cantValores){
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

	// Arreglo con las alturas
	int* alts = (int*) malloc(sizeof(int)*3);
	alts[0] = arbolBB.altura();
	alts[1] = arbolAVL.altura();
	alts[2] = arbolRN.altura();

	return alts;
}