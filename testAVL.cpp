#include <iostream>
#include <algorithm>
#include <ctime>
#include "libs/AVL.hpp"

using namespace std;

int main(int argc, char * argv[]){
	int n = 10;
	unsigned int data[n];
	AVL ordererData;
	AVL unordererData;
	AVL inverseData;
	AVL zigZag1;
	AVL zigZag2;
	AVL zigZag;
	AVL random;

	cout << "Insercion de datos ordenados: " << endl;
	for(unsigned int i = 0; i < n; i++){
		data[i] = i;
		ordererData.insert(i);
	}
	
	cout << "Insercion de datos inverso: " << endl;
	for(unsigned int i = 0; i < n; i++){
		inverseData.insert(n-i-1);
	}
	
	random_shuffle(data, data + n);
	
	cout << "Insercion de datos desordenados: " << endl;
	for(unsigned int i = 0; i < n; i++){
		unordererData.insert(data[i]);
	}
	
	cout << "Insercion de datos zigzag1" << endl;
	zigZag1.insert(30);
	zigZag1.insert(10);
	zigZag1.insert(20);
	
	cout << "Insercion de datos zigzag2" << endl;
	zigZag2.insert(10);
	zigZag2.insert(30);
	zigZag2.insert(20);
	
	cout << "Insercion de datos zigZag: " << endl;
	for(unsigned int i = 0; i < n/2; i++){
		zigZag.insert(i);
		zigZag.insert(n-1-i);
	}
	
	srand(time(NULL));
	cout << "Insercion de datos random: " << endl;
	for(unsigned int i = 0; i < n; i++){
		random.insert(((int)rand()%101));
	}
	
	cout << "AVL con los datos desordenados: " << endl;
	unordererData.printTree();
	
	cout << "AVL con los datos ordenados: " << endl;
	ordererData.printTree();
	
	cout << "AVL con los datos inversos: " << endl;
	inverseData.printTree();
	
	cout << "AVL con los datos zigzag1: " << endl;
	zigZag1.printTree();
	
	cout << "AVL con los datos zigzag2: " << endl;
	zigZag2.printTree();
	
	cout << "AVL con los datos zigzag: " << endl;
	zigZag.printTree();
	
	cout << "AVL con los datos random: " << endl;
	random.printTree();
	
	cout << "Búsquedas: " << endl;
	
	for(int i = -5; i < 5+n; i++){
		cout << "Buscar " << i << " -> " << unordererData.isInserted(i) << endl;
	}
	
}