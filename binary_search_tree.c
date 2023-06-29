#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>

NodeT* createNode(int key){
    NodeT* root = malloc (sizeof(NodeT));

    if(root==NULL){
        printf("Couldnt't allocate memory!");
        return NULL;
    }

    root->value=key;
    root->parent=NULL;
    root->left=NULL;
    root->right=NULL;

    return root;
}

void insertNode(NodeT** root, int key){
    if((*root)==NULL){
        (*root) = createNode(key);
        return;
    }

    if(key<(*root)->value){
        insertNode(&((*root)->left), key);
        (*root)->left->parent = (*root);
    }

    else if (key>(*root)->value){
        insertNode(&((*root)->right), key);
        (*root)->right->parent = (*root);
    }
}

void preorder(NodeT *root){
    if(root==NULL)
        return;

    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(NodeT *root){
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void postorder(NodeT *root){
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

NodeT* searchKey(NodeT* root, int key){
    if(root==NULL || root->value==key)
        return root;

    if(key<root->value)
        searchKey(root->left,key);
    else
        searchKey(root->right,key);
}

NodeT *findMin(NodeT* root){
    if(root->left==NULL)
        return root;

    findMin(root->left);
}

NodeT *findMax(NodeT* root){
    if(root->right==NULL)
        return root;

    findMax(root->right);
}

NodeT *successor(NodeT *node){
    if(node->right!=NULL)
        return findMin(node->right);
    else{
        NodeT* ancestor = node->parent;
        NodeT *suc = NULL;

        while(ancestor!=NULL){
            if(node->value<ancestor->value){
                suc = ancestor;
                ancestor = ancestor->parent;
            }
            else
                ancestor = ancestor->parent;
        }

        return suc;
    }

}

NodeT *predecessor(NodeT *node){
    if(node->left!=NULL)
        return findMax(node->left);
    else{
        NodeT *ancestor = node->parent;
        NodeT *pred = NULL;

        while(ancestor!=NULL){
            if(node->value>ancestor->value){
                pred=ancestor;
                ancestor = ancestor->parent;
            }
            else
                ancestor = ancestor->parent;
        }

        return pred;
    }
}

void deleteNode(NodeT** root, int key) {
    if (*root == NULL)
        return;

    if (key < (*root)->value)
        deleteNode(&(*root)->left, key);
    else if (key > (*root)->value)
        deleteNode(&(*root)->right, key);
    else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            if ((*root)->parent != NULL) {
                if ((*root)->parent->left == (*root))
                    (*root)->parent->left = NULL;
                else
                    (*root)->parent->right = NULL;
            }
            free(*root);
            *root = NULL;

            return;
        }

        else if ((*root)->left == NULL) {
            NodeT* temp = *root;

            *root = (*root)->right;
            (*root)->parent = temp->parent;
            free(temp);
        }

        else if ((*root)->right == NULL) {
            NodeT* temp = *root;

            *root = (*root)->left;
            (*root)->parent = temp->parent;
            free(temp);
        }

        else {
            NodeT* successor = findMin((*root)->right);

            (*root)->value = successor->value;
            deleteNode(&(*root)->right, successor->value);
        }
    }
}

