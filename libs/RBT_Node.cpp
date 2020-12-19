#include "RBT_Node.hpp"

RBT_node::RBT_node(int x) : NodeBT(x){
	parent = NULL;
	isBlack = false;
}

RBT_node::~RBT_node(){
	
}

// Si al nodo se le agregan nuevos atributos, no olvidar agregarlos aquí
void RBT_node::printNode(){
	char color = isBlack ? 'B' : 'R';
	string padre = (parent == NULL) ? "NULL" : to_string(parent->value);
	cout << "<"<<value<<", "<<color<<", "<<blackHeight<<", p:"<< padre <<">" << endl;
}