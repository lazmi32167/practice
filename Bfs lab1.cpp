#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100005

bool visited[MAX_NODES];
int adjacency[MAX_NODES][MAX_NODES];

void breadth_first_search(int start, int num_nodes) {
    int queue[MAX_NODES];
    int front = 0, rear = -1;
    queue[++rear] = start;
    visited[start] = true;

    while (front <= rear) {
        int node = queue[front++];
        printf("%d\n", node);

        for (int i = 1; i <= num_nodes; i++) {
            if (adjacency[node][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    int x, y;
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &x, &y);
        adjacency[x][y] = 1;
        adjacency[y][x] = 1;
    }

    breadth_first_search(1, num_nodes);

    return 0;
}
