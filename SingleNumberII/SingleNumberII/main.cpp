//
//  main.cpp
//  SingleNumberII
//
//  Created by Suyu Pan on 8/2/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t size = nums.size();
        if (!size) return 0;
        int one = 0;    /**< bit mask shows bits appear only once */
        int two = 0;    /**< bit mask shows bits appear once or twice */
        int thr = 0;    /**< bit mask shows bits appear once or twice or three times */
        for (size_t i = 0; i < size; ++i) {
            int num = nums[i];
            thr ^= two & one & num;
            two ^= one & num;
            one ^= num;
            int mask = ~(~one & ~two & thr);    // 4: 100
            thr &= mask;
            two &= mask;
            one &= mask;
            
            std::cout << thr << " " << two << " " << one << " " << mask << std::endl;
        }
        return one;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> vec = {2, 3, 2, 2, 2};
    std::cout << s.singleNumber(vec) << std::endl;
    return 0;
}