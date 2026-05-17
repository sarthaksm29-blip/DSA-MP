#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Driver {
    string name;
    int rating;
};

struct BSTNode {

    Driver data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Driver d) {
        data = d;
        left = right = NULL;
    }
};

class BST {

    BSTNode* root;

    BSTNode* insert(BSTNode* node, Driver d);
     void inorder(BSTNode* node);

public:

    BST();

    void addDriver(Driver d);
    void showDrivers();
};

#endif