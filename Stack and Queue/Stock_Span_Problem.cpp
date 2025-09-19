#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() = default;

    int next(int price)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.emplace(price, span);
        return span;
    }
};
