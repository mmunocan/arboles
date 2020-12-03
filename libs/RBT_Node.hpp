#ifndef RBT_NODE_HPP
#define RBT_NODE_HPP
#include "NodeBT.hpp"
using namespace std;

class RBT_node : public NodeBT{
	public:
		// Agregar otras variables de ser necesario
		bool isBlack; // false = red, true = black
		unsigned int blackHeight;
		RBT_node(int x);
		~RBT_node();
		void printNode();
};

#endif