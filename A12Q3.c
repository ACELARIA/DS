#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; 
}

Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    int current = preorder[*preIndex];
    (*preIndex)++;

    Node* node = createNode(current);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, current);

    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void printInorder(Node* root) {
    if (root) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

void printPreorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(Node* root) {
    if (root) {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int inorder[SIZE] =  {1, 8, 19, 13, 25, 9, 5, 10, 4, 3};
    int preorder[SIZE] = {25, 8, 1, 13, 19, 5, 9, 4, 10, 3};

    int preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, SIZE - 1, &preIndex);

    printf("Constructed Tree Traversals:\n");
    printf("Inorder: ");
    printInorder(root);
    printf("\nPreorder: ");
    printPreorder(root);
    printf("\nPostorder: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
