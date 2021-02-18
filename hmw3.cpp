#include <iostream>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
#include <string>
using namespace std;


int main(){

    BinarySearchTree *bst = new BinarySearchTree();

    string ended = "Goksel"; 
    string numbers = "#"; //dummy

    cout << "Enter a set of numbers (-2 to remove numbers, -1 to stop):" << endl;
    while(numbers != "-1"){

        if(numbers == "-2"){

            while(numbers != "-1"){
                cin >> numbers;
                if(numbers != "-1"){
                    int number = stoi(numbers);
                    bst->remove(number);
                }
                else if(numbers == "-1"){
                    ended = "break";
                    break;
                }
            }  
        }
        else{
            if(numbers != "#"){ 
                int number = stoi(numbers);
                bst->insert(number);
            }
        }
        //control
        if(ended == "break"){
            break;
        }

        cin >> numbers;
    }

    cout << "preorder: ";
    bst->printPreorder();

    cout << "inorder: ";
    bst->printInorder();
    
    cout << "postorder: ";
    bst->printPostOrder();

    delete bst;
    
    return 0;
}
