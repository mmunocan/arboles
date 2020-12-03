#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "NodeBT.hpp"
using namespace std;

class AVL_node : public NodeBT{
	public:
		AVL_node * leftChild;
		AVL_node * rightChild;
		unsigned int height;
		// Agregar otras variables de ser necesario
		
		AVL_node(int x): NodeBT(x){}
		bool Node_search(int x){
			if(this == NULL){
				return false;
			}
			AVL_node *aux = this;
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
		
	private:
};

class AVL{
	public:
		AVL();
		~AVL();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
	private:
		AVL_node * root;
		int nodes;
		void printTree(const AVL_node * r, unsigned int level);
		void printNode(const AVL_node * node);
		void insertFixup(AVL_node * node); // Rebalanceo
		// Rotaciones simples. Las rotaciones dobles se realizan combinando las simples
		void leftRotate(const AVL_node * x, const AVL_node * y);
		void rightRotate(const AVL_node * x, const AVL_node * y);
};

#endif