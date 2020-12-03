#ifndef NODEBT_HPP
#define NODEBT_HPP
#include <iostream>
using namespace std;

class NodeBT{	
	public:
		NodeBT * leftChild;
		NodeBT * rightChild;
		int value;
		NodeBT(int x);
		~NodeBT();
		bool Node_search(int x);
		void printNode();
	private:
		
};

#endif