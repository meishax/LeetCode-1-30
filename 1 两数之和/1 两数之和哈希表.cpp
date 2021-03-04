class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashmap;
        int i;
        for(i=0;i<=nums.size()-1;i++)
        {
            if(hashmap.count(target-nums[i]))
            {
                return {hashmap[target-nums[i]],i};
                break;
            }
            hashmap[nums[i]]=i;
        }
        return {};

    }
};