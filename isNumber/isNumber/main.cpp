//
//  main.cpp
//  isNumber
//
//  Created by Suyu Pan on 5/28/15.
//  Copyright (c) 2015 Suyu Pan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(!s.size()) return false;
        bool hasDot = false, hasEpo = false, hasNum = false, hasSpc = false, isSpcPre = false;
        int flag = parse(s[0]);
        if(!flag || flag == 4) return false;
        else if(flag == 1) hasNum = true;
        else if(flag == 3) hasDot = true;
        else if(flag == 5) isSpcPre = true;
        for(size_t i = 1; i < s.size(); ++i) {
            switch(parse(s[i])) {
                case 1: {
                    hasNum = true;
                    break;
                }
                case 2: {
                    if(parse(s[i - 1]) != 4) return false;
                    if(i == s.size() - 1) return false;
                    else {
                        int tmp = parse(s[i + 1]);
                        if(!(tmp == 1 || tmp == 3)) return false;
                    }
                    break;
                }
                case 3: {
                    if(hasDot) return false;
                    else hasDot = true;
                    if(hasEpo) return false;
                    break;
                }
                case 4: {
                    if(hasEpo) return false;
                    else hasEpo = true;
                    if(!hasNum) return false;
                    if(i == s.size() - 1) return false;
                    else {
                        int tmp = parse(s[i + 1]);
                        if(!(tmp == 1 || tmp == 2)) return false;
                    }
                    break;
                }
                case 5: {
                    if(!isSpcPre) hasSpc = true;
                    continue;
                }
                default: return false;
            }
            if(hasSpc) return false;
            isSpcPre = false;
        }
        return hasNum;
    }
private:
    int parse(const char &c) {
        switch(c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': {
                return 1;
            }
            case '+': case '-': {
                return 2;
            }
            case '.': {
                return 3;
            }
            case 'e': {
                return 4;
            }
            case ' ': {
                return 5;
            }
            default: return 0;
        }
    }
    /*
     *   valid characters: -, +, e, 0 ~ 9, ., ' '
     *   valid numbers: 1, -2, +3, .4, 5., 6.7, 8e90, 4.e3, ' 1', '2 '
     *   not valid: 0e, '1  3'
     *   first character: -, +, ., 0 ~ 9
     */
};

int main(int argc, const char * argv[]) {
    Solution s;
    bool res = s.isNumber(" -2.3");
    cout << (res ? "true" : "false") << endl;
    return 0;
}
