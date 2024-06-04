#include <stdio.h>
#include <stdbool.h>

#define N 100002

bool vis[N];
int adj[N][N];

int main(){
    for(int i=0; i<N; i++){
        vis[i]=false;
    }

    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    int x,y;
    for(int i=0; i<edges; i++){
        scanf("%d %d", &x, &y);

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    int q[N], front = 0, rear = -1;
    q[++rear] = 1;
    vis[1] = true;

    while(front <= rear){
        int node = q[front++];

        printf("%d\n", node);

        for(int i = 1; i <= nodes; i++){
            if(adj[node][i] && !vis[i]){
                vis[i] = true;
                q[++rear] = i;
            }
        }
    }

    return 0;
}
