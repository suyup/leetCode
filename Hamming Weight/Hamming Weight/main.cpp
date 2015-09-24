//
//  main.cpp
//  Hamming Weight
//
//  Created by Patrick on 9/23/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <bitset>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // O(m) where m = hamming weight.
        ++counta;
        return n ? 1 + hammingWeight(n & (n - 1)) : 0;
    }
    
    int myHammingWeight(uint32_t n) {
        // O(n) where n = 32
        ++countb;
        return n ? myHammingWeight(n >> 1) + (n >> 1 << 1 ^ n) : 0;
    }
    
    int counta;
    int countb;
};

int main(int argc, const char * argv[]) {
    Solution s;
    uint32_t integer = 2342103534;
    std::bitset<32> bs(integer);
    std::cout << bs.count() << " " << bs.to_string() << std::endl;
    int ret = s.hammingWeight(integer);
    std::cout << ret << " " << s.counta << std::endl;
    ret = s.myHammingWeight(integer);
    std::cout << ret << " " << s.countb << std::endl;
    return 0;
}
