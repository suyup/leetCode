//
//  main.cpp
//  twoSum
//
//  Created by Suyu Pan on 6/9/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for(size_t i = 0; i < nums.size(); ++i) {
            auto &&itr = hashTable.find(nums[i]);
            if(itr != hashTable.end()) return vector<int>({(int)itr->second, (int)i});
            hashTable.insert(pair<int, int>(target - nums[i], i));
        }
        return vector<int>(2, 0);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> vec = {2, 45, 3, 0, 2, 8, 1};
    vector<int> res = s.twoSum(vec, 8);
    
    for_each(res.begin(), res.end(), [&](int num){cout << num << " ";});
    cout << endl;
    
    return 0;
}
