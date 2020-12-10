#ifndef NODE_AVL_HPP
#define NODE_AVL_HPP
#include "NodeBT.hpp"
using namespace std;

class AVL_node : public NodeBT{
	public:
		// Agregar otras variables de ser necesario
		int height;
		AVL_node(int x);
		~AVL_node();
		void printNode();
	private:
};

#endif