#include <iostream>
#include <algorithm>
#include "libs/RBT.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Error! Faltan argumentos.\n");
		printf("Usage: %s <cantidad_elementos>\n", argv[0]);
		return -1;
	}
	int n = (int) atoi(argv[1]);
	unsigned int data[n];
	RBT ordererData;
	RBT invertedData;
	RBT unordererData;
	
	for(unsigned int i = 0; i < n; i++){
		data[i] = i;
		ordererData.insert(i);
		invertedData.insert(n-i-1);
	}
	
	random_shuffle(data, data + n);

	for(unsigned int i = 0; i < n; i++){
		unordererData.insert(data[i]);
	}

	cout << "Búsquedas: " << endl;
	for(int i = -2; i < 2+n; i++){
		cout << "Buscar " << i << " -> " << unordererData.isInserted(i) << endl;
	}
	
	cout << "RBT con los datos ordenados: " << endl;
	ordererData.printTree();
	
	cout << "RBT con los datos invertidos: " << endl;
	invertedData.printTree();
	
	cout << "RBT con los datos desordenados: " << endl;
	unordererData.printTree();

	cout << "Altura de datos ordenados: " << ordererData.altura() << endl;
	cout << "Altura de datos desordenados: " << unordererData.altura() << endl;

	return 0;

	cout << "Ingresar nodo a rotar a la izquierda: ";
	int b;
	cin >> b;
	unordererData.leftRotation(b);

	cout << "Luego de rotar nodo " << b << endl;;
	unordererData.printTree();

	cout << "Ingresar nodo a rotar a la derecha: ";
	cin >> b;
	unordererData.rightRotation(b);

	cout << "Luego de rotar nodo " << b << endl;;
	unordererData.printTree();
	
}