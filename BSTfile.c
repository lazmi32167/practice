#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value in the BST
struct Node* insertBST(struct Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Preorder traversal
void preorder(struct Node* root, FILE* outputFile) {
    if (root == NULL) {
        return;
    }
    fprintf(outputFile, "%d ", root->data);
    preorder(root->left, outputFile);
    preorder(root->right, outputFile);
}

// Inorder traversal
void inorder(struct Node* root, FILE* outputFile) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, outputFile);
    fprintf(outputFile, "%d ", root->data);
    inorder(root->right, outputFile);
}

// Postorder traversal
void postorder(struct Node* root, FILE* outputFile) {
    if (root == NULL) {
        return;
    }
    postorder(root->left, outputFile);
    postorder(root->right, outputFile);
    fprintf(outputFile, "%d ", root->data);
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("inputbst.txt", "r");
    outputFile = fopen("output5.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    struct Node* root = NULL;
    int val;

    // Read values from input file and insert into BST
    while (fscanf(inputFile, "%d", &val) != EOF) {
        root = insertBST(root, val);
    }

    // Write traversals to output file
    fprintf(outputFile, "Inorder Traversal: ");
    inorder(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Preorder Traversal: ");
    preorder(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Postorder Traversal: ");
    postorder(root, outputFile);
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
