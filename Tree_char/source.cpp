#include <stdio.h>
#include <stdlib.h>

// 二叉树结点结构体
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建二叉树
TreeNode* createBinaryTree() {
    char value;
    printf("Enter the value of the node (or z to exit): ");
    scanf_s(" %c", &value);

    if (value == 'z') {
        return NULL;
    }

    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;

    printf("Enter the left child of %c:\n", value);
    newNode->left = createBinaryTree();

    printf("Enter the right child of %c:\n", value);
    newNode->right = createBinaryTree();

    return newNode;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

void printLeavesWithDegreeOne(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        printf("%c ", root->data);
    }

    printLeavesWithDegreeOne(root->left);
    printLeavesWithDegreeOne(root->right);
}

int getTreeDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

int main() {
    printf("Enter the elements of the binary tree (or z to exit):\n");
    TreeNode* root = createBinaryTree();

    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Leaves with degree 1: ");
    printLeavesWithDegreeOne(root);
    printf("\n");

    int depth = getTreeDepth(root);
    printf("Tree depth: %d\n", depth);

    return 0;
}