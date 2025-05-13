int downToZero(int n) {
    vector<int> visited(n + 1, 0); // menyimpan langkah ke node tersebut
    queue<int> q;

    q.push(n);
    visited[n] = 1; // bukan langkah ke-1, tapi penanda bahwa telah dikunjungi

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == 0)
            return visited[curr] - 1; // dikurangi 1 karena visited[n] dimulai dari 1

        // Operasi 1: kurangi 1
        if (visited[curr - 1] == 0) {
            visited[curr - 1] = visited[curr] + 1;
            q.push(curr - 1);
        }

        // Operasi 2: cari pembagi
        for (int i = 2; i * i <= curr; ++i) {
            if (curr % i == 0) {
                int next = max(i, curr / i);
                if (visited[next] == 0) {
                    visited[next] = visited[curr] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1; // fallback
}