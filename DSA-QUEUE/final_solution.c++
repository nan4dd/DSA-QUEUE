#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int downToZero(int n) {
    if (n == 0) return 0;

    vector<int> visited(n + 1, INT_MAX);
    visited[n] = 0;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == 0) return visited[0];

        // Operasi 1 : kurangi 1
        if (visited[current - 1] > visited[current] + 1) {
            visited[current - 1] = visited[current] + 1;
            q.push(current - 1);
        }

        // Operasi 2 : faktor
        for (int i = 2; i * i <= current; ++i) {
            if (current % i == 0) {
                int next = max(i, current / i);
                if (visited[next] > visited[current] + 1) {
                    visited[next] = visited[current] + 1;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}

int main() {
    int q;
    cout << "Input:";
    cin >> q;

    vector<int> inputs(q);
    for (int i = 0; i < q; ++i) {
        cin >> inputs[i];
    }
    cout << endl; 
    cout << "Output:\n";
    for (int i = 0; i < q; ++i) {
        cout << downToZero(inputs[i]) << endl;
    }

    return 0;
}