class MinStack {
public:

    // BHAIII MAIN ELEMENTS STORE KRENGE
    stack<int> st;

    // BHAIII HAR STEP PE MINIMUM STORE KRENGE
    stack<int> minSt;

    MinStack() {

    }
    
    void push(int value) {

        // Main stack me value push
        st.push(value);

        // Agar pehla element hai ya naya minimum mil gaya
        if(minSt.empty() || value <= minSt.top())
            minSt.push(value);

        // Nahi to purana minimum hi copy krdo
        else
            minSt.push(minSt.top());
    }
    
    void pop() {

        // Dono stack se ek saath pop
        st.pop();
        minSt.pop();
    }
    
    int top() {

        return st.top();
    }
    
    int getMin() {

        // Current minimum hamesha top pe hoga
        return minSt.top();
    }
};