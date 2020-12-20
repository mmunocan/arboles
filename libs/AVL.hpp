#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <vector>
#include "AVL_Node.hpp"
using namespace std;

class AVL{
	public:
		AVL();
		~AVL();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
		int altura();
	private:
		AVL_node * root;
		int nodes;
		void printTree(const NodeBT * r, unsigned int level);
		void insertFixup(vector<AVL_node*> * path); // Rebalanceo
		// Rotaciones 
		void leftLeftRotate(NodeBT * parent, bool isLeft);
		void rightRightRotate(NodeBT * parent, bool isLeft);
		void rightLeftRotate(NodeBT * parent, bool isLeft);
		void leftRightRotate(NodeBT * parent, bool isLeft);
		void calculateHeight(NodeBT * n);
		int balanceFactor(NodeBT * n);
};

#endif