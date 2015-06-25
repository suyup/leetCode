//
//  main.cpp
//  3SumClosest
//
//  Created by Suyu Pan on 6/21/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

/**
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 
 For example, given array S = {-1 2 1 -4}, and target = 1.
 
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int min_diff = INT_MAX;
        
        for(size_t i = 0; i < nums.size() - 2; ++i) {
            size_t start = i + 1;
            size_t end = nums.size() - 1;
            int t = target - nums[i];
            while(start < end) {
                int sum = nums[start] + nums[end];
                if(sum == t) return target;
                if(sum < t) {
                    int diff = t - sum;
                    if(abs(diff) < abs(min_diff)) {
                        min_diff = diff;
                    }
                    ++start;
                    while(start < end && nums[start - 1] == nums[start]) ++start;
                }
                else {
                    int diff = t - sum;
                    if(abs(diff) < abs(min_diff)) {
                        min_diff = diff;
                    }
                    --end;
                    while(start < end && nums[end + 1] == nums[end]) --end;
                }
            }
        }
        return target - min_diff;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
//    vector<int> vec = {-10, -8, -5, -2, -1};
//    vector<int> vec = {0 , 1, 2};
    vector<int> vec = {1,2,4,8,16,32,64,128};
    
    cout << s.threeSumClosest(vec, 88) << endl;
    
    return 0;
}
