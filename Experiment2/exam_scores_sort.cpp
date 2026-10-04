#include <iostream>
using namespace std;

class ExamScores
{
public:
    void quickSort(int a[], int low, int high)
    {
        if (low < high)
        {
            int i = low, j = high;
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
    ExamScores e;
    int n, scores[50], quick[50], merge[50];

    cout << "Enter number of exams: ";
    cin >> n;

    cout << "Enter exam scores: ";

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        quick[i] = scores[i];
        merge[i] = scores[i];
    }

    e.quickSort(quick, 0, n - 1);
    e.mergeSort(merge, 0, n - 1);

    cout << "\nScores sorted using Quick Sort: ";
    e.display(quick, n);

    cout << "Scores sorted using Merge Sort: ";
    e.display(merge, n);

    return 0;
}