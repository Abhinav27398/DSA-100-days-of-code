// C program for zigzag (spiral) level order traversal of a binary tree
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Zigzag (spiral) level order traversal
void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    // Queue for BFS
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1; // flag to alternate direction

    while (front < rear) {
        int levelSize = rear - front;
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", level[i]);
        }
        printf("\n");

        free(level);
        leftToRight = !leftToRight; 
    }
}

int main() {
    
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Zigzag (Spiral) Level Order Traversal:\n");
    zigzagTraversal(root);

    return 0;
}