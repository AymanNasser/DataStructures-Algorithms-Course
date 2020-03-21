/*
 * binary_tree.cpp
 *
 *  Created on: Mar 21, 2020
 *      Author: an
 */

#include "binary_tree.h"

static void auxilaryTraverseTree(TreeNode *pt, void (*pf)(TREE_ENTRY element)){

	if(pt){
		auxilaryTraverseTree(pt->left, pf);
		(*pf)(pt->entry);
		auxilaryTraverseTree(pt->right,pf);
		(*pf)(pt->entry);
	}
}

static void auxilaryClearTree(TreeNode * pt ){
	if(pt){
		auxilaryClearTree(pt->left);
		auxilaryClearTree(pt->right);
		delete pt;
	}
}

void createTree(Tree * const pt){
	pt->root = NULL;
	pt->depth = 0;
	pt->size = 0;
}

void clearTree(Tree * const pt ){
	auxilaryClearTree(pt->root);

	pt->size =0;
	pt->depth = 0;
	pt->root = NULL;
}

int treeSize(Tree * const pt){
	return pt->size;
}

int treeDepth(Tree * const pt){
	return pt->depth;
}


bool treeEmpty(Tree * const pt){
	return (! (pt->root) );
}

bool treeFull(Tree * const){
	return 0;
}



void inOrderTraverse(Tree * const pt, void (*pf)(TREE_ENTRY element)){
	auxilaryTraverseTree(pt->root, pf);
}
void preOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY)){

}
void postOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY)){

}


void insertTree(Tree * const pt, TREE_ENTRY * const pe){


}











