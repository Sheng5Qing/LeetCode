//43.接雨水
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            }else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

struct Example {
    vector<int> height;
    int ans;
};

int main(){
    vector<Example> examples = {
        {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
        {{4,2,0,3,2,5}, 9}
    };
    Solution* solve = new Solution();
    for (Example example: examples) {
        cout << solve->trap(example.height) << endl;
    }

    return 0;
}