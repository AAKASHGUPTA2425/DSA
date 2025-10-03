#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int Celebrity(vector<vector<int>> &mat, int n, int m)
    {
        int top = 0;
        int down = n - 1;

        // Step 1: Find a candidate
        while (top < down)
        {
            if (mat[top][down] == 1) // top knows down → top can't be celebrity
                top++;
            else if (mat[down][top] == 1) // down knows top → down can't be celebrity
                down--;
            else
            {
                top++;
                down--;
            }
        }

        if (top > down)
            return -1;

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++)
        {
            if (i == top) continue;
            // Celebrity condition:
            // - Celebrity does NOT know anyone → mat[top][i] == 0
            // - Everyone knows celebrity → mat[i][top] == 1
            if (!(mat[top][i] == 0 && mat[i][top] == 1))
            {
                return -1;
            }
        }
        return top;
    }
};

int main()
{
    Solution sol;

    // Example matrix (party of 3 people)
    // mat[i][j] = 1 if i knows j, else 0
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}};

    int n = mat.size();
    int m = mat[0].size();

    int celeb = sol.Celebrity(mat, n, m);

    if (celeb == -1)
        cout << "No celebrity found." << endl;
    else
        cout << "Celebrity is person index: " << celeb << endl;

    return 0;
}
