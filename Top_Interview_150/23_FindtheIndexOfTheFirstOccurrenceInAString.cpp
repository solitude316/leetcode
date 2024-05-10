/**
 * 28. Find the Index of the First Occurrence in a String
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
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
    int strStr(string haystack, string needle) {

        int haystack_len = haystack.length();
        int needle_len = needle.length();

        for (int i = 0; i < haystack_len - needle_len + 1; i++) {
            bool check = false;
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, needle.length()) == needle) {
                    return i;
                }
            }
        }
       
        return -1;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    string haystack;
    string needle;

    haystack = "a";
    needle = "a";
    cout << "prefix  = " << solution.strStr(haystack, needle) << endl;

    return 0;
}