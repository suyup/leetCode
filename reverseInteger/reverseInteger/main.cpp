//
//  main.cpp
//  reverseInteger
//
//  Created by Suyu Pan on 5/28/15.
//  Copyright (c) 2015 Suyu Pan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

size_t highestBitPos(int x) {
    size_t bits = 0;
    while (x) {
        ++bits;
        x >>= 1;
    };
    return bits;
}

bool canSafeAdd(int a, int b) {
    size_t high = a > 0 ? 15 : 16;
    return highestBitPos(a) < high && highestBitPos(b) < high;
}

bool canSafeMultiply(int a, int b) {
    size_t high = a > 0 ? 15 : 16;
    return highestBitPos(a) + highestBitPos(b) < high;
}

int reverse(int x) {
    int ret = 0;
    while(x) {
        if(!canSafeMultiply(ret, 10)) return 0;
        ret = 10 * ret;
        int add = x % 10;
        if(!canSafeAdd(ret, add)) return 0;
        ret += add;
        x /= 10;
    }
    return ret;
}

void rotate(vector<int>& nums, int k) {
    unsigned n = (unsigned)nums.size();
    if(!n) return;
    int step = k % n;
    if(step < 0) step += n;
    int i = 0;
    while(1) {
        int j = (i + step) % n;
        if(!j) return;
        int tmp = nums[j];
        nums[j] = nums[0];
        nums[0] = tmp;
        i = j;
    }
}

int main(int argc, const char * argv[]) {
//    std::cout << reverse(1534239) << std::endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    rotate(nums, 2);
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    std:cout << std::endl;
    return 0;
}
