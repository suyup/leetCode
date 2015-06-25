//
//  main.cpp
//  permutation
//
//  Created by Suyu Pan on 5/26/15.
//  Copyright (c) 2015 Suyu Pan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        perm.reserve(nums.size());
        map<int, int> map;
        permute(res, nums, perm, map);
        return res;
    }
private:
    void permute(vector<vector<int>>& res, vector<int>& nums, vector<int>& perm, map<int, int>& map) {
        size_t size = nums.size();
        if(!size) {
            res.push_back(perm);
            return;
        }
        for(size_t i = 0; i < size; ++i) {
            int num = nums[i];
            if(map.find(num) != map.end()) continue;
            map.insert(pair<int, int>(num, 1));
            perm.push_back(num);
            nums.erase(nums.begin() + i);
            permute(res, nums, perm, map);
            nums.insert(nums.begin() + i, num);
            perm.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> ori;
    ori.push_back(-1);
    ori.push_back(-1);
    ori.push_back(3);
    ori.push_back(-1);
    vector<vector<int>> ret = s.permuteUnique(ori);
    for (size_t i = 0; i < ret.size(); ++i) {
        for (size_t j = 0; j < ori.size(); ++j) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
