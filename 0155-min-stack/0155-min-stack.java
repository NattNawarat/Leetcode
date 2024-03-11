class MinStack {
        class Node {
            private int val;
            private int min;

            Node(int val,int min){
                this.val = val;
                this.min = min;
            }

            public int getVal() {
                return val;
            }

            public int getMin() {
                return min;
            }
        }
        private Stack<Node> stack;
        public MinStack() {
            this.stack = new Stack<>();
        }

        public void push(int val) {
            if(this.stack.isEmpty()){
                stack.push(new Node(val,val));
            } else {
                stack.push(new Node(val,Math.min(val,stack.peek().getMin())));
            }
        }

        public void pop() {
            stack.pop();
        }

        public int top() {
            return stack.peek().getVal();
        }

        public int getMin() {
            return stack.peek().getMin();
        }
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */