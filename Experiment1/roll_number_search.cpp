#include <iostream>
using namespace std;

class RollSearch
{
public:
    int binarySearch(int a[], int n, int key)
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (a[mid] == key)
                return mid;

            if (a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

int main()
{
    RollSearch r;
    int n, key;
    int roll[50];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter roll numbers in sorted order: ";

    for (int i = 0; i < n; i++)
        cin >> roll[i];

    cout << "Enter roll number to search: ";
    cin >> key;

    int result = r.binarySearch(roll, n, key);

    if (result != -1)
        cout << "Roll number found at position " << result + 1 << endl;
    else
        cout << "Roll number not found" << endl;

    return 0;
}