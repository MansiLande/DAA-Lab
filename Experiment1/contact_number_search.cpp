#include <iostream>
using namespace std;

class ContactSearch
{
public:
    int binarySearch(long long contacts[], int n, long long key)
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (contacts[mid] == key)
                return mid;

            if (contacts[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

int main()
{
    ContactSearch c;
    int n;
    long long key;
    long long contacts[50];

    cout << "Enter number of contacts: ";
    cin >> n;

    cout << "Enter contact numbers in sorted order: ";

    for (int i = 0; i < n; i++)
        cin >> contacts[i];

    cout << "Enter contact number to search: ";
    cin >> key;

    int result = c.binarySearch(contacts, n, key);

    if (result != -1)
        cout << "Contact number found at position " << result + 1 << endl;
    else
        cout << "Contact number not found" << endl;

    return 0;
}