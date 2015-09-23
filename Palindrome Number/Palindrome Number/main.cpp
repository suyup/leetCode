//
//  main.cpp
//  Palindrome Number
//
//  Created by Patrick on 9/23/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
//        int d = 0, tmp = x;
//        while (tmp) {
//            ++d;
//            tmp /= 10;
//        }
//        
//        while(d > 1) {
//            int a = pow(10, d - 1), h = x / a;
//            if (x % 10 != h) return false;
//            x = (x - h * a) / 10;
//            d -= 2;
//        }
//        return true;
        if (x < 0) return false;
        int r = 0;
        while (x > r) {
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        return x == r || x == r / 10;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    bool ret = s.isPalindrome(10);
    std::cout << (ret ? "true" : "false") << std::endl;
    return 0;
}
