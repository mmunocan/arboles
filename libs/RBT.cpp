#include "RBT.hpp"

RBT::RBT(){
	root = NULL;
}

RBT::~RBT(){}

void RBT::insert(int x){}

bool RBT::isInserted(int x){return false;}

void RBT::printTree(){
	printTree(root, 0);
}

void RBT::printTree(const RBT_node * r, unsigned int level){
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
void RBT::printNode(const RBT_node * node){
	char color = node->color ? 'B' : 'R';
	cout << "<"<<node->value<<", "<<color<<", "<<node->blackHeight<<">" << endl;
}

void RBT::insertFixup(const RBT_node * node){}

void RBT::leftRotate(const RBT_node * x, const RBT_node * y){}

void RBT::rightRotate(const RBT_node * x, const RBT_node * y){}