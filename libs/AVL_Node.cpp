#include "AVL_Node.hpp"

AVL_node::AVL_node(int x) : NodeBT(x){}

AVL_node::~AVL_node(){}

// Si al nodo se le agregan nuevos atributos, no olvidar agregarlos aquí
void AVL_node::printNode(){
	cout << "<"<<value<<", "<<height<<">" << endl;
}