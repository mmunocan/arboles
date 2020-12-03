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

void RBT::leftRotate(const RBT_node * x, const RBT_node * y){}

void RBT::rightRotate(const RBT_node * x, const RBT_node * y){}