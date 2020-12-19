#include "AVL.hpp"

AVL::AVL(){
	root = NULL;
	nodes = 0;
}

AVL::~AVL(){
	delete root;
}

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
					AVL_node * n;
					for(int i = path->size() - 1; i >= 0; i--){
						n = (*path)[i];
						calculateHeight((NodeBT*)n);
						
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
					AVL_node * n;
					for(int i = path->size() - 1; i >= 0; i--){
						n = (*path)[i];
						calculateHeight((NodeBT*)n);
						
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
	if(root == NULL)  return false;
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
	int leftBalanceFactor, rightBalanceFactor, nodeBalanceFactor;
	AVL_node * n;
	AVL_node * parent;
	//cout << "path size: "<< path->size() << endl;
	for(int i = path->size() - 2; i >= 0; i--){
		n = (*path)[i];
		nodeBalanceFactor = balanceFactor(n);
		leftBalanceFactor = balanceFactor(n->leftChild);
		rightBalanceFactor = balanceFactor(n->rightChild);
		//cout << "INSERTION <" << n->value << ", " << nodeBalanceFactor << ", "
		//	<< leftBalanceFactor << ", " << rightBalanceFactor << ">" << endl;
		if(nodeBalanceFactor >= 2 && leftBalanceFactor >= 1){
			// LeftLeft rotation
			if(i > 0){
				parent = (*path)[i-1];
				bool isLeft = true;
				if(n->value > parent->value) isLeft = false;
				leftLeftRotate(parent, isLeft);
			}else{
				// Rotate the root
				root = (AVL_node*) root->Node_rightRotation();
				calculateHeight(root->leftChild);
				calculateHeight(root->rightChild);
				//calculateHeight(root);
			}
		}
		
		if(nodeBalanceFactor <= -2 && rightBalanceFactor <= -1){
			// RightRight rotation
			if(i > 0){
				parent = (*path)[i-1];
				bool isLeft = true;
				if(n->value > parent->value) isLeft = false;
				rightRightRotate(parent, isLeft);
			}else{
				// Rotate the root
				root = (AVL_node*) root->Node_leftRotation();
				calculateHeight(root->leftChild);
				calculateHeight(root->rightChild);
				//calculateHeight(root);
			}
		}
		
		if(nodeBalanceFactor <= -2 && rightBalanceFactor >= 1){
			// RightLeft rotation
			//cout << "RightLeft rotation" << endl;
			if(i > 0){
				parent = (*path)[i-1];
				bool isLeft = true;
				if(n->value > parent->value) isLeft = false;
				rightLeftRotate(parent, isLeft);
			}else{
				// Rotate the root
				root->rightChild = (AVL_node*)root->rightChild->Node_rightRotation();
				root = (AVL_node*) root->Node_leftRotation();
				calculateHeight(root->leftChild);
				calculateHeight(root->rightChild);
				calculateHeight(root);
			}
		}
		
		if(nodeBalanceFactor >= 2 && leftBalanceFactor <= -1){
			// LeftRight rotation
			//cout << "LeftRight rotation" << endl;
			if(i > 0){
				parent = (*path)[i-1];
				bool isLeft = true;
				if(n->value > parent->value) isLeft = false;
				leftRightRotate(parent, isLeft);
			}else{
				// Rotate the root
				root->leftChild = (AVL_node*)root->leftChild->Node_leftRotation();
				root = (AVL_node*) root->Node_rightRotation();
				calculateHeight(root->leftChild);
				calculateHeight(root->rightChild);
				calculateHeight(root);
			}
		}
		
		calculateHeight(n);
		
	}
}

void AVL::leftLeftRotate(NodeBT * parent, bool isLeft){
	if(isLeft){
		parent->leftChild = (NodeBT*) parent->leftChild->Node_rightRotation();
		if(parent->leftChild->rightChild != NULL) calculateHeight(parent->leftChild->rightChild);
		if(parent->leftChild->leftChild != NULL) calculateHeight(parent->leftChild->leftChild);
		calculateHeight(parent->leftChild);
	}else{
		parent->rightChild = (NodeBT*) parent->rightChild->Node_rightRotation();
		if(parent->rightChild->rightChild != NULL) calculateHeight(parent->rightChild->rightChild);
		if(parent->rightChild->leftChild != NULL) calculateHeight(parent->rightChild->leftChild);
		calculateHeight(parent->rightChild);
	}
}

void AVL::rightRightRotate(NodeBT * parent, bool isLeft){
	if(isLeft){
		parent->leftChild = (NodeBT*) parent->leftChild->Node_leftRotation();
		if(parent->leftChild->rightChild != NULL) calculateHeight(parent->leftChild->rightChild);
		if(parent->leftChild->leftChild != NULL) calculateHeight(parent->leftChild->leftChild);
		calculateHeight(parent->leftChild);
	}else{
		parent->rightChild = (NodeBT*) parent->rightChild->Node_leftRotation();
		if(parent->rightChild->rightChild != NULL) calculateHeight(parent->rightChild->rightChild);
		if(parent->rightChild->leftChild != NULL) calculateHeight(parent->rightChild->leftChild);
		calculateHeight(parent->rightChild);
	}
	
	
}

void AVL::rightLeftRotate(NodeBT * parent, bool isLeft){
	if(isLeft){
		parent->leftChild->rightChild = (NodeBT*)parent->leftChild->rightChild->Node_rightRotation();
		parent->leftChild = (NodeBT*) parent->leftChild->Node_leftRotation();
		
		if(parent->leftChild->rightChild != NULL) calculateHeight(parent->leftChild->rightChild);
		if(parent->leftChild->leftChild != NULL) calculateHeight(parent->leftChild->leftChild);
		calculateHeight(parent->leftChild);
	}else{
		parent->rightChild->rightChild = (NodeBT*)parent->rightChild->rightChild->Node_rightRotation();
		parent->rightChild = (NodeBT*) parent->rightChild->Node_leftRotation();
		
		if(parent->rightChild->rightChild != NULL) calculateHeight(parent->rightChild->rightChild);
		if(parent->rightChild->leftChild != NULL) calculateHeight(parent->rightChild->leftChild);
		calculateHeight(parent->rightChild);
	}
}
void AVL::leftRightRotate(NodeBT * parent, bool isLeft){
	if(isLeft){
		parent->leftChild->leftChild = (NodeBT*)parent->leftChild->leftChild->Node_leftRotation();
		parent->leftChild = (NodeBT*) parent->leftChild->Node_rightRotation();
		
		if(parent->leftChild->rightChild != NULL) calculateHeight(parent->leftChild->rightChild);
		if(parent->leftChild->leftChild != NULL) calculateHeight(parent->leftChild->leftChild);
		calculateHeight(parent->leftChild);
	}else{
		parent->rightChild->leftChild = (NodeBT*)parent->rightChild->leftChild->Node_leftRotation();
		parent->rightChild = (NodeBT*) parent->rightChild->Node_rightRotation();
		
		if(parent->rightChild->rightChild != NULL) calculateHeight(parent->rightChild->rightChild);
		if(parent->rightChild->leftChild != NULL) calculateHeight(parent->rightChild->leftChild);
		calculateHeight(parent->rightChild);
	}
}

void AVL::calculateHeight(NodeBT * n){
	int hl = n->leftChild != NULL ? ((AVL_node*)n->leftChild)->height : -1;
	int hr = n->rightChild != NULL ? ((AVL_node*)n->rightChild)->height : -1;
	
	((AVL_node*)n)->height = hl > hr ? hl + 1 : hr + 1;
	
}

int AVL::balanceFactor(NodeBT * n){
	if(n == NULL) return 0;
	int leftHeight, rightHeight, balanceFactor;
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
	balanceFactor = leftHeight - rightHeight;
	return balanceFactor;
}