#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include <iostream>


BinarySearchTree::BinarySearchTree(){
    this->root =NULL;
}

BinarySearchTree::~BinarySearchTree(){
    deleteNodes(root);
}

void BinarySearchTree::insert(int elem){
    insert(elem,root);
}

void BinarySearchTree::remove(int elem){
    remove(elem,root);
}

void BinarySearchTree::printPreorder(){
    if(root == NULL){
        cout << "Tree is Empty!";
    }
    traversePreorder(root);
    cout << endl;
}

void BinarySearchTree::printInorder(){
    if(root == NULL){
        cout << "Tree is Empty!";
    }
    traverseInorder(root);
    cout << endl;
}

void BinarySearchTree::printPostOrder(){
    if(root == NULL){
        cout << "Tree is Empty!";
    }
    traversePostorder(root);
    cout << endl;
}


void BinarySearchTree::insert(int elem, BinaryTreeNode * & n){
   
    if( n == NULL ){
        n = new BinaryTreeNode(elem);
    }
    else if( elem < n->element ){
        insert( elem, n->left );
    }
    else if( n->element < elem ){
        insert( elem, n->right );
    }
    else
        ;
}

void BinarySearchTree::remove(int elem, BinaryTreeNode * & n){

    if( n == NULL ){
        return; // Item not found; do nothing
    }

    if( elem < n->element ){
        remove( elem, n->left );
    }
    else if( n->element < elem ){
        remove( elem, n->right );
    }
    else if( n->left != NULL && n->right != NULL ){
        n->element = findMin( n->right )->element;
        remove( n->element, n->right );
    }
    else{
        BinaryTreeNode *old = n;
        n = ( n->left != NULL) ? n->left : n->right;
        delete old;
    }
}

void BinarySearchTree::traversePreorder(BinaryTreeNode *n){
    if(n == NULL){
        return;
    }
    cout << n->element << " ";
    traversePreorder(n->left);
    traversePreorder(n->right);
}

void BinarySearchTree::traverseInorder(BinaryTreeNode *n){
    if(n == NULL){
        return;
    }
    traverseInorder(n->left);
    cout << n->element << " ";
    traverseInorder(n->right);
}

void BinarySearchTree::traversePostorder(BinaryTreeNode *n){
    if(n == NULL){
        return;
    }
    traversePostorder(n->left);
    traversePostorder(n->right);
    cout << n->element << " ";
}

void BinarySearchTree::deleteNodes(BinaryTreeNode * & n){
    if(n == NULL){
        
        return;
    }
    else if((n->left != NULL)){
        deleteNodes(n->left);
    }
    else if(n->right != NULL){
        deleteNodes(n->right);
    }
    delete n;
}

BinaryTreeNode* BinarySearchTree::findMin(BinaryTreeNode *n){
    if(n == NULL){
        return NULL;
    }
    if(n->left == NULL){
        return n;
    }
    return findMin(n->left);
}
