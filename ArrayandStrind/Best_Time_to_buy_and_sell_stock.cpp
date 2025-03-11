#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
int BestSell(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    int minprice = INT16_MAX;
    int maxprofit = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Checking price[" << i << "] = " << prices[i] << endl;
        if (prices[i] < minprice)
        {
            minprice = prices[i];
            cout << "Updated minprice: " << minprice << endl;
        }
        int profit = prices[i] - minprice;
        cout << "Profit at day " << i << " = " << profit << endl;

        if (profit > maxprofit)
        {
            maxprofit = profit;
            cout << "Updated maxprofit: " << maxprofit << endl;
        }
    }
    return maxprofit;
}

};
int main()
{
    cout << "program started...." << endl; // Ensure immediate output
    vector<int> price = {7, 2, 1, 5, 6, 3};
    solution sol;

    int maxprofit = sol.BestSell(price);
    cout << "Max Profit: " << maxprofit << endl;  // Ensure output is printed
    return 0;
}

