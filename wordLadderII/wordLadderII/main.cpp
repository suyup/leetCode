//
//  main.cpp
//  wordLadderII
//
//  Created by Suyu Pan on 6/7/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class Solution_So_Slow {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        return generateTree(end, start, dict);
    }
private:
    static inline bool canTransform(const string &a, const string &b) {
        int diff = 0;
        for(size_t i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) ++diff;
        }
        return diff == 1;
    }
    
    struct TreeNode {
        string word;
        unsigned level;
        TreeNode *parent;
        unordered_set<TreeNode *> children;
        unordered_set<string> dict;
        
        TreeNode(const string &w, unsigned l, TreeNode *p, unordered_set<string> &d) : word(w), level(l), parent(p), dict(d) {
            dict.erase(word);
        }
        
        void setChildren(unordered_set<string> &dict) {
            for (auto itr = dict.begin(); itr != dict.end(); ++itr) {
                if (canTransform(word, *itr)) {
                    TreeNode child(*itr, level + 1, this, dict);
                    children.insert(&child);
                }
            }
        }
        
        bool hasChildren() const { return children.empty(); }
    };
    
    /* 
     * breath-first
     */
    vector<vector<string>> generateTree(const string &start, const string &end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        size_t minimumStep = -1;
        queue<TreeNode *> que;
        TreeNode root(start, 0, NULL, dict);
        
        que.push(&root);
        while (!que.empty()) {
            TreeNode node = *que.front();
            que.pop();
            
            if (node.word.compare(end) == 0) {
                minimumStep = node.level;
                ret.push_back(printPath(&node));
                continue;
            } else if(minimumStep != -1) continue;
            
            node.setChildren(dict);
            
            for (auto itr = node.children.begin(); itr != node.children.end(); ++itr) {
                que.push(*itr);
            }
        }
        
        return ret;
    }
    
    vector<string> printPath(TreeNode *node) {
        vector<string> ret;
        while(node) {
            ret.push_back(node->word);
            node = node->parent;
        }
        return ret;
    }
};


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        unordered_map<string, vector<vector<string>>> left, right;
        unordered_map<string, vector<vector<string>>> *a_ptr = &left, *b_ptr = &right;
        left.insert({start, {1, {1, start}}});
        right.insert({end, {1, {1, end}}});
        dict.erase(start);
        dict.erase(end);
        bool shouldStop = false;
        
        while(!shouldStop) {
            unordered_map<string, vector<vector<string>>> tmp;
            unordered_set<string> deletingDict;
            
            for(pair<string, vector<vector<string>>> &&p : *a_ptr) {
                for(size_t i = 0; i < start.size(); ++i) {
                    for(char c = 'a'; c <= 'z'; ++c) {
                        string s(p.first);
                        s[i] = c;
                        auto &&itr = (*b_ptr).find(s);
                        
                        // found!
                        if (itr != right.end()) {
                            vector<vector<string>> *left_paths;
                            vector<vector<string>> *right_paths;
                            if (a_ptr == &left) {
                                left_paths = &p.second;
                                right_paths = &(*itr).second;
                            } else {
                                left_paths = &(*itr).second;
                                right_paths = &p.second;
                            }
                            
                            for(auto &&l : *left_paths) {
                                for(auto &&r : *right_paths) {
                                    vector<string> vec(l);
                                    vec.insert(vec.end(), r.rbegin(), r.rend());
                                    ret.push_back(vec);
                                }
                            }
                            
                            shouldStop = true;
                            
                        } else if(dict.find(s) != dict.end()) {
                            for(auto path : p.second) {
                                path.push_back(s);
                                tmp[s].push_back(path);
                            }
                            deletingDict.insert(s);
                        }
                    }
                }
            } // end for
            
            for_each(deletingDict.begin(), deletingDict.end(), [&](const string &s){dict.erase(s);});
            
            if (tmp.empty()) shouldStop = true;
            
            if (!shouldStop) {
                *a_ptr = tmp;
                if(left.size() < right.size()) {
                    a_ptr = &left;
                    b_ptr = &right;
                } else {
                    a_ptr = &right;
                    b_ptr = &left;
                }
            }
        } // end while
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    unordered_set<string> aSet = {"hot","dot","dog","lot","log"};
    Solution s;
    vector<vector<string>> res = s.findLadders("hit", "cog", aSet);
    
    for (size_t i = 0; i < res.size(); ++i) {
        for (size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
