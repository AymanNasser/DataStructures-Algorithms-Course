/*
 * binary_tree.cpp
 *
 *  Created on: Mar 21, 2020
 *      Author: an
 */

#include "binary_tree.h"

static int auxiliaryHeightTreeRec(TreeNode * pt){

	if(pt == NULL)
		return 0;

	int a = auxiliaryHeightTreeRec(pt->left);
	int b = auxiliaryHeightTreeRec(pt->right);

	return (a > b) ? a+1 : b+1 ;
}

static bool auxiliaryIsTreeBalanced(TreeNode * pt){


	if(pt == NULL )
		return true;

	int leftSubTree = auxiliaryHeightTreeRec(pt->left);
	int rightSubTree = auxiliaryHeightTreeRec(pt->right);

	if((leftSubTree - rightSubTree) == 0 && auxiliaryIsTreeBalanced(pt->left) &&
			auxiliaryIsTreeBalanced(pt->right))
		return true;

	else if( ((leftSubTree - rightSubTree) == -1 || (leftSubTree - rightSubTree) == 1)
			&& auxiliaryIsTreeBalanced(pt->left) && auxiliaryIsTreeBalanced(pt->right))
		return true;

	else
		return false;

}


static bool auxiliaryfindItemTree(TreeNode * pt, TREE_ENTRY * pe){

	bool found = false;

	TreeNode *pTemp = pt;

	while(pTemp != NULL){

		if(pTemp->entry == *pe)
		{
			found = true;
			break;
		}

		else if(pTemp->entry > *pe)
			pTemp = pTemp->left;

		else
			pTemp = pTemp->right;

	}

	return found;
}



static void auxiliaryInsertTree(TreeNode *pt, TREE_ENTRY *pe, int *pDepth){

	/* Checking if the subtree is empty ==> base condition */
	if(! pt )
	{
		pt = new TreeNode;
		pt->entry = *pe;
		pt->left = NULL;
		pt->right = NULL;
	}
	else if( *pe < pt->entry )
	{
		auxiliaryInsertTree(pt->left, pe, pDepth);
	}
	else
	{
		auxiliaryInsertTree(pt->right, pe, pDepth);
	}

    (*pDepth)++;
}

static void auxiliaryTraverseTree(TreeNode *pt, void (*pf)(TREE_ENTRY element)){

	if(pt){
		auxiliaryTraverseTree(pt->left, pf);
		(*pf)(pt->entry);
		auxiliaryTraverseTree(pt->right,pf);
		(*pf)(pt->entry);
	}
}

static void auxiliaryClearTree(TreeNode * pt ){
	if(pt){
		auxiliaryClearTree(pt->left);
		auxiliaryClearTree(pt->right);
		delete pt;
	}
}

void createTree(Tree * const pt){
	pt->root = NULL;
	pt->depth = 0;
	pt->size = 0;
}

void clearTree(Tree * const pt ){
	auxiliaryClearTree(pt->root);

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
	auxiliaryTraverseTree(pt->root, pf);
}
void preOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY)){

}
void postOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY)){

}


void insertTreeRec(Tree * const pt, TREE_ENTRY * const pe){

	int tempDepth = 0;
	auxiliaryInsertTree(pt->root, pe, &tempDepth);

	pt->size++;

	if(pt->depth < tempDepth)
		pt->depth = tempDepth ;
}

void insertTreeIte(Tree * const pt, TREE_ENTRY * const pe){

	/* Depth of a tree is at least 1 if the tree has only the root &
	 * will be incremented at each traversing of the tree to return
	 * the right depth of the tree
	 * */
	int tempDepth = 1;

	/* 1- Creating new node
	 * 2- Initializing the new created node
	 * 3- Checking if the tree has only root or it consists of many
	 * node so traversing upon them to find the right place to insert
	 * the new node
	 * */

	TreeNode *pTemp = new TreeNode;
	TreeNode *currentIndex, *previousIndex;
	pTemp->entry = *pe;
	pTemp->left = NULL;
	pTemp->right = NULL;

	if(! pt->root )
	{
		pt->root = pTemp;
	}
	else
	{
		currentIndex = pt->root;
		/* Traversing the sub-trees till NULL found so it means that we found
		 * the place to insert
		 * */
		while(currentIndex != NULL)
		{
			previousIndex = currentIndex;

			if( *pe < currentIndex->entry )
			{
				currentIndex = currentIndex->left;
			}
			else
			{
				currentIndex = currentIndex->right;
			}
			tempDepth++;
		}
		/* Checking if the element to be inserted is smaller than current Key
		 * smaller == > inserted to left of the current node
		 * greater or equal == > inserted to right of the current node
		 * */

		if( *pe < previousIndex->entry)
			previousIndex->left = pTemp;
		else
			previousIndex->right = pTemp;

	}
	pt->size++;

	if(pt->depth < tempDepth)
		pt->depth = tempDepth;

}


bool findItemTreeIte(Tree * const pt, TREE_ENTRY * const pe){
	return auxiliaryfindItemTree(pt->root, pe);
}

bool isTreeBalanced(Tree * const pt){

	return auxiliaryIsTreeBalanced(pt->root);
}




