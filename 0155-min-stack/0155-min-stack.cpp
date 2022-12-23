class MinStack {
public:
    stack<pair<int,int>> minStack;
    int minVal;
    MinStack() {
    }
    
    void push(int val) {
        pair<int,int> node,topNode;
        
        if(!minStack.empty()){
            topNode = minStack.top();
            //cout << "has_min" << " ";
            minVal = min(val,topNode.second);
        } else {
            minVal = val;
        } 
        //cout <<"push "<< val << " " << minVal << endl;
        node.first = val;
        node.second = minVal;
        minStack.push(node);
    }
    
    void pop() {
        pair<int,int> topNode;
        topNode = minStack.top();
        //cout<<"pop "<<topNode.first << " "<< topNode.second<<endl;
        minStack.pop();
    }
    
    int top() {
        pair<int,int> topNode;
        topNode = minStack.top();
        //cout<<"top "<<topNode.first << " "<< topNode.second<<endl;
        return topNode.first;
    }
    
    int getMin() {
        pair<int,int> topNode;
        topNode = minStack.top();
        //cout<<"get_min "<<topNode.first << " "<< topNode.second<<endl;
        return topNode.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */