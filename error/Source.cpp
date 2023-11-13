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
    char value = 'A';
    int d;// 声明并初始化字符变量
    printf("Enter the value of the node (or z to exit): ");
    d = scanf_s("%c", &value);
    if (d!= 1) {
            // 处理输入失败的情况
        }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    //如果在终端不进行输入该程序会自动结束(while的意思就是说当当前输入缓存还有东西时就一直读取，直到输入缓存中的内容为空时停止)。
    //在这"scanf(" % d",&n) != EOF"相当于"scanf(" % d",&n) != EOF"，或"~scanf(" % d",&n)"，或"scanf(" % d",&n) == 1 " 。
    /*请注意，scanf函数会留下换行符（\n）在输入缓冲区中。
      因此，当您在使用getchar和scanf之间切换时，可能需要清除输入缓冲区中的剩余换行符。*/
    //scanf的读取原理是匹配字符，当scanf从缓冲区读取数据时遇到空格和回车键则会认为读取完毕
    /*
    （1）使用gets(buf); 替换scanf("%s", buf);
       即可，但是编译时系统会报警告，说它不安全，因为gets()不能指定获取数据的长度，故可使用fgets()
    （2）使用fgets(buf, 20, stdin); 替换scanf("%s", buf);  即可
    */
    if (value == 'z') {
        return NULL;
    }
    /*缓冲区问题：scanf函数通常会从标准输入流（stdin）中读取数据，并将其存储在指定的变量中。如果在调用scanf之前有其他输入操作，可能会导致输入缓冲区中仍然存在未读取的数据，从而导致scanf无法正常执行输入。在调用scanf之前，可以尝试清空输入缓冲区，例如通过使用fflush(stdin)或while(getchar() != '\n')来清除缓冲区中的剩余数据。

错误的格式化字符串：scanf函数的第一个参数是格式化字符串，用于指定输入的预期格式。如果格式化字符串与输入数据不匹配，scanf可能会失败或输入不正确。请确保格式化字符串正确匹配您要输入的数据类型，并使用正确的格式说明符。

输入流结束：如果输入流已经结束，例如在文件末尾或者通过重定向输入，scanf函数将无法继续读取数据。请确保输入流中存在足够的数据供scanf读取。

输入阻塞：如果您的程序在等待输入时被阻塞，可能是因为输入操作暂停或被其他程序占用。请确保您的程序可以正常获取输入，并且没有其他进程或线程在占用输入资源。

代码逻辑问题：检查您的代码逻辑，确保在调用scanf之前没有错误或逻辑问题导致无法执行输入。例如，可能需要在调用scanf之前打开文件或初始化相关变量。*/
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;

    printf("Enter the left child of %c:\n", value);
    newNode->left = createBinaryTree();

    printf("Enter the right child of %c:\n", value);
    newNode->right = createBinaryTree();

    return newNode;
}


// 中序遍历二叉树
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

// 输出度为1的叶子结点
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
    printf("Enter the elements of the binary tree (or z to exit):\n");
    TreeNode* root = createBinaryTree();

    printf("\n");

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

    system("pause");

    return 0;
}