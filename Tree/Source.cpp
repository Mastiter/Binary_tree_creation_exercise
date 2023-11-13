#include <stdio.h>
#include <stdlib.h>

// 二叉树结点结构体
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建二叉树
TreeNode* createBinaryTree() {
    int value;
    printf("Enter the value of the node (or -114514 to exit): ");
    scanf_s("%d", &value);

    if (value == -114514) {
        return NULL;
    }

    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;

    printf("Enter the left child of %d:\n", value);
    newNode->left = createBinaryTree();

    printf("Enter the right child of %d:\n", value);
    newNode->right = createBinaryTree();

    return newNode;
}

// 中序遍历二叉树
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// 输出度为1的叶子结点
void printLeavesWithDegreeOne(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        printf("%d ", root->data);
    }

    printLeavesWithDegreeOne(root->left);
    printLeavesWithDegreeOne(root->right);
}

// 计算二叉树的深度
int getTreeDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

int main() {
    // 创建二叉树
    printf("Enter the elements of the binary tree (or -1 to exit):\n");
    TreeNode* root = createBinaryTree();

    // 中序遍历二叉树
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // 后序遍历二叉树
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // 输出度为1的叶子结点
    printf("Leaves with degree 1: ");
    printLeavesWithDegreeOne(root);
    printf("\n");

    // 计算二叉树的深度
    int depth = getTreeDepth(root);
    printf("Tree depth: %d\n", depth);

    return 0;
}