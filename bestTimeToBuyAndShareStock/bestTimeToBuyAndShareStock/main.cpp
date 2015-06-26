//
//  main.cpp
//  bestTimeToBuyAndShareStock
//
//  Created by Suyu Pan on 6/25/15.
//  Copyright (c) 2015 sp. All rights reserved.
//
/**
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int buy = prices[0], res = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - buy;
            if (profit < 0)
                buy = prices[i];
            else
                res = max(res, profit);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices = {5, 10, 0, 2, 5, 4, 9, 19, 3, 3, 1, 5};
    std::cout << s.maxProfit(prices) << std::endl;
    return 0;
}
