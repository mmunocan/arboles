#include "RBT.hpp"

RBT::RBT(){
	root = NULL;
	nodes = 0;
}

RBT::~RBT(){}

void RBT::insert(int x){
	// Paso 1 : Basado en algoritmo presentado en 
	// https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
	if(nodes == 0){
		root = new RBT_node(x);
		root->isBlack = true;
		treeBlackHeight = 1;
		nodes++;
	}else{
		NodeBT *aux = root;
		NodeBT *toInsert =  new RBT_node(x);
		while(aux != NULL && aux->value != x){
			if(aux->value < x){
				if(aux->rightChild == NULL){
					aux->rightChild = toInsert;
					((RBT_node*) toInsert)->parent = ((RBT_node*) aux);
					nodes++;
					insertFixup((RBT_node*)toInsert);
					return;
				}
				aux = aux->rightChild;
			}else if(x < aux->value){
				if(aux->leftChild == NULL){
					aux->leftChild = toInsert;
					((RBT_node*) toInsert)->parent = ((RBT_node*) aux);
					nodes++;
					insertFixup((RBT_node*)toInsert);
					return;
				}
				aux = aux->leftChild;
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
	for(unsigned int i = 0; i < level; i++) cout << "-- ";
	if(r != NULL){
		((RBT_node*)r)->printNode();
		printTree(r->leftChild, level+1);
		printTree(r->rightChild, level+1);
	}else{
		cout << "NULL" << endl;
	}
}

RBT_node* RBT::getUncle(const RBT_node* node){
	if(node != NULL && node->parent != NULL && node->parent->parent!= NULL){
		if(node->parent->value < node->parent->parent->value){
			return ((RBT_node*)(node->parent->parent->rightChild));
		}
		return ((RBT_node*)(node->parent->parent->leftChild));
	}
	return NULL;
}


void RBT::insertFixup(RBT_node * node){
	// Pasos > 1 en adelante de 
	// https://www.geeksforgeeks.org/red-black-tree-set-2-insert/

	// Paso 2
	if(node->value == root->value){
		node->isBlack = true;
		treeBlackHeight++;
		return;
	}
	// Paso 3
	if(!node->parent->isBlack){
		// Paso 3.a
		// Por propiedades del RedBlackTree:
		// si el nodo padre es rojo entonces debe tener abuelo
		RBT_node* uncle = getUncle(node);
		if(uncle != NULL && !uncle->isBlack){
			node->parent->isBlack = true;
			uncle->isBlack = true;
			node->parent->parent->isBlack = false;
			insertFixup(node->parent->parent);
			return;
		}
		if(uncle != NULL && uncle->isBlack){
			RBT_node* p = node->parent;
			RBT_node* g = p->parent;
			if(p->value < g->value){
				// p es hijo izquierdo de g
				if(node->value < p->value){
					// x es hijo izquierdo de p
					// Rotación LL
					
					// Esta rotación es equivalente a la rightRotation de NodeBT
					// Que no incluye la actualización de los enlaces a los padres
					// 1º llamar a la rotación

					// 2º realizar actualizaciones de punteros a padres

				}else{
					// x es el hijo derecho de p
					// Rotación LR
				}

			}else{
				// p es hijo derecho de g
				if(node->value > p->value){
					// x es hijo derecho de p
					// Rotación RR
					
					// Esta rotación es equivalente a la leftRotation de NodeBT
					// Que no incluye la actualización de los enlaces a los padres
					// 1º llamar a la rotación

					// 2º realizar actualizaciones de punteros a padres

				}else{
					// x es el hijo izquierdo de p
					// Rotación RL
				}				
			}
		}
	}
}

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