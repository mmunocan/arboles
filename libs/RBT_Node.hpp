#ifndef RBT_NODE_HPP
#define RBT_NODE_HPP
#include "NodeBT.hpp"
using namespace std;

class RBT_node : public NodeBT{
	public:
		// Agregar otras variables de ser necesario
		RBT_node* parent;
		bool isBlack; // false = red, true = black
		unsigned int blackHeight;
		RBT_node(int x);
		~RBT_node();
		void printNode();
		bool RBT_insert(int x);
};

#endif