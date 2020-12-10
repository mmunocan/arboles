#include "RBT.hpp"

RBT::RBT(){
	root = NULL;
	nodes = 0;
}

RBT::~RBT(){}

void RBT::insert(int x){
	if(nodes == 0){
		root = new RBT_node(x);
		nodes++;
	}else{
		NodeBT *aux = root;
		NodeBT *toInsert =  new RBT_node(x);
		while(true){
			if(aux->value < x){
				if(aux->rightChild != NULL){
					aux = aux->rightChild;
				}else{
					aux->rightChild = toInsert;
					nodes++;
				}
			}else if(x < aux->value){
				if(aux->leftChild != NULL){
					aux = aux->leftChild;
				}else{
					aux->leftChild = toInsert;
					nodes++;
				}
			}else{
				// x == aux->value
				return;
			}
		}
	}
}

bool RBT::isInserted(int x){
	return root->Node_search(x);
}

void RBT::printTree(){
	printTree(root, 0);
}

void RBT::printTree(const NodeBT * r, unsigned int level){
	for(unsigned int i = 0; i < level; i++) cout << "-";
	if(r != NULL){
		((RBT_node*)r)->printNode();
		printTree(r->leftChild, level+1);
		printTree(r->rightChild, level+1);
	}else{
		cout << "NULL" << endl;
	}
}


void RBT::insertFixup(const RBT_node * node){}

// Implementación para rotar nodo según su valor
bool RBT::leftRotation(int x){
	cout << "RBT_leftRotation..." << endl;
	RBT_node* aux = root;
	if(aux->value == x){
		root = (RBT_node*) aux->Node_leftRotation();
		return true;
	}
	do{
		if(x > aux->value){
			if(aux->rightChild != NULL && aux->rightChild->value == x){
				aux->rightChild = (RBT_node*) aux->rightChild->Node_leftRotation();
				return true;
			}
			aux = (RBT_node*) aux->rightChild;
		}else if(x < aux->value){
			if(aux->leftChild != NULL && aux->leftChild->value == x){
				aux->leftChild = (NodeBT*) aux->leftChild->Node_leftRotation();
				return true;
			}
			aux = (RBT_node*) aux->leftChild;
		}
	}while(aux != NULL);
	return false;
}

bool RBT::rightRotation(int x){
	cout << "RBT_rightRotation..." << endl;
	RBT_node* aux = root;
	if(aux->value == x){
		root = (RBT_node*) aux->Node_rightRotation();
		return true;
	}
	do{
		if(x > aux->value){
			if(aux->rightChild != NULL && aux->rightChild->value == x){
				aux->rightChild = (RBT_node*) aux->rightChild->Node_rightRotation();
				return true;
			}
			aux = (RBT_node*) aux->rightChild;
		}else if(x < aux->value){
			if(aux->leftChild != NULL && aux->leftChild->value == x){
				aux->leftChild = (NodeBT*) aux->leftChild->Node_rightRotation();
				return true;
			}
			aux = (RBT_node*) aux->leftChild;
		}
	}while(aux != NULL);
	return false;
}