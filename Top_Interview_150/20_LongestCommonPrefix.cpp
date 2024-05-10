/**
 * 14. Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

void printArr(vector<int>& nums, const string title)
{
    cout << "=============== " << title << " ===============\n";
    cout << "(";
    vector<int>::iterator it;

    for (it = nums.begin(); it != nums.end(); it++) {
        cout << *it;
        if (it != nums.end() - 1) {
            cout << ", ";
        }
    }

    cout << ")\n\n";
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stringstream prefix;
        int pos = 0;
        bool check = true;
        size_t shortist_word_index = 0;

        
        if (strs.size() == 0) {
            return "";
        }
        
        int min_length = strs[0].length();

        for (size_t i = 1; i < strs.size(); i++) {
            if (strs[i].length() < min_length) {
                min_length = strs[i].length();
                shortist_word_index = i;
            }
        }

        cout << "strs[" << shortist_word_index << "] = " << strs[shortist_word_index] << endl;
        check = true;
        for (int i = 0; i < strs[shortist_word_index].length(); i++) {
            
            cout << "strs[shortist_word_index][i] = " << strs[shortist_word_index][i] << endl;

            for (size_t j = 0; j < strs.size(); j++) {
                cout << strs[j] << ", strs[" << j <<"][" << i << "] = " << strs[j][i] << endl;
                cout << "strs[" << shortist_word_index << "][" << i <<"] = " << strs[shortist_word_index][i] << endl;
                if (strs[j][i] != strs[shortist_word_index][i]) {
                    check = false;
                    break;
                }
            }

            if (check == false) {
                break;
            }

            prefix << strs[shortist_word_index][i];
        }

        return prefix.str();
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<string> worlds;

    //worlds = { "flower","flow","flight" };
    //cout << "prefix  = " << solution.longestCommonPrefix(worlds) << endl;

    //worlds = { "dog","racecar","car" };
    //cout << "prefix  = " << solution.longestCommonPrefix(worlds) << endl;

    worlds = { "cir","car" };
    cout << "prefix  = " << solution.longestCommonPrefix(worlds) << endl;

    return 0;
}