/*
 * binary_tree.h
 *
 *  Created on: Mar 21, 2020
 *      Author: an
 */



#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdio.h>

#define TREE_ENTRY int

typedef struct TreeNode{
	TREE_ENTRY entry;
	TreeNode * left;
	TreeNode *right;
};

typedef struct Tree{
	TreeNode * root;
	int size;
	int depth;
};

/********************* Function APIs *******************/
void insertTree(Tree * const, TREE_ENTRY * const);


void createTree(Tree * const);
void clearTree(Tree * const);
int treeSize(Tree * const);
int treeDepth(Tree * const);
bool treeEmpty(Tree * const);
bool treeFull(Tree * const);

void inOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY));
void preOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY));
void postOrderTraverse(Tree *const, void (*pf)(TREE_ENTRY));


#endif /* BINARY_TREE_H_ */












