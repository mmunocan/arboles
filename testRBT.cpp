#include <iostream>
#include <algorithm>
#include "libs/RBT.hpp"

using namespace std;

int main(int argc, char * argv[]){
	int n = 10;
	unsigned int data[n];
	RBT ordererData;
	RBT unordererData;
	
	for(unsigned int i = 0; i < n; i++){
		data[i] = i;
		ordererData.insert(i);
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
	
	cout << "RBT con los datos desordenados: " << endl;
	unordererData.printTree();

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

	cout << "Fin!" << endl;
	
}