#include <stdio.h>
#include <stdlib.h>

// ���������ṹ��
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ����������
TreeNode* createBinaryTree() {
    char value = 'A';
    int d;// ��������ʼ���ַ�����
    printf("Enter the value of the node (or z to exit): ");
    d = scanf_s("%c", &value);
    if (d!= 1) {
            // ��������ʧ�ܵ����
        }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    //������ն˲���������ó�����Զ�����(while����˼����˵����ǰ���뻺�滹�ж���ʱ��һֱ��ȡ��ֱ�����뻺���е�����Ϊ��ʱֹͣ)��
    //����"scanf(" % d",&n) != EOF"�൱��"scanf(" % d",&n) != EOF"����"~scanf(" % d",&n)"����"scanf(" % d",&n) == 1 " ��
    /*��ע�⣬scanf���������»��з���\n�������뻺�����С�
      ��ˣ�������ʹ��getchar��scanf֮���л�ʱ��������Ҫ������뻺�����е�ʣ�໻�з���*/
    //scanf�Ķ�ȡԭ����ƥ���ַ�����scanf�ӻ�������ȡ����ʱ�����ո�ͻس��������Ϊ��ȡ���
    /*
    ��1��ʹ��gets(buf); �滻scanf("%s", buf);
       ���ɣ����Ǳ���ʱϵͳ�ᱨ���棬˵������ȫ����Ϊgets()����ָ����ȡ���ݵĳ��ȣ��ʿ�ʹ��fgets()
    ��2��ʹ��fgets(buf, 20, stdin); �滻scanf("%s", buf);  ����
    */
    if (value == 'z') {
        return NULL;
    }
    /*���������⣺scanf����ͨ����ӱ�׼��������stdin���ж�ȡ���ݣ�������洢��ָ���ı����С�����ڵ���scanf֮ǰ������������������ܻᵼ�����뻺��������Ȼ����δ��ȡ�����ݣ��Ӷ�����scanf�޷�����ִ�����롣�ڵ���scanf֮ǰ�����Գ���������뻺����������ͨ��ʹ��fflush(stdin)��while(getchar() != '\n')������������е�ʣ�����ݡ�

����ĸ�ʽ���ַ�����scanf�����ĵ�һ�������Ǹ�ʽ���ַ���������ָ�������Ԥ�ڸ�ʽ�������ʽ���ַ������������ݲ�ƥ�䣬scanf���ܻ�ʧ�ܻ����벻��ȷ����ȷ����ʽ���ַ�����ȷƥ����Ҫ������������ͣ���ʹ����ȷ�ĸ�ʽ˵������

����������������������Ѿ��������������ļ�ĩβ����ͨ���ض������룬scanf�������޷�������ȡ���ݡ���ȷ���������д����㹻�����ݹ�scanf��ȡ��

����������������ĳ����ڵȴ�����ʱ����������������Ϊ���������ͣ����������ռ�á���ȷ�����ĳ������������ȡ���룬����û���������̻��߳���ռ��������Դ��

�����߼����⣺������Ĵ����߼���ȷ���ڵ���scanf֮ǰû�д�����߼����⵼���޷�ִ�����롣���磬������Ҫ�ڵ���scanf֮ǰ���ļ����ʼ����ر�����*/
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;

    printf("Enter the left child of %c:\n", value);
    newNode->left = createBinaryTree();

    printf("Enter the right child of %c:\n", value);
    newNode->right = createBinaryTree();

    return newNode;
}


// �������������
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

// �������������
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

// �����Ϊ1��Ҷ�ӽ��
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
    printf("Enter the elements of the binary tree (or z to exit):\n");
    TreeNode* root = createBinaryTree();

    printf("\n");

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

    system("pause");

    return 0;
}