class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,i,j,ans = nums.at(0);
        for(i = 0; i < nums.size(); i++)
        {
            sum += nums.at(i);
            ans = max(sum,ans);
            sum = max(sum,0);
        }
        return ans;
    }
};
