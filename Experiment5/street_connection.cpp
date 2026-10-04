#include <iostream>
using namespace std;

class StreetNetwork
{
public:
    void prim(int graph[10][10], int n)
    {
        int selected[10] = {0};
        selected[0] = 1;

        int edges = 0;
        int total = 0;

        cout << "\nPrim's MST:\n";

        while (edges < n - 1)
        {
            int min = 9999;
            int x = 0, y = 0;

            for (int i = 0; i < n; i++)
            {
                if (selected[i])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (!selected[j] && graph[i][j] &&
                            graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            cout << "Street " << x + 1 << " - Street "
                 << y + 1 << " : " << min << endl;

            total += min;
            selected[y] = 1;
            edges++;
        }

        cout << "Total cost = " << total << endl;
    }

    int findParent(int parent[], int i)
    {
        while (parent[i] != i)
            i = parent[i];

        return i;
    }

    void kruskal(int graph[10][10], int n)
    {
        int parent[10];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int edges = 0;
        int total = 0;

        cout << "\nKruskal's MST:\n";

        while (edges < n - 1)
        {
            int min = 9999;
            int x = -1, y = -1;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (graph[i][j] && graph[i][j] < min)
                    {
                        int p1 = findParent(parent, i);
                        int p2 = findParent(parent, j);

                        if (p1 != p2)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            int p1 = findParent(parent, x);
            int p2 = findParent(parent, y);

            parent[p2] = p1;

            cout << "Street " << x + 1 << " - Street "
                 << y + 1 << " : " << min << endl;

            total += min;
            edges++;
        }

        cout << "Total cost = " << total << endl;
    }
};

int main()
{
    StreetNetwork s;
    int n, graph[10][10];

    cout << "Enter number of streets: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    s.prim(graph, n);
    s.kruskal(graph, n);

    return 0;
}