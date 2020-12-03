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
		vector<AVL_node*> * path = new vector<AVL_node*>();
		NodeBT *aux = root;
		NodeBT *toInsert =  new AVL_node(x);
		while(true){
			if(aux->value < x){
				if(aux->rightChild != NULL){
					path->push_back((AVL_node*)aux);
					aux = aux->rightChild;
				}else{
					aux->rightChild = toInsert;
					path->push_back((AVL_node*)aux);
					nodes++;
					for(AVL_node * n : *path){
						n->height++;
					}
					insertFixup(path);
					return;
				}
			}else if(x < aux->value){
				if(aux->leftChild != NULL){
					path->push_back((AVL_node*)aux);
					aux = aux->leftChild;
				}else{
					aux->leftChild = toInsert;
					path->push_back((AVL_node*)aux);
					nodes++;
					for(AVL_node * n : *path){
						n->height++;
					}
					insertFixup(path);
					return;
				}
			}else{
				// x == aux->value
				return;
			}
		}
		
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


void AVL::insertFixup(vector<AVL_node*> * path){
	int leftHeight, rightHeight, balanceFactor;
	AVL_node * n;
	for(int i = path->size() - 3; i >= 0; i--){
		n = (*path)[i];
		if(n->leftChild != NULL){
			leftHeight = ((AVL_node*)n->leftChild)->height;
		}else{
			leftHeight = -1;
		}
		if(n->rightChild != NULL){
			rightHeight = ((AVL_node*)n->rightChild)->height;
		}else{
			rightHeight = -1;
		}
		balanceFactor = rightHeight - leftHeight;
		if(abs(balanceFactor) >= 2){
			cout << "Requiero un balanceo en: " << endl;
			((AVL_node*)n)->printNode();
		}
	}
}

void AVL::leftRotate(const NodeBT * x, const NodeBT * y){}

void AVL::rightRotate(const NodeBT * x, const NodeBT * y){}