#include <iostream>
using namespace std;

class HospitalRoute
{
public:
    void dijkstra(int graph[10][10], int n, int source)
    {
        int distance[10];
        bool visited[10];

        for (int i = 0; i < n; i++)
        {
            distance[i] = 9999;
            visited[i] = false;
        }

        distance[source] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int min = 9999;
            int u = -1;

            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && distance[i] < min)
                {
                    min = distance[i];
                    u = i;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && graph[u][v] &&
                    distance[u] + graph[u][v] < distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        cout << "\nShortest distances from Hospital:\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Location " << i + 1 << " = "
                 << distance[i] << endl;
        }
    }
};

int main()
{
    HospitalRoute h;
    int n, graph[10][10];

    cout << "Enter number of locations: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    h.dijkstra(graph, n, 0);

    return 0;
}