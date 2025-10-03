#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack_spanner {
public:
    stack<pair<int,int>> st;
    int ind;

    // Constructor
    Stack_spanner() {
        ind = -1;
        while (!st.empty()) st.pop();
    }

    int next(int val) {
        ind++;
        // Pop smaller or equal prices
        while (!st.empty() && st.top().first <= val) {
            st.pop();
        }
        // Span = current index - index of previous greater element
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({val, ind});
        return ans;
    }
};

int main() {
    Stack_spanner spanner;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << "Price: " << price 
             << " -> Span: " << spanner.next(price) << endl;
    }
    return 0;
}
