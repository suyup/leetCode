//
//  main.cpp
//  decodeWays
//
//  Created by Suyu Pan on 6/21/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
 
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /**
         * Two subproblems per level:
         * 1:n-1
         * 2:n-2
         * f(n) = c1 * f(n - 1) + c2 * f(n - 2)
         */
        size_t n = s.size();
        if(!n || s[0] == '0') return 0;
        if(n == 1) return 1;
        
        int res = 0, sub_1 = 1, sub_2 = 1;
        
        for(size_t i = 1; i < n; ++i) {
            bool v1 = isValid(s[i]);
            bool v2 = isValid(s[i - 1], s[i]);
            
            if(v1 && v2) res = sub_1 + sub_2;
            else if(!v1 && v2) res = sub_2;
            else if(v1 && !v2) res = sub_1;
            else if(!v1 && !v2) return 0;
            
            int tmp = sub_1;
            sub_1 = res;
            sub_2 = tmp;
        }
        return res;
    }
    
    bool isValid(const char &c) {
        return c != '0';
    }
    
    bool isValid(const char &a, const char &b) {
        return a == '1' || (a == '2' && b <= '6');
    }
};



int main(int argc, const char * argv[]) {
    
    string str = "123943289317856183419313102398";
    
    Solution s;
    
    cout << s.numDecodings(str) << endl;
    
    return 0;
}
