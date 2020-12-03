#include "AVL.hpp"

AVL::AVL(){
	root = NULL;
	nodes = 0;
}

AVL::~AVL(){}

void AVL::insert(int x){
	if(nodes == 0){
		root = new AVL_node(x);
		nodes++;
	}else{
		NodeBT *aux = root;
		NodeBT *toInsert =  new AVL_node(x);
		while(true){
			if(aux->value < x){
				if(aux->rightChild != NULL){
					aux = aux->rightChild;
				}else{
					aux->rightChild = toInsert;
					nodes++;
					return;
				}
			}else if(x < aux->value){
				if(aux->leftChild != NULL){
					aux = aux->leftChild;
				}else{
					aux->leftChild = toInsert;
					nodes++;
					return;
				}
			}else{
				// x == aux->value
				return;
			}
		}
		insertFixup(toInsert);
	}
	
}

bool AVL::isInserted(int x){
	return root->Node_search(x);
}

void AVL::printTree(){
	printTree(root, 0);
}

void AVL::printTree(const NodeBT * r, unsigned int level){
	for(unsigned int i = 0; i < level; i++) cout << "-- ";
	if(r != NULL){
		((AVL_node*)r)->printNode();
		printTree(r->leftChild, level+1);
		printTree(r->rightChild, level+1);
	}else{
		cout << "NULL" << endl;
	}
}


void AVL::insertFixup(NodeBT * node){}

void AVL::leftRotate(const NodeBT * x, const NodeBT * y){}

void AVL::rightRotate(const NodeBT * x, const NodeBT * y){}