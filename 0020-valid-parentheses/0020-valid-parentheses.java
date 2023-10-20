class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        List<Character> closedParenthesis = List.of(')',']','}');
        for(int i = 0 ; i < s.length() ;i++){
            char currentBracket = s.charAt(i);
            if(closedParenthesis.contains(currentBracket)) {
                if (stack.empty()) {
                    return false;
                }
                char open = (char) stack.pop();
                if (!isMatch(open, currentBracket)) {
                    return false;
                }
            } else {
                stack.push(currentBracket);
            }
        }
        if(stack.empty()){
            return true;
        } else {
            return false;
        }
    }
    private boolean isMatch(char open,char close){
        if(open == '(' && close == ')'){
            return true;
        } else if(open == '{' && close == '}'){
            return true;
        } else if(open == '[' && close == ']'){
            return true;
        }
        return false;
    }
}