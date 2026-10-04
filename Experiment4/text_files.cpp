#include <iostream>
using namespace std;

class TextFileMerge
{
public:
    void mergeFiles(int files[], int n)
    {
        int totalCost = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int min1 = 0, min2 = 1;

            if (files[min2] < files[min1])
                swap(min1, min2);

            for (int j = 2; j < n - i; j++)
            {
                if (files[j] < files[min1])
                {
                    min2 = min1;
                    min1 = j;
                }
                else if (files[j] < files[min2])
                {
                    min2 = j;
                }
            }

            int cost = files[min1] + files[min2];
            totalCost += cost;

            files[min1] = cost;
            files[min2] = files[n - i - 1];
        }

        cout << "Minimum merge cost = " << totalCost << endl;
    }
};

int main()
{
    TextFileMerge t;
    int n, files[50];

    cout << "Enter number of text files: ";
    cin >> n;

    cout << "Enter file sizes: ";

    for (int i = 0; i < n; i++)
        cin >> files[i];

    t.mergeFiles(files, n);

    return 0;
}