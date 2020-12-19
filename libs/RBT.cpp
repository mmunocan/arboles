#include "RBT.hpp"

RBT::RBT(){
	root = NULL;
	nodes = 0;
}

RBT::~RBT(){
	delete root;
}

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
		if(uncle != NULL && uncle->isBlack || !node->parent->isBlack){
			RBT_node* p = node->parent;
			RBT_node* g = p->parent;
			if(p->value < g->value){
				// p es hijo izquierdo de g
				if(node->value < p->value){
					// x es hijo izquierdo de p
					// Rotación LL
					
					// Esta rotación es equivalente a la rightRotation de NodeBT
					// Que no incluye la actualización de los enlaces a los padres
					// Hacer la rotación y actualización de punteros a padres
					if(g->parent == NULL){
						// El padre de g es la raíz
						root = (RBT_node*) g->Node_rightRotation();
						root->parent = NULL;
					}else{
						// El padre de g es un nodo
						if(g->value < g->parent->value){
							// g es hijo izquerdo
							g->parent->leftChild = (RBT_node*) g->Node_rightRotation();
						}else{
							// g es hijo derecho
							g->parent->rightChild = (RBT_node*) g->Node_rightRotation();
						}
						p->parent = g->parent;
					}
					g->parent = p;
					if(g->leftChild != NULL){
						((RBT_node*)g->leftChild)->parent = g;
					}
					g->isBlack = false;
					p->isBlack = true;
					node->isBlack = false;
				}else{
					// x es el hijo derecho de p
					// Rotación LR
					// 1° Rotación a la izquierda en P
					g->leftChild = (RBT_node*) p->Node_leftRotation();
					if(p->rightChild != NULL){
						((RBT_node*) p->rightChild)->parent = p;
					}
					p->parent = node;
					node->parent = g;
					// 2° Rotación a la derecha en G
					if(g->parent == NULL){
						// El padre de g es la raíz
						root = (RBT_node*) g->Node_rightRotation();
						root->parent = NULL;
					}else{
						// El padre de g es un nodo
						if(g->value < g->parent->value){
							// g es hijo izquerdo
							g->parent->leftChild = (RBT_node*) g->Node_rightRotation();
						}else{
							// g es hijo derecho
							g->parent->rightChild = (RBT_node*) g->Node_rightRotation();
						}
						node->parent = g->parent;
					}
					g->parent = node;
					if(g->leftChild != NULL){
						((RBT_node*)g->leftChild)->parent = g;
					}
					g->isBlack = false;
					p->isBlack = false;
					node->isBlack = true;
				}
			}else{
				// p es hijo derecho de g
				if(node->value > p->value){
					// x es hijo derecho de p
					// Rotación RR
				
					// Esta rotación es equivalente a la leftRotation de NodeBT
					// Que no incluye la actualización de los enlaces a los padres
					// Hacer la rotación y actualización de punteros a padres
					if(g->parent == NULL){
						// El padre de g es la raíz
						root = (RBT_node*) g->Node_leftRotation();
						root->parent = NULL;
					}else{
						// El padre de g es un nodo
						if(g->value < g->parent->value){
							// g es hijo izquerdo
							g->parent->leftChild = (RBT_node*) g->Node_leftRotation();
						}else{
							// g es hijo derecho
							g->parent->rightChild = (RBT_node*) g->Node_leftRotation();
						}
						p->parent = g->parent;
					}
					g->parent = p;
					if(g->rightChild != NULL){
						((RBT_node*)g->rightChild)->parent = g;
					}
					g->isBlack = false;
					p->isBlack = true;
					node->isBlack = false;
				}else{
					// x es el hijo izquierdo de p
					// Rotación RL
					// 1° Rotación a la derecha en p
					g->rightChild = (RBT_node*) p->Node_rightRotation();
					if(p->leftChild != NULL){
						((RBT_node*) p->leftChild)->parent = p;
					}
					p->parent = node;
					node->parent = g;
					// 2° Rotación a la izquierda en G
					if(g->parent == NULL){
						// El padre de g es la raíz
						root = (RBT_node*) g->Node_leftRotation();
						root->parent = NULL;
					}else{
						// El padre de g es un nodo
						if(g->value < g->parent->value){
							// g es hijo izquerdo
							g->parent->leftChild = (RBT_node*) g->Node_leftRotation();
						}else{
							// g es hijo derecho
							g->parent->rightChild = (RBT_node*) g->Node_leftRotation();
						}
						node->parent = g->parent;
					}
					g->parent = node;
					if(g->rightChild != NULL){
						((RBT_node*)g->rightChild)->parent = g;
					}
					g->isBlack = false;
					p->isBlack = false;
					node->isBlack = true;					
				}				
			}
		}
	}
}

// Implementación para rotación de nodos según su valor
bool RBT::leftRotation(int x){
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

int RBT::altura(){
	if(root == NULL){
		return 0;
	}
	return root->Node_altura();
}