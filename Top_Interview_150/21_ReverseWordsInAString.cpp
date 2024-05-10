/**
 * 151. Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


void printArr(vector<string>& nums, const string title)
{
    cout << "=============== " << title << " ===============\n";
    cout << "(";
    vector<string>::iterator it;

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
    string reverseWords(string s) {
        vector<string> dict;

        int pos = 0;
        string temp;
        bool is_start = false;
        while (pos < s.length()) {
            if (s[pos] != ' ') {
                temp += s[pos];
                is_start = true;
            }
            else {
                if (is_start == true) {
                    dict.insert(dict.begin(), temp);
                    temp.clear();
                    is_start = false;
                }
            }

            pos++;
        }

        if (temp.length() > 0) {
            dict.insert(dict.begin(), temp);
            temp = "";
        }

        printArr(dict, "dict");

        string answer = "";
        for (size_t i = 0; i < dict.size(); i++) {
            answer += dict[i];
            answer += (i == dict.size() - 1) ? "" : " ";
        }

        return answer;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    string worlds;

    worlds = "  hello world  ";
    cout << "prefix  = " << solution.reverseWords(worlds) << endl;

    return 0;
}