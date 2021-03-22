class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        if(len<=1){
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        char[] charArray = s.toCharArray();
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(j-i+1>maxLen&&judgePalindrome(charArray,i,j)){
                    maxLen = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substring(begin, begin+maxLen);
    }
    private boolean judgePalindrome(char[] charArray,int i,int j){
        while(i<j){
            if(charArray[i]!=charArray[j]){
                return false;
            }
            else{
                i++;
                j--;

            }
        }
        return true;

    }
}