// problem: https://leetcode.com/problems/permutations/
// hint: implementation
// level: easy
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
private:
    void remove(vector<int> &list, int prev, int i) {
        int next = list[i];
        list[prev] = next;
        list[i] = prev;
    }
    void restore(vector<int> &list, int i) {
        int prev = list[i];
        int next = list[prev];
        list[prev] = i;
        list[i] = next;
    }
    void permute(vector<int> &nums, vector<int> &list, vector<int> &cur, vector<vector<int> > &out) {
        int n = nums.size();
        int prev = 0;
        int next = list[prev];
        if (next > n) {
            out.push_back(cur);
            return ;
        }

        while (next <= n) {
            cur.push_back(nums[next-1]);
            remove(list, prev, next);
            permute(nums, list, cur, out);
            restore(list, next);
            cur.pop_back();
            prev = next;
            next = list[next];
        }
   }
public:
    vector<vector<int> > permute(vector<int> &nums) {
        vector<int> cur;
        vector<vector<int> > out;
        vector<int> list(nums.size() + 1);
        iota(list.begin(), list.end(), 1);
        permute(nums, list, cur, out);
        return out;
    }
};

int main(void) {
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    {
        Solution sol;
        vector<int> nums { 1, 2, 3 };
        cout << "input: ";
        for (auto e : nums)
            cout << e << ' ';
        cout << '\n';
        const vector<vector<int> > &ans = sol.permute(nums);
        cout << "Total permutations: " << ans.size() << '\n';
        cout << "output: ";
        for (auto &v : ans) {
            for (auto e : v)
                cout << e << ' ';
            cout << '\n';
        }
    }
    return 0;
}