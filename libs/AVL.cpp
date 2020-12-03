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
		AVL_node *aux = root;
		AVL_node *toInsert =  new AVL_node(x);
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
		//insertFixup(toInsert);
	}
	
}

bool AVL::isInserted(int x){
	return root->Node_search(x);
}

void AVL::printTree(){
	printTree(root, 0);
}

void AVL::printTree(const AVL_node * r, unsigned int level){
	for(unsigned int i = 0; i < level; i++) cout << "-- ";
	if(r != NULL){
		printNode(r);
		printTree(r->leftChild, level+1);
		printTree(r->rightChild, level+1);
	}else{
		cout << "NULL" << endl;
	}
}

// Si al nodo se le agregan nuevos atributos, no olvidar agregarlos aquí
void AVL::printNode(const AVL_node * node){
	cout << "<"<<node->value<<", "<<node->height<<">" << endl;
}

void AVL::insertFixup(AVL_node * node){}

void AVL::leftRotate(const AVL_node * x, const AVL_node * y){}

void AVL::rightRotate(const AVL_node * x, const AVL_node * y){}