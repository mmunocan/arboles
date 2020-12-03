#include "RBT_Node.hpp"

RBT_node::RBT_node(int x) : NodeBT(x){}

RBT_node::~RBT_node(){}

// Si al nodo se le agregan nuevos atributos, no olvidar agregarlos aquí
void RBT_node::printNode(){
	char color = isBlack ? 'B' : 'R';
	cout << "<"<<value<<", "<<color<<", "<<blackHeight<<">" << endl;
}