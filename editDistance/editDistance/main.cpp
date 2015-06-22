//
//  main.cpp
//  editDistance
//
//  Created by Suyu Pan on 6/21/15.
//  Copyright (c) 2015 sp. All rights reserved.
//
/**
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#pragma mark - TOOD: use O(n) space?

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size(), n = (int)word2.size();
        if(!m || !n) return m + n;
        int dp[m + 1][n + 1];
        for(int i = 0; i <= m; ++i) dp[i][0] = i;
        for(int j = 1; j <= n; ++j) dp[0][j] = j;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                int cost = word1[i-1] == word2[j-1] ? 0 : 1;
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + cost);
            }
        }
        
#if 1
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
#endif
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.minDistance("algorithm", "complexity") << std::endl;
    return 0;
}
