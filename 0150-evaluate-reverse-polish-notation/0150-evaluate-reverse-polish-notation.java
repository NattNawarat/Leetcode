class Solution {
    public int evalRPN(String[] tokens) {
        final Map<String, BinaryOperator<Integer>> op = Map.of(
            "+", (a, b) -> a + b,
            "-", (a, b) -> a - b,
            "*", (a, b) -> a * b,
            "/", (a, b) -> a / b);
        Deque<Integer> numberStack = new ArrayDeque<>();
        for(String token : tokens){
            if(!op.containsKey(token)){
                numberStack.push(Integer.parseInt(token));
            } else {
                Integer b = numberStack.pop();
                Integer a = numberStack.pop();
                numberStack.push(op.get(token).apply(a, b));
            }
        }
        return numberStack.pop();
    }
}