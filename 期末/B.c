#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char g[1005][1005]; // 存地圖
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int vis[1005][1005]; // 紀錄已經走過

bool valid(int x, int y, int n, int m) { // 查看是否超出邊界
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    return true;
}
void dfs(int x, int y, int n, int m) {
    if (!valid(x, y, n, m)) return;
    if (g[x][y] != '#') return;
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], m, m);
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &g[i][j]);
            vis[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] == '#') {
                ans++;
                dfs(i, j, n, m);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

//1.本題是經典的孤島問題，可以用 DFS 或 BFS 兩種方法求解，只要一個點沒走過且可走，就對那個點做 DFS/BFS (line36)。
//2.DFS 可以用遞迴解決，BFS 則需要刻一個 queue。