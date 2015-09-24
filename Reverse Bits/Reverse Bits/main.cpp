//
//  main.cpp
//  Reverse Bits
//
//  Created by Patrick on 9/23/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int r = 0;
        for (int i = 0; i < 32; ++i) {
            int b = n & 1;
            r = (r << 1) + b;
            n = n >> 1;
        }
        return r;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.reverseBits(1) << std::endl;
    return 0;
}
