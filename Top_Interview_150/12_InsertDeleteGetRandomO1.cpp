/**
 * 380. Insert Delete GetRandom O(1)
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

class RandomizedSet {
public:
    vector<int> set;


    RandomizedSet() {

    }

    bool insert(int val) {
        int index = 0;
        for (int i = 0; i < set.size(); i++) {
            index = i;
            if (val == set[i]) {
                return false;
            }
        }
        set.insert(set.begin() + index, val);
        return true;
    }

    bool remove(int val) {
        int index = 0;
        for (int i = 0; i < set.size(); i++) {
            index = i;
            if (val == set[i]) {
                set.erase(set.begin() + i);
                return true;
            }
        }
        return false;
    }

    int getRandom() {
        size_t index = rand() % set.size();
        return set[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main(int argc, char** argv) {
    bool result;

    RandomizedSet solution;
    printArr(solution.set, "initial");
 
    result = solution.insert(1);
    cout << "result = " << result << endl;
    printArr(solution.set, "insert 1");

    result = solution.remove(2);
    cout << "result = " << result << endl;
    printArr(solution.set, "remove 2");

    result = solution.insert(2);
    cout << "result = " << result << endl;
    printArr(solution.set, "insert 2");

    int output = solution.getRandom();
    cout << "output of solution.getRandom() = " << output << endl;
    printArr(solution.set, "get random");

    result = solution.remove(1);
    cout << "result = " << result << endl;
    printArr(solution.set, "remove 1");

    result = solution.insert(2);
    cout << "result = " << result << endl;
    printArr(solution.set, "insert 2");

    output = solution.getRandom();
    cout << "output of solution.getRandom() = " << output << endl;
    printArr(solution.set, "get random");

    return 0;
}