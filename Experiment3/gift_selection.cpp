#include <iostream>
using namespace std;

class GiftSelection
{
public:
    void knapsack(int weight[], int value[], int n, int capacity)
    {
        double ratio[50];

        for (int i = 0; i < n; i++)
            ratio[i] = (double)value[i] / weight[i];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(value[i], value[j]);
                }
            }
        }

        double totalValue = 0;

        for (int i = 0; i < n; i++)
        {
            if (capacity >= weight[i])
            {
                capacity -= weight[i];
                totalValue += value[i];
            }
            else
            {
                totalValue += ratio[i] * capacity;
                break;
            }
        }

        cout << "Maximum gift value = " << totalValue << endl;
    }
};

int main()
{
    GiftSelection g;

    int n, capacity;
    int weight[50], value[50];

    cout << "Enter number of gifts: ";
    cin >> n;

    cout << "Enter weights of gifts: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values of gifts: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter bag capacity: ";
    cin >> capacity;

    g.knapsack(weight, value, n, capacity);

    return 0;
}