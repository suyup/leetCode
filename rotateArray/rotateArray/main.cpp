//
//  main.cpp
//  rotateArray
//
//  Created by Suyu Pan on 6/7/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        if(!n) return;
        k = k % n;
        if(!k) return;
        else if(k < 0) k += n;
        reverse(nums, 0, n - 1 - k);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
private:
    void reverse(vector<int>& nums, size_t begin, size_t end) {
        size_t j = (end - begin + 1) / 2;
        for(size_t i = 0; i < j; ++i) {
            swap(nums[begin + i], nums[end - i]);
        }
    }
};

template <class T>
void printVector(vector<T> & vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3};
    Solution s;
    s.rotate(nums, 2);
    printVector(nums);
    return 0;
}
