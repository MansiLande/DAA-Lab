#include <iostream>
using namespace std;

class StudentMarks
{
public:
    void quickSort(int a[], int low, int high)
    {
        if (low < high)
        {
            int i = low;
            int j = high;
            int pivot = a[(low + high) / 2];

            while (i <= j)
            {
                while (a[i] < pivot)
                    i++;

                while (a[j] > pivot)
                    j--;

                if (i <= j)
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    i++;
                    j--;
                }
            }

            if (low < j)
                quickSort(a, low, j);

            if (i < high)
                quickSort(a, i, high);
        }
    }

    void merge(int a[], int low, int mid, int high)
    {
        int temp[50];
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high)
        {
            if (a[i] < a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }

        while (i <= mid)
            temp[k++] = a[i++];

        while (j <= high)
            temp[k++] = a[j++];

        for (i = low; i <= high; i++)
            a[i] = temp[i];
    }

    void mergeSort(int a[], int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;

            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);
            merge(a, low, mid, high);
        }
    }

    void display(int a[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main()
{
    StudentMarks s;
    int n, marks[50], quick[50], merge[50];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student marks: ";

    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
        quick[i] = marks[i];
        merge[i] = marks[i];
    }

    s.quickSort(quick, 0, n - 1);
    s.mergeSort(merge, 0, n - 1);

    cout << "\nMarks sorted using Quick Sort: ";
    s.display(quick, n);

    cout << "Marks sorted using Merge Sort: ";
    s.display(merge, n);

    return 0;
}