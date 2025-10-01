#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int findMaxValue(TreeNode* root) {
    // �p�G�`�I�O�Ū��A��^ INT_MIN
    if (root == nullptr) {
        return INT_MIN;
    }

    // ���j�a��X���k�l�𤤪��̤j��
    int leftMax = findMaxValue(root->left);
    int rightMax = findMaxValue(root->right);

    // ��^�ثe�`�I���ȻP���k�l��̤j�Ȫ��̤j��
    return max(root->value, max(leftMax, rightMax));
}

int main() {
    // �إߤ@�ӽd�ҤG����
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);

    // ��X�G���𪺳̤j��
    int maxValue = findMaxValue(root);
    cout << "Binary tree maximum value: " << maxValue << endl;

    // ����ʺA�O����
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
