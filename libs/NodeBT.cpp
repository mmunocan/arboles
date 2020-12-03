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
