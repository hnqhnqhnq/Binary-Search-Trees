#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

int main() {
    NodeT *root = NULL;
    int nodesArray[11] = {15, 6, 18, 20, 17, 7, 13, 3, 2, 4, 9};

    for (int i = 0; i < 11; i++)
        insertNode(&root, nodesArray[i]);

//    for(int i=0;i<11;i++){
//        NodeT *search = searchKey(root,nodesArray[i]);
//
//        if(search==NULL)
//            printf("The key %d doesn't exist", nodesArray[i]);
//        else
//            printf("Found %d", search->value);
//
//        printf("\n");
//    }
//
//    int notNodes[11]={33,44,55,66,77,88,99,11,90,43,56};
//
//    for(int i=0;i<11;i++){
//        NodeT *search = searchKey(root,notNodes[i]);
//
//        if(search==NULL)
//            printf("The key %d doesn't exist", notNodes[i]);
//        else
//            printf("Found %d", notNodes[i]);
//
//        printf("\n");
//    }
//
//    printf("\n");

//    NodeT *minim = findMin(root);
//
//    printf("The minimum value of the BST is: %d\n", minim->value);
//
//    NodeT *max = findMax(root);
//
//    printf("The maximum value of the BST is: %d\n",max->value);
//
//    printf("\n");

//    for (int i = 0; i < 11; i++) {
//        NodeT *search = searchKey(root, nodesArray[i]);
//        NodeT *suc = successor(search);
//        if (suc == NULL)
//            printf("The node %d doesn't have a successor!\n", search->value);
//        else
//            printf("The node %d has a successor: %d\n", search->value, suc->value);
//    }

//    printf("\n");

//    for (int i = 0; i < 11; i++) {
//        NodeT *search = searchKey(root, nodesArray[i]);
//        NodeT *pred = predecessor(search);
//        if (pred == NULL)
//            printf("The node %d doesn't have a predecessor!\n", search->value);
//        else
//            printf("The node %d has a predecessor: %d\n", search->value, pred->value);
//    }



    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    printf("\n");

    deleteNode(&root,18);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    printf("\n");



    return 0;
}