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
    // 如果節點是空的，返回 INT_MIN
    if (root == nullptr) {
        return INT_MIN;
    }

    // 遞迴地找出左右子樹中的最大值
    int leftMax = findMaxValue(root->left);
    int rightMax = findMaxValue(root->right);

    // 返回目前節點的值與左右子樹最大值的最大值
    return max(root->value, max(leftMax, rightMax));
}

int main() {
    // 建立一個範例二元樹
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);

    // 找出二元樹的最大值
    int maxValue = findMaxValue(root);
    cout << "Binary tree maximum value: " << maxValue << endl;

    // 釋放動態記憶體
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
