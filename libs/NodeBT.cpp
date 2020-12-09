#include "NodeBT.hpp"


NodeBT::NodeBT(int x){
	leftChild = NULL;
	rightChild = NULL;
	value = x;
}


NodeBT::~NodeBT(){
	delete leftChild;
	delete rightChild;
}


bool NodeBT::Node_search(int x){
	if(this == NULL){
		return false;
	}
	NodeBT *aux = this;
	while(true){
		if(aux->value == x){
			return true;
		}else if(x < aux->value){
			if(aux->leftChild != NULL){
				aux = (NodeBT*) (aux->leftChild);
			}else{
				return false;
			}
		}else{
			// x > aux->value
			if(aux->rightChild != NULL){
				aux = (NodeBT*) (aux->rightChild);
			}else{
				return false;
			}
			
		}
	}
}

// Si al nodo se le agregan nuevos atributos, no olvidar agregarlos aquí
void NodeBT::printNode(){
	cout << "<"<<value<<">" << endl;
}

NodeBT* NodeBT::Node_leftRotation(){
	cout << "Node_leftRotation..." << endl;
	if(this->rightChild == NULL){
		// Si no hay un subarbol con raíz y
		return this;
	}
	NodeBT* x = this;
	NodeBT* y = x->rightChild;
	x->rightChild = y->leftChild;
	y->leftChild = x;
	return y;
}

NodeBT* NodeBT::Node_rightRotation(){
	cout << "Node_rightRotation..." << endl;
	if(this->leftChild == NULL){
		// Si no hay un subarbol con raíz x
		return this;
	}
	NodeBT* y = this;
	NodeBT* x = y->leftChild;
	y->leftChild = x->rightChild;
	x->rightChild = y;
	return x;
}
