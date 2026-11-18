class MinStack {
private:
    stack<pair<int, int>> st; // {value, minimum so far}

public:
    MinStack() {}

    void push(int val) {
        int minimum = st.empty() ? val : min(val, st.top().second);
        st.push({val, minimum});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};