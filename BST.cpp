#include "BST.h"

BST::BST() {
    root = NULL;
}

BSTNode* BST::insert(BSTNode* node, Driver d) {

    if(node == NULL)
        return new BSTNode(d);

    if(d.rating < node->data.rating)
        node->left = insert(node->left, d);

    else
        node->right = insert(node->right, d);

    return node;
}

void BST::inorder(BSTNode* node) {

    if(node == NULL)
        return;

    inorder(node->right);

    cout << node->data.name
    << " Rating: "
         << node->data.rating << endl;

    inorder(node->left);
}

void BST::addDriver(Driver d) {
    root = insert(root, d);
}

void BST::showDrivers() {
    inorder(root);
}