//============================================================================
// Name        : BinaryTreeNode.h
// Author      : Emre Sefer & Hasan Sozer
// Version     : 2.0
// Copyright   : (c) 2020 Ozyegin University
// Description : Includes the header file of the BinaryTreeNode class 
//				 that will be used as part of the program to be submitted 
//				 as Homework 3, which is assigned in the context of  
//				 the course CS201, Data Structures and Algorithms.
//============================================================================

#ifndef __BINARYTREENODE__
#define __BINARYTREENODE__

class BinaryTreeNode {

public:
	BinaryTreeNode(int);
	int element;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

#endif /* __BINARYTREENODE__ */