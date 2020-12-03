#include <iostream>
#include <algorithm>
#include "libs/AVL.hpp"

using namespace std;

int main(int argc, char * argv[]){
	int n = 10;
	unsigned int data[n];
	AVL ordererData;
	AVL unordererData;
	
	cout << "Insercion de datos ordenados: " << endl;
	for(unsigned int i = 0; i < n; i++){
		data[i] = i;
		ordererData.insert(i);
	}
	
	random_shuffle(data, data + n);
	
	cout << "Insercion de datos desordenados: " << endl;
	for(unsigned int i = 0; i < n; i++){
		unordererData.insert(data[i]);
	}
	
	cout << "AVL con los datos desordenados: " << endl;
	unordererData.printTree();
	
	cout << "AVL con los datos ordenados: " << endl;
	ordererData.printTree();
	
	cout << "Búsquedas: " << endl;
	
	for(int i = -5; i < 5+n; i++){
		cout << "Buscar " << i << " -> " << unordererData.isInserted(i) << endl;
	}
	
}