class Solution {
public:
    void Permute(vector<int> &nums,vector<vector<int>> &result,int len){
        if(len == nums.size()-1){
                for(int i = 0;i<nums.size();i++){
                    cout<<nums[i];
                }
                cout<<endl;
            result.push_back(nums);
            return;
        }
        for(int i = len; i<nums.size();i++){
            int temp = nums[len];
            nums[len] = nums[i];
            nums[i] = temp;
            Permute(nums,result,++len);
            --len;
            temp = nums[len];
            nums[len] = nums[i];
            nums[i] = temp;
        }
    }
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r1;
        if(nums.size()<= 0) return r1;
        Permute(nums,r1,0);
        return r1;
    }

};
