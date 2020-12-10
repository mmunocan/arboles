#include "BST.hpp"

BST::BST(){
	root = NULL;
	nodes = 0;
}

BST::~BST(){
	delete root;
}

void BST::insert(int x){
	if(nodes == 0){
		root = new NodeBT(x);
		nodes++;
	}else{
		NodeBT *aux = root;
		NodeBT *toInsert =  new NodeBT(x);
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

bool BST::isInserted(int x){
	return root->Node_search(x);
}

void BST::printTree(){
	cout << "Cantidad de nodos: " << nodes << endl;
	printTree(root, 0);
}

void BST::printTree(const NodeBT * r, unsigned int level){
	for(unsigned int i = 0; i < level; i++) cout << "-- ";
	if(r != NULL){
		((NodeBT*)r)->printNode();
		printTree(r->leftChild, level+1);
		printTree(r->rightChild, level+1);
	}else{
		cout << "NULL" << endl;
	}
}

// Basado en esquema de:
//	https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
NodeBT* leftRotation(NodeBT* x){
	if(x == NULL || x->rightChild == NULL){
		return x;
	}
	NodeBT* y = x->rightChild;
	x->rightChild = y->leftChild;
	y->leftChild = x;
	return y;
}

NodeBT rightRotation(NodeBT x){

}