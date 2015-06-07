#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(!strs.size()) return string();
    	string prefix = string();
    	for(unsigned i = 0; i < strs[0].length(); i++) {
    		bool flag = true;
    		for(unsigned j = 0; j < strs.size(); j++) {
    			if(strs[j].length() >= i) return prefix;
    			if(strs[j][i] != strs[0][i]) {
    				flag = false;
    				break;
    			}
    		}
    		const char* c = &strs[0][i];
    		if(flag) prefix.append(c);
       		else return prefix;
    	}
    	return prefix;
    }
};

int main() {
	Solution s;
	std::vector<string> v;
	v.push_back("a");
	string m = s.longestCommonPrefix(v);
	std::cout << m << std::endl;
	return 0;
}
