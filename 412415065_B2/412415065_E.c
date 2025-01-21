#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 1000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pt;
    int dist;
} Node;

int n, m;
int g[MAXN][MAXN];
Point si, se;
Point monsters[MAXN * MAXN];
int monster_count = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};
char path[MAXN * MAXN];
Point par_mp[MAXN][MAXN];

bool isValid(int x, int y, int timer) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    if (g[x][y] <= timer) {
        return false;
    }
    return true;
}

bool isEscape(int x, int y, int timer) {
    if (!isValid(x, y, timer)) {
        return false;
    }
    if (x == 0 || y == 0 || x == n-1 || y == m-1) {
        return true;
    }
    return false;
}

bool bfs_escape() {
    Node queue[MAXN * MAXN];
    int front = 0, rear = 0;
    queue[rear++] = (Node){si, 0};
    par_mp[si.x][si.y] = (Point){-1, -1};
    while (front < rear) {
        int cx = queue[front].pt.x;
        int cy = queue[front].pt.y;
        int timer = queue[front++].dist;
        timer++;
        for (int i = 0; i < 4; ++i) {
            int tx = cx + dx[i];
            int ty = cy + dy[i];
            if (isEscape(tx, ty, timer)) {
                par_mp[tx][ty] = (Point){cx, cy};
                se = (Point){tx, ty};
                return true;
            }
            if (isValid(tx, ty, timer)) {
                par_mp[tx][ty] = (Point){cx, cy};
                g[tx][ty] = timer;
                queue[rear++] = (Node){{tx, ty}, timer};
            }
        }
    }
    return false;
}

void preprocess_lava_flow() {
    Node queue[MAXN * MAXN];
    int front = 0, rear = 0;
    for (int i = 0; i < monster_count; ++i) {
        queue[rear++] = (Node){monsters[i], 0};
    }
    while (front < rear) {
        int cx = queue[front].pt.x;
        int cy = queue[front].pt.y;
        int timer = queue[front++].dist;
        timer++;
        for (int i = 0; i < 4; ++i) {
            int tx = cx + dx[i];
            int ty = cy + dy[i];
            if (isValid(tx, ty, timer)) {
                g[tx][ty] = timer;
                queue[rear++] = (Node){{tx, ty}, timer};
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c", &c);
            if (c == '#') {
                g[i][j] = 0;
            } else if (c == 'M') {
                g[i][j] = 0;
                monsters[monster_count++] = (Point){i, j};
            } else if (c == 'A') {
                g[i][j] = 0;
                si = (Point){i, j};
            } else {
                g[i][j] = INT_MAX;
            }
        }
    }

    if (si.x == 0 || si.y == 0 || si.x == n-1 || si.y == m-1) {
        printf("YES\n");
        printf("0\n");
        return 0;
    }

    preprocess_lava_flow();

    if (!bfs_escape()) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    Point tmp = se;
    Point tmp1 = par_mp[se.x][se.y];
    Point ed = {-1, -1};
    int len = 0;
    while (!(tmp1.x == ed.x && tmp1.y == ed.y)) {
        if ((tmp.y - tmp1.y) == 1 && (tmp.x - tmp1.x) == 0) {
            path[len++] = 'R';
        }
        if ((tmp.y - tmp1.y) == -1 && (tmp.x - tmp1.x) == 0) {
            path[len++] = 'L';
        }
        if ((tmp.y - tmp1.y) == 0 && (tmp.x - tmp1.x) == 1) {
            path[len++] = 'D';
        }
        if ((tmp.y - tmp1.y) == 0 && (tmp.x - tmp1.x) == -1) {
            path[len++] = 'U';
        }
        tmp = par_mp[tmp.x][tmp.y];
        tmp1 = par_mp[tmp.x][tmp.y];
    }

    printf("%d\n", len);
    for (int i = len - 1; i >= 0; --i) {
        putchar(path[i]);
    }
    putchar('\n');

    return 0;
}
