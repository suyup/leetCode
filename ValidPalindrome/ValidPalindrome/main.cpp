//
//  main.cpp
//  ValidPalindrome
//
//  Created by Patrick on 9/22/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
//    bool isPalindrome(string s) {
//        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
//        return isPalindrome(s, 0, (int)s.size() - 1);
//    }
//    
//    bool isPalindrome(string &s, int f, int b) {
//        if (f >= b) return true;
//        
//        while(f < b && !isalnum(s[f])) ++f;
//        while(f < b && !isalnum(s[b])) --b;
//        
//        if(f >= b) return true;
//        
//        if (s[f] != s[b]) return false;
//        
//        return isPalindrome(s, ++f, --b);
//    }
    bool isPalindrome(string s) {
        for (int i = 0, j = (int)s.size() - 1; i < j; ++i, --j) {
            while (isalnum(s[i]) == false && i < j) ++i;
            while (isalnum(s[j]) == false && i < j) --j;
            if (toupper(s[i]) != toupper(s[j])) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str1 = ",.";
    string str2 = "a man, a plan, a canal: panama";
    string str3 = "A man, a plan, a canal: Panama";
    bool ret = s.isPalindrome(str1);
    std::cout << (ret ? "true" : "false") << std::endl;
    return 0;
}
