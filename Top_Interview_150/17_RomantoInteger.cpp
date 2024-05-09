/**
 * 13. Roman to Integer


 * https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
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
    int romanToInt(string s) {
        int answer = 0;

        for (int i = 1; i <= s.length(); i++) {
            int pos = s.length() - i;
            string c = s.substr(pos, 1);
             if (c == "I") {
                answer++;
            }
            else if (c == "V") {
                 answer += 5;
                 if (pos > 0 && s.substr(pos - 1, 1) == "I") {
                     answer--;
                     i++;
                 }
            }
            else if (c == "X") {
                 answer += 10;
                 if (pos > 0 && s.substr(pos - 1, 1) == "I") {
                     answer--;
                     i++;
                 }
            }
            else if (c == "L") {
                 answer += 50;
                 if (pos > 0 && s.substr(pos - 1, 1) == "X") {
                     answer -= 10;
                     i++;
                 }
            }
            else if (c == "C") {
                 answer += 100;
                 if (pos > 0 && s.substr(pos - 1, 1) == "X") {
                     answer -= 10;
                     i++;
                 }
            }
            else if (c == "D") {
                 answer += 500;
                 if (pos > 0 && s.substr(pos - 1, 1) == "C") {
                     answer -= 100;
                     i++;
                 }
            }
            else if (c == "M") {
                 answer += 1000;
                 if (pos > 0 && s.substr(pos - 1, 1) == "C") {
                     answer -= 100;
                     i++;
                 }
            }
            else {
                //return -1;
            }
        }

        return answer;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    string s;

    s = "III";
    cout << s << " = " << solution.romanToInt(s) << endl;

    s = "VIII";
    cout << s << " = " << solution.romanToInt(s) << endl;

    s = "IV";
    cout << s << " = " << solution.romanToInt(s) << endl;

    s = "IX";
    cout << s << " = " << solution.romanToInt(s) << endl;

    s = "LVIII";
    cout << s << " = " << solution.romanToInt(s) << endl;

    s = "MCMXCIV";
    cout << s << " = " << solution.romanToInt(s) << endl;

    return 0;
}