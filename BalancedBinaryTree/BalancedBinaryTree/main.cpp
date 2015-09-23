//
//  main.cpp
//  BalancedBinaryTree
//
//  Created by Patrick on 9/19/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        else if (!root->left && !root->right) return true;
        else if (root->left && root->right) return isBalanced(root->left) && isBalanced(root->right);
        else if (!root->left) {
            if (root->right->left || root->right->right) return false;
        } else {
            if (root->left->left || root->left->right) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new TreeNode(0);
    TreeNode *leaf = new TreeNode(1);
    root->right = leaf;
    
    Solution s;
    bool b = s.isBalanced(root);
    
    cout << b << endl;
    
    delete root; root = NULL;
    delete leaf; leaf = NULL;
    return 0;
    
    vector<int> a;
    std::reverse(a.begin(), a.end());
}
