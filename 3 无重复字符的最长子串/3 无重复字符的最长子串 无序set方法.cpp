class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lls;
        int maxlen = 0;
        int left = 0;
        for(int i=0;i<s.size();i++)
        {
            //.find若查询无结果，返回.endend
            while(lls.find(s[i])!=lls.end())//代表目前无重复char
            {
                lls.erase(s[left++]);

            }
            maxlen=max(maxlen,i-left+1);
            lls.insert(s[i]);
            

        }
        return maxlen;

    }
};