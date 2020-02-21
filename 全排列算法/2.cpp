class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void dfs(const vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(nums, pos + 1);
                used[i] = false;
                path.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return ans;
        }
        used.resize(nums.size());
        dfs(nums, 0);
        return ans;
    }
};
