#include <iostream>
using namespace std;

class BookSearch
{
public:
    int binarySearch(int books[], int n, int key)
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (books[mid] == key)
                return mid;

            if (books[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

int main()
{
    BookSearch b;
    int n, key;
    int books[50];

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book numbers in sorted order: ";

    for (int i = 0; i < n; i++)
        cin >> books[i];

    cout << "Enter book number to search: ";
    cin >> key;

    int result = b.binarySearch(books, n, key);

    if (result != -1)
        cout << "Book number found at position " << result + 1 << endl;
    else
        cout << "Book number not found" << endl;

    return 0;
}