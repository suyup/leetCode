//
//  main.cpp
//  MaximumDepthofBinaryTree
//
//  Created by Patrick on 9/19/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <utility>
#include <stack>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        // return maxDepthRecursive(root);
        return maxDepthIterative(root);
    }
    
    int maxDepthRecursive(TreeNode *node) {
        if (!node) return 0;
        return max(maxDepthRecursive(node->left), maxDepthRecursive(node->right)) + 1;
    }
    
    int maxDepthIterative(TreeNode *root) {
        if (!root) return 0;
        stack<pair<TreeNode *, int>> s;
        s.push(make_pair(root, 1));
        int maxDepth = 1;
        while(!s.empty()) {
            TreeNode *node = s.top().first;
            int depth = s.top().second;
            if (depth > maxDepth) maxDepth = depth;
            s.pop();
            if(node->left) s.push(make_pair(node->left, depth + 1));
            if(node->right) s.push(make_pair(node->right, depth + 1));
        }
        return maxDepth;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new TreeNode(0);
    TreeNode *leaf = new TreeNode(1);
    root->right = leaf;
    
    Solution s;
    int depth = s.maxDepth(root);
    
    cout << depth << endl;
    
    delete root; root = NULL;
    delete leaf; leaf = NULL;
    return 0;
}
