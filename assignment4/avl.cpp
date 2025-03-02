#include "avl.hpp"
using namespace std;

static const int BALANCE = 1;

bool AvlTree::contains(AvlNode * N, int x){
	if(N == NULL){
		return false;
	}
	else if(x < N->element){
		return contains(N->left, x);
	}
	else if(x > N->element){
		return contains(N->right, x);
	}
	else{
		return true;
	}
}

AvlNode* AvlTree::findMin(AvlNode* N){
	if(N == NULL){
		return NULL;
	}	
	if(N->left == NULL){
		return N;
	}
	return findMin(N->left);
}

AvlNode* AvlTree::findMax(AvlNode* N){
	if(N == NULL){
		return NULL;
	}	
	if(N->right == NULL){
		return N;
	}
	return findMax(N->right);
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * N is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void AvlTree::insert(AvlNode *& N, int x){

}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * N is the node that roots the subtree.
 * Set the new root of the subtree.
 */
bool AvlTree::remove(AvlNode *& N, int x){

}

/**
 * Returns the height of the node root or -1 if nullptr 
 */
int AvlTree::height(AvlNode * N){
	return N == NULL ? -1 : N->height;
}
//rebalancing the tree by performing appropriate 
//rotation on the subtree rooted with N
void AvlTree::balance(AvlNode *& N){

}
//right rotation
void AvlTree::rotateWithLeftChild(AvlNode *& k2){

  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right) ) + 1;
  k1->height = max(height(k1->left), k2->height ) + 1;
  k2 = k1;
}
//left rotation
void AvlTree::rotateWithRightChild(AvlNode *& k2){

  AvlNode *k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = max(height(k2->right), height(k2->left) ) + 1;
  k1->height = max(height(k1->right), k2->height ) + 1;
  k2 = k1;
}
//left-right rotation
void AvlTree::doubleLeftChild(AvlNode *& k3){

  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}
//right-left rotation
void AvlTree::doubleRightChild(AvlNode *& k3){

  rotateWithLeftChild(k3->right);
  rotateWithRightChild(k3);
}

void AvlTree::print(AvlNode *N, int level, int type){
        //cout << "printing N: " << N << endl;
  	if (N == NULL) {
                cout << "test!" << endl;
    		return;
  	}
  	if (type == IS_ROOT) {
    		std::cout << N -> element << "\n";
  	} else {
    		for (int i = 1; i < level; i++) {
      			std::cout << "| ";
    		}
    		if (type == IS_LEFT) {
      			std::cout << "|l_" << N -> element << "\n";
    		} else {
      			std::cout << "|r_" << N -> element << "\n";
    		}
  	}
  	if (N -> left != NULL) {
    		print(N -> left, level + 1, IS_LEFT);
  	}
  	if (N -> right != NULL) {
    		print(N -> right, level + 1, IS_RIGHT);
  	}
}
