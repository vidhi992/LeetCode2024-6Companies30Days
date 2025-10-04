#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements (circular): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
