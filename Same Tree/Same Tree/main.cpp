//
//  main.cpp
//  Same Tree
//
//  Created by Patrick on 9/23/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> s;
        /**
         * push regardless if object is NULL or not
         */
        s.push(p); s.push(q);
        
        while (!s.empty()) {
            TreeNode *y = s.top();
            s.pop();
            TreeNode *x = s.top();
            s.pop();
            
            if (!x && !y) continue;
            else if (!x || !y) return false;
            else if (x->val != y->val) return false;
            
            s.push(x->left);
            s.push(y->left);
            s.push(x->right);
            s.push(y->right);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    bool ret = s.isSameTree(NULL, NULL);
    cout << (ret ? "true" : "false") << endl;
    return 0;
}
