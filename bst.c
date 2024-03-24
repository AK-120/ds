#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a data into the BST
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

// Function to find the node with the minimum data in the BST
int minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to delete a node with the given data from the BST
void deleteNode(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        deleteNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        deleteNode(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL) {
            struct Node* temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if ((*root)->right == NULL) {
            struct Node* temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            int minData = minValueNode((*root)->right);
            (*root)->data = minData;
            deleteNode(&(*root)->right, minData);
        }
    }
}

// Function to perform in-order traversal of the BST recursively
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal of the BST recursively
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to perform post-order traversal of the BST recursively
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to test the BST implementation
int main() {
    struct Node* root = NULL;
    int data, choice;

    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&root, data);
                break;
            case 3:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}