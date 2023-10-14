#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
// Included required libraries.

struct BinaryTree // Created a struct named BinaryTree for binary search tree.
{
    int data;                 // Created an int field for storing data
    BinaryTree *left, *right; // For separating leaves, created 2 BinaryTree pointers as left and right.
};

BinaryTree *Add(BinaryTree *binaryTree, int number) // Created add function for adding leaves to binary tree.
{
    // If leaf of tree is null(empty):
    if (binaryTree == NULL)
    {
        // Created root pointer for storing data.
        BinaryTree *root = (BinaryTree *)malloc(sizeof(BinaryTree));
        root->left = NULL; // Assigned null to leaves as default.
        root->right = NULL;
        root->data = number; // Assigned the given data to root.
        return root;
    }

    // If leaf is not empty:
    if (binaryTree->data < number) // If data is greater than root go right leaf(recursively).
    {
        binaryTree->right = Add(binaryTree->right, number);
        return binaryTree;
    }

    binaryTree->left = Add(binaryTree->left, number); // If data is less than root go left leaf(recursively).

    return binaryTree;
}

// Created a function for searching leaves by level. 0. level is root level of tree.
int levelArray[100]; // Created an array for storing leaves of level.
int levelIndex = 0;  // Created two variables for finding level as f and k.
int index = 0;
void Level(BinaryTree *binaryTree, int levelNumber)
{
    // Stopped the function with return if tree is empty.
    if (binaryTree == NULL)
        return;

    // If the searched level is found:
    if (levelIndex == levelNumber)
    {
        // Added data to leaves array and increase index by 1 for adding next data.
        levelArray[index] = binaryTree->data;
        index++;
    }

    // For getting right and left leaf, increased levelIndex by 1.
    levelIndex++;
    Level(binaryTree->left, levelNumber);
    Level(binaryTree->right, levelNumber);
    // If right and left leaves are empty, for returning to previous leaf, decreased levelIndex by 1.
    levelIndex--;
}

// Created an array for storing data of all leaves. Used for calculating arithmetic mean.
int leaves[100];
int i = 0;
// Created a function for finding leaves and adding data to array
void Leaf(BinaryTree *binaryTree)
{
    // Created a BinaryTree pointer for searching leaves
    BinaryTree *iter;

    // Stopped the function if the tree is empty
    if (binaryTree == NULL)
        return;

    // Controlled the left and right leaves for confirming the element is a leaf
    if (binaryTree->left == NULL && binaryTree->right == NULL)
    {
        // Added leaf data to array and increased array index for next data
        leaves[i] = binaryTree->data;
        i++;
        // After finding leaf, assigned the pointer to root of tree
        iter = binaryTree;
    }

    // Controlled right element is empty
    if (binaryTree->right != NULL)
    {
        // Assigned the pointer to right element and called function recursively.
        iter = binaryTree->right;
        Leaf(iter);
    }

    // Controlled left element is empty
    if (binaryTree->left != NULL)
    {
        // Assigned the pointer to left element and called function recursively.
        iter = binaryTree->left;
        Leaf(iter);
    }
}

// Created step counter variable.
int stepCount;
// Created a function for searching element in binary tree.
int Search(BinaryTree *binaryTree, int wanted)
{
    // Stopped the and returned -1 if element is not found in tree.
    if (binaryTree == NULL)
    {
        printf("%d not found in tree.\n", wanted);
        return -1;
    }

    // If the element found, stopped the function and returned 1, printed wanted element with step count to console
    if (binaryTree->data == wanted)
    {
        printf("Found %d. Step Count: %d\n", wanted, stepCount);
        return 1;
    }

    // Increased step count if the element is not found yet.
    stepCount++;
    // If the wanted element is less then data in current position:
    if (wanted < binaryTree->data)
    {
        // Search recursively starts from left element
        binaryTree = binaryTree->left;
        Search(binaryTree, wanted);
    }
    else // If the wanted element is greater then data in current position:
    {
        // Search recursively starts from right element
        binaryTree = binaryTree->right;
        Search(binaryTree, wanted);
    }

    // Returned -1 if the function does not finished properly
    return -1;
}

// Created an array for finding and listing greater elements than user input of tree.
int bigElementsArray[100];
// Created a variable for control if any greater element is found.
int control = 0;
// Created a function for finding greater elements than user input of tree using Preorder Traversal
void FindBigElements(BinaryTree *binaryTree, int number)
{
    // Stopped the function if tree is empty or there is no greater elements than user input in tree.
    if (binaryTree == NULL)
        return;

    // If the controlled data is greater than user input:
    if (binaryTree->data > number)
    {
        // Added data to array and assigned 1 to control variable.
        bigElementsArray[index] = binaryTree->data;
        control = 1;
        // Increased array index by one for next data.
        index++;
    }
    FindBigElements(binaryTree->left, number);
    FindBigElements(binaryTree->right, number);
}

void WaitForUser()
{
    getchar();
    fflush(stdin);
    getchar();
}

void ClearConsole()
{
    system("clear");
}

#endif
