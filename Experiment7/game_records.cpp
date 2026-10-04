#include <iostream>
using namespace std;

class OptimalBST
{
public:
    void findOptimalBST(int keys[], int freq[], int n)
    {
        int cost[20][20];

        for (int i = 0; i < n; i++)
            cost[i][i] = freq[i];

        for (int length = 2; length <= n; length++)
        {
            for (int i = 0; i <= n - length; i++)
            {
                int j = i + length - 1;
                cost[i][j] = 9999;

                int sum = 0;

                for (int k = i; k <= j; k++)
                    sum += freq[k];

                for (int r = i; r <= j; r++)
                {
                    int left = (r > i) ? cost[i][r - 1] : 0;
                    int right = (r < j) ? cost[r + 1][j] : 0;

                    int total = left + right + sum;

                    if (total < cost[i][j])
                        cost[i][j] = total;
                }
            }
        }

        cout << "Minimum cost of Optimal BST = "
             << cost[0][n - 1] << endl;
    }
};

int main()
{
    OptimalBST o;

    int n;
    int keys[20], freq[20];

    cout << "Enter number of games: ";
    cin >> n;

    cout << "Enter game IDs: ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    cout << "Enter search frequencies: ";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    o.findOptimalBST(keys, freq, n);

    return 0;
}