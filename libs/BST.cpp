#include "BST.hpp"

BST::BST(){
	root = NULL;
	nodes = 0;
}

BST::~BST(){}

void BST::insert(int x){
	if(nodes == 0){
		root = new struct BST_node();
		root->value = x;
		root->leftChild = NULL;
		root->rightChild = NULL;
		nodes++;
	}else{
		struct BST_node *aux = root;
		struct BST_node *toInsert =  new struct BST_node();
		toInsert->leftChild = NULL;
		toInsert->rightChild = NULL;
		toInsert->value = x;
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
	if(root == NULL){
		return false;
	}
	struct BST_node *aux = root;
	while(true){
		if(aux->value == x){
			return true;
		}else if(x < aux->value){
			if(aux->leftChild != NULL){
				aux = aux->leftChild;
			}else{
				return false;
			}
		}else{
			// x > aux->value
			if(aux->rightChild != NULL){
				aux = aux->rightChild;
			}else{
				return false;
			}
			
		}
	}

}

void BST::printTree(){
	cout << "Cantidad de nodos: " << nodes << endl;
	printTree(root, 0);
}

void BST::printTree(const BST_node * r, unsigned int level){
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
void BST::printNode(const BST_node * node){
	cout << "<"<<node->value<<">" << endl;
}