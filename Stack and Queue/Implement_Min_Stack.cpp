#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:
    MinStack() = default;

    void push(int val)
    {
        int currentMin = st.empty() ? val : min(val, st.top().second);
        st.emplace(val, currentMin);
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};
