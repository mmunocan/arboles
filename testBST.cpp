#include <iostream>
#include <algorithm>
#include "libs/BST.hpp"

using namespace std;

int main(int argc, char * argv[]){
	int n = 10;
	unsigned int data[n];
	BST ordererData;
	BST unordererData;
	
	for(unsigned int i = 0; i < n; i++){
		data[i] = i;
		ordererData.insert(i);
	}
	
	random_shuffle(data, data + n);
	
	cout << "Numeros desordenados: " << endl;
	for(unsigned int i = 0; i < n; i++){
		unordererData.insert(data[i]);
		cout << data[i] << " - " ;
	}
	cout << endl;
	
	cout << "BST con los datos desordenados: " << endl;
	unordererData.printTree();
	
	cout << "BST con los datos ordenados: " << endl;
	ordererData.printTree();

	cout << "Búsquedas: " << endl;
	for(int i = -5; i < 5+n; i++){
		cout << "Buscar " << i << " -> " << unordererData.isInserted(i) << endl;
	}
	
}