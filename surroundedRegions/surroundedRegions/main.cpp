//
//  main.cpp
//  surroundedRegions
//
//  Created by Suyu Pan on 6/9/15.
//  Copyright (c) 2015 sp. All rights reserved.
//
/**
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 
 X X X X
 X X X X
 X X X X
 X O X X
 */
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int row = static_cast<int>(board.size());
        int col = static_cast<int>(board[0].size());
        if(row < 3 || col < 3) return;
        
        for (int i = 0; i < row; ++i) {
            solve(board, i, 0);
            solve(board, i, col - 1);
        }
        for (int j = 1; j < col - 1; ++j) {
            solve(board, 0, j);
            solve(board, row - 1, j);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                char *c = &board[i][j];
                if (*c == 'X') continue;
                if (*c == '1') *c = 'O';
                else *c = 'X';
            }
        }
    }
    
private:
    void solve(vector<vector<char>>& board, int i, int j) {
        char *c = &board[i][j];
        if(*c != 'O') return;
        *c = '1';
        
        queue<pair<int, int>> flips;
        flips.push({i, j});
        while(!flips.empty()) {
            pair<int, int> &pos = flips.front();
            flips.pop();
            for(int k = 0; k < 4; ++k) {
                int x = pos.first, y = pos.second;
                char *tmp = getAdjacent(board, x, y, k);
                if(!tmp || *tmp != 'O') continue;
                *tmp = '1';
                flips.push({x, y});
            }
        }
    }
    
    inline char * getAdjacent(vector<vector<char>>& board, int &i, int &j, int direction) {
        // top: 0, right: 1, bottom: 2, left: 3
        switch(direction) {
            case 0: i -= 1; break;
            case 1: j += 1; break;
            case 2: i += 1; break;
            case 3: j -= 1; break;
            default: break;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return NULL;
        return &board[i][j];
    }
};


#pragma mark - TODO : has beter solution
/**
 * This is not a good solution.
 * Only need to check four boarders and flip all isolated inner 'O's.
 */
class Solution2 {
public:
    void solve(vector<vector<char>>& board) {
        list<char *> visited;
        list<char *>::iterator itr;
        for(size_t i = 0; i < board.size(); ++i) {
            for(size_t j = 0; j < board[0].size(); ++j) {
                char *c = &board[i][j];
                if(*c == 'X' || *c == '1') continue;
                // breadth-first-search
                
                *c = '1';
                visited.push_back(c);
                itr = visited.end();
                --itr;
                bool shouldFlip = true;
                
                queue<pair<size_t, size_t>> flips;
                flips.push({i, j});
                while(!flips.empty()) {
                    pair<size_t, size_t> &pos = flips.front();
                    flips.pop();
                    for(int k = 0; k < 4; ++k) {
                        int x = (int)pos.first, y = (int)pos.second;
                        char *tmp = getAdjacent(board, x, y, k);
                        if(!tmp) {
                            shouldFlip = false;
                            continue;
                        }
                        if(*tmp == 'X' || *tmp == '1') continue;
                        *tmp = '1';
                        flips.push({x, y});
                        visited.push_back(tmp);
                    }
                }
                
                if(shouldFlip) {
                    for_each(itr, visited.end(), [&](char *c) { *c = 'X'; });
                    visited.erase(itr, visited.end());
                }
            }
        }
        for_each(visited.begin(), visited.end(), [&](char *c) { *c = 'O'; });
    }
    
private:
    char * getAdjacent(vector<vector<char>>& board, int &i, int &j, int direction) {
        // top: 0, right: 1, bottom: 2, left: 3
        switch(direction) {
            case 0: i -= 1; break;
            case 1: j += 1; break;
            case 2: i += 1; break;
            case 3: j -= 1; break;
            default: break;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return NULL;
        return &board[i][j];
    }
};

template <class T>
static void printBoard(const vector<vector<T>> &board) {
    for(size_t i = 0; i < board.size(); ++i) {
        for(size_t j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    s.solve(board);
    
    printBoard(board);
    
    return 0;
}
