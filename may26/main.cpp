#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        perm.reserve(nums.size());
        std::sort(nums.begin(), nums.end());
        permute(res, nums, perm);
        return res;
    }
private:
    void permute(vector<vector<int>>& res, vector<int>& nums, vector<int>& perm) {
        size_t size = nums.size();
        if(!size) {
            res.push_back(perm);
            return;
        }
        for(size_t i = 0; i < size; ++i) {
            int num = nums[i];
            size_t j = i + 1;
            while(j < size && num == nums[j]) ++j;
            perm.push_back(num);
            nums.erase(nums.begin() + i);
            permute(res, nums, perm);
            nums.insert(nums.begin() + i, num);
            perm.pop_back();
            i = j - 1;
        }
    }
};

int main() {

	Solution s;
	vector<int> ori(1, 1);
	vector<vector<int>> ret = s.permuteUnique(ori);
	return 0;
}