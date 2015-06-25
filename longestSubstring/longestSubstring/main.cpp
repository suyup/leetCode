//
//  main.cpp
//  longestSubstring
//
//  Created by Patrick on 6/24/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * wrong answer: watch out unordered_set
 */
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> aSet;
        int max = 0;
        for(size_t i = 0; i < s.size(); i++) {
            auto iter = aSet.find(s[i]);
            if(iter != aSet.end()) aSet.erase(aSet.begin(), iter);
            /**
             * Insert will change order if its count is larger than bucket size.
             */
            aSet.insert(s[i]);
            if(max < aSet.size()) max = (int)aSet.size();
            for ( const char x: aSet ) std::cout << x << " ";
            cout << endl;
        }
        return max;
    }
};

/**
 * err...
 */
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int orderTable[256] = {0};
        int max = 0, deleted = 0, size = (int)s.size();
        for(int i = 0; i < size; ++i) {
            int order = orderTable[s[i]];
            if(order != 0) {
                for(size_t j = 0; j < 256; ++j) {
                    int &tmp = orderTable[j];
                    if(tmp && order >= tmp) {
                        orderTable[j] = 0;
                        ++deleted;
                        if (deleted == order) break;
                    }
                }
            }
            orderTable[s[i]] = i + 1;
            int subStrNum = i + 1 - deleted;
            if (max < subStrNum) max = subStrNum;
#if 1
            for (size_t j = 0; j < 256; ++j) {
                cout << getChar(s, orderTable[j], 0);
            }
            cout << " | deleted: "<< deleted << " | max: " << max << " | " << s[i] << endl;
#endif
        }
#if 0
        for (size_t j = 0; j < 256; ++j) {
            cout << getChar(s, orderTable[j], 0);
        }
        cout << endl;
#endif
        return max;
    }
    
private:
    char getChar(const string &s, int i, bool option) const {
        if (i == 0) return (option ? '_' : '\0');
        return s[i - 1];
    }
};

/**
 *  not so fast
 */
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.size();
        if (!n || n == 1) return static_cast<int>(n);
        unordered_map<char, size_t> aMap;
        size_t max = 0, deleted = 0;
        for(size_t i = 0; i < n; ++i) {
            size_t & index = aMap[s[i]];
            if(index && index > deleted) deleted = index;
            index = i + 1;
            size_t length = i + 1 - deleted;
            if(max < length) max = length;
#if 1
            for (auto iter = aMap.begin(); iter != aMap.end(); ++iter) {
                cout << iter->first << ":" << iter->second << " ";
            }
            cout << endl << max << " " << deleted << endl;
#endif
        }
        return static_cast<int>(max);
    }
};


/**
 * I always like bitmask
 * A DP?
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256] = {};
        int start = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, flag[s[i]]);
            flag[s[i]] = i + 1;
            res = max(res, i - start + 1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;
    return 0;
}
