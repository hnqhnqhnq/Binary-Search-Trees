#pragma once

typedef struct NodeT{
    int value;
    struct NodeT* right;
    struct NodeT* left;
    struct NodeT* parent;
}NodeT;

void insertNode(NodeT** root, int key);

void preorder(NodeT *root);

void inorder(NodeT *root);

void postorder(NodeT *root);

NodeT* searchKey(NodeT* root, int key);

NodeT *findMin(NodeT* root);

NodeT *findMax(NodeT* root);

NodeT *successor(NodeT *node);

NodeT *predecessor(NodeT *node);

void deleteNode(NodeT **root, int key);