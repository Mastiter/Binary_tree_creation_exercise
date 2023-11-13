#include <stdio.h>
#include <stdlib.h>

// ���������ṹ��
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ����������
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

// �������������
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// �������������
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// �����Ϊ1��Ҷ�ӽ��
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

// ��������������
int getTreeDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

int main() {
    // ����������
    printf("Enter the elements of the binary tree (or -1 to exit):\n");
    TreeNode* root = createBinaryTree();

    // �������������
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // �������������
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // �����Ϊ1��Ҷ�ӽ��
    printf("Leaves with degree 1: ");
    printLeavesWithDegreeOne(root);
    printf("\n");

    // ��������������
    int depth = getTreeDepth(root);
    printf("Tree depth: %d\n", depth);

    return 0;
}