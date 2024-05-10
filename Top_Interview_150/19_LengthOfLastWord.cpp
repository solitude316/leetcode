/**
 * 58. Length of Last Word
 * https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
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
    int lengthOfLastWord(string s) {
        int str_length = s.length();

        if (str_length == 0) {
            return 0;
        }
        else if (str_length == 1) {
            if (s == " ") {
                return 0;
            }
            else {
                return 1;
            }
        }

        int end_pos = str_length - 1;
        int start_pos = 0;

        while (s[end_pos] == ' ') {
            end_pos--;
        }

        cout << "end_pos = " << end_pos << endl;
        cout << "s[end_pos] = " << s[end_pos] << endl;

        start_pos = end_pos;

        while (s[start_pos] != ' ') {
            start_pos--;
            if (start_pos < 0) {
                break;
            }
        }
        cout << "start_pos = " << start_pos << endl;

        return end_pos - start_pos;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    string world;

    world = "a ";
    cout << world << " = " << solution.lengthOfLastWord(world) << endl;

    return 0;
}