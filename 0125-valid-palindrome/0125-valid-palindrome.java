class Solution {
    public boolean isPalindrome(String s) {
        int leftIndex = 0;
        int rightIndex = s.length()-1;
        while (leftIndex < rightIndex){
            char leftChar = s.charAt(leftIndex);
            char rightChar = s.charAt(rightIndex);

            boolean b = !Character.isAlphabetic(leftChar) && !Character.isDigit(leftChar);
            boolean b1 = !Character.isAlphabetic(rightChar) && !Character.isDigit(rightChar);
            if(b || b1){
                if(b){
                    leftIndex++;
                }
                if (b1){
                    rightIndex--;
                }
                //System.out.println(leftIndex+" "+rightIndex);
                continue;
            }
            if(Character.toLowerCase(rightChar) != Character.toLowerCase(leftChar)){
                return false;
            }
            leftIndex ++;
            rightIndex --;
        }
        return true;
    }
}