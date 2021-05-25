stack<int> st;
stack<int> minst;

MinStack::MinStack() {
    st.clear();
    minst.clear();
}

void MinStack::push(int x) {
    st.push(x);
    if(minst.empty()){
        minst.push(x);
        return;
    }
    if(x<minst.top()){
        minst.push(x);
    }else{
        minst.push(minst.top());
    }
    return;
}

void MinStack::pop() {
    if(!st.empty()){
        st.pop();
        minst.pop();
    }
    return;
}

int MinStack::top() {
    if(!st.empty()){
        return st.top();
    }
    return -1;
}

int MinStack::getMin() {
    if(!minst.empty()){
        return minst.top();
    }
    return -1;
}

