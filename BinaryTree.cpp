//
// Created by Giselle McNeill on 3/4/26.
//
#include "BinaryTree.h"
#include <iostream>
#include <stack>
using namespace std;

//created a flag for traversal methods
static bool first;

//constructor
BinaryTree::BinaryTree(Node *root)
    :root_(root){}

//destructor
BinaryTree::~BinaryTree() {
    destroy(root_);
}

//Wrapper: return the height of the tree (levels)
int BinaryTree::height() const {
    return height(root_);
}
//Wrapper: get the amount of nodes
int BinaryTree::countNodes() const {
        return countNodes(root_);
    }
//Wrapepr: get the amount of leaves (no children)
int BinaryTree::countLeaves() const {
    return countLeaves(root_);
}
//Wrapper: sum all values in tree
int BinaryTree::sum()const {
    return sum(root_);
}
//Wrapper: print preOrder traversal
void BinaryTree::preOrder() const {
    //if empty tree print empty line
    if (root_ == nullptr) {
        std::cout<< std::endl;
        return;
    }
    //reset flag/static variable
    first = true;

    //Call recursive helper
    preOrder(root_);
    std::cout<< std::endl;
}
//Wrapper: print preOrder traversal
void BinaryTree::inOrder() const {
    //If empty, print empty line
    if (root_ == nullptr) {
        std::cout<< std::endl;
        return;
    }

    //reset flag/static variable
    first = true;
    //Call recursive helper
    inOrder(root_);
    std::cout<< std::endl;
}
//Wrapper: print preOrder traversal
void BinaryTree::postOrder() const {
    //If empty print empty line
    if (root_ == nullptr) {
        std::cout<< std::endl;
        return;
    }
    //reset flag/static variable
    first = true;
    //Call recursive helper
    postOrder(root_);
    std::cout<< std::endl;
}
//Prints preOrder using iteration and a stack
void BinaryTree::preOrderIterative() const {
    //Check if root is empty
    if (root_ == nullptr) {
        std::cout<< std::endl;
        return;
    }
    //Reset flag and create stack
    first = true;
    stack<Node*> s;
    s.push(root_);

    //Iterate through the stack
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        //check if first node, no extra space
        if (first == true) {
            cout << node->value;
            first = false;
        }else {//otherwise print normal
            std::cout<< " " << node->value;
        }
        if (node->right != nullptr) {
            s.push(node->right);
        }
        if (node->left != nullptr) {
            s.push(node->left);
        }
    }

    std::cout<< std::endl;
}

//Wrapper: left and right nodes swap
void BinaryTree::mirror() {
    mirror(root_);
}

//**HELPER FUNCTIONS BELOW**

//Helper: calculates height
int BinaryTree::height(Node* node) const {
    //Base Case: Node is empty
    if (node == nullptr) {
        return 0;
    }
    //recursive case:
    //calculate left tree height
    int leftHeight = height(node->left);
    //calculate right tree height
    int rightHeight = height(node->right);
    //return the larger of the two
    return 1 + max(leftHeight, rightHeight);
}
//Helper calculates nodes
int BinaryTree::countNodes(Node* node) const {
    //base case: empty node
    if (node == nullptr) {
            return 0;
        }
        //recursive case: total from left and right
        return 1 + countNodes(node->left) + countNodes(node->right);

    }
//Helper calculates leaves
int BinaryTree::countLeaves(Node* node) const {
    //base case: empty node
    if (node == nullptr) {
        return 0;
    }
    //leaf = node with no children
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    //recursive case: total from left and right
    return countLeaves(node->left) + countLeaves(node->right);
}
//Helper calculates sum
int BinaryTree::sum(Node* node) const {
    //Base Case: Node is empty
    if (node == nullptr) {
        return 0;
    }
    //Recursive case: total from left and right
    return node->value + sum(node->left) + sum(node->right);
}
//Helper: prints tree in PreOrder
void BinaryTree::preOrder(Node* node) const {
    //Base Case: Node is empty
    if (node == nullptr) {
        return;
    }
    //Edge case: First element
    if (first == true) {
        cout << node->value;
        first = false;
    //Recursive Case: print, go left, go right
    }else {
        cout << " "<< node->value ;
    }
    preOrder(node->left);
    preOrder(node->right);
}

//Helper: prints tree in inOrder
void BinaryTree::inOrder(Node* node) const {
    //Base Case: Node is empty
    if (node == nullptr) {
        return;
    }

    inOrder(node->left);
    //edge case: first element
    if (first == true) {
        cout << node->value;
        first = false;
    }else {
        //Recursive Case, go left, print, go right
        cout << " "<< node->value ;
    }
    inOrder(node->right);
}

//Helper: prints tree in postOrder
void BinaryTree::postOrder(Node* node) const {
    //Base Case: Node is empty
    if (node == nullptr) {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);

    //edge case: first element
    if (first == true) {
        cout << node->value;
        first = false;
    }else {
        //Recursive Case: go left, go right, then print
        cout << " "<< node->value;
    }
}
//Helper: switch all left and right nodes
void BinaryTree::mirror(Node* node) {
    //base case: empty node
    if (node == nullptr) {
        return;
    }
    //recursive case: go down left and right
    mirror(node->left);
    mirror(node->right);

    //at each node swap left and right
    swap(node->left,node->right);
}
//Helper: destory each node in the tree
void BinaryTree::destroy(Node* node) {

    //base case
    if (node == nullptr) {
        return;
    }

    //recursive case: postorder
    //do not loose root node or you lose access
    destroy(node->left);
    destroy(node->right);
    delete node;
}


