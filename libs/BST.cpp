#include "BST.hpp"

BST::BST(){
	root = NULL;
}

BST::~BST(){}

void BST::insert(int x){}

bool BST::isInserted(int x){return false;}

void BST::printTree(){
	printTree(root, 0);
}

void BST::printTree(const BST_node * r, unsigned int level){
	for(unsigned int i = 0; i < level; i++) cout << "-";
	if(r != NULL){
		printNode(r);
		printTree(r->leftChild, level+1);
		printTree(r->rightChild, level+1);
	}else{
		cout << "NULL" << endl;
	}
}

// Si al nodo se le agregan nuevos atributos, no olvidar agregarlos aquí
void BST::printNode(const BST_node * node){
	cout << "<"<<node->value<<">" << endl;
}