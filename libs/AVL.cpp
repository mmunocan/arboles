#include "AVL.hpp"

AVL::AVL(){
	root = NULL;
}

AVL::~AVL(){}

void AVL::insert(int x){}

bool AVL::isInserted(int x){return false;}

void AVL::printTree(){
	printTree(root, 0);
}

void AVL::printTree(const AVL_node * r, unsigned int level){
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
void AVL::printNode(const AVL_node * node){
	cout << "<"<<node->value<<", "<<node->height<<">" << endl;
}

void AVL::insertFixup(const AVL_node * node){}

void AVL::leftRotate(const AVL_node * x, const AVL_node * y){}

void AVL::rightRotate(const AVL_node * x, const AVL_node * y){}