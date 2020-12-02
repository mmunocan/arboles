#ifndef RBT_HPP
#define RBT_HPP
#include <iostream>
#include "NodeBT.hpp"
using namespace std;

class RBT_node : public NodeBT{
	public: 
		RBT_node * leftChild;
		RBT_node * rightChild;
		int value;
		bool color; // false = red, true = black
		unsigned int blackHeight;
		// Agregar otras variables de ser necesario
	private:
		
};

class RBT{
	private:
		RBT_node * root;
		void printTree(const RBT_node * r, unsigned int level);
		void printNode(const RBT_node * node);
		// Extraido del libro de Cormen pg 312-316
		void insertFixup(const RBT_node * node);
		void leftRotate(const RBT_node * x, const RBT_node * y);
		void rightRotate(const RBT_node * x, const RBT_node * y);
	public:
		RBT();
		~RBT();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
};

#endif