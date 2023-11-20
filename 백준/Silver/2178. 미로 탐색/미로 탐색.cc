#include <cstdio>
#include <queue>
using namespace std;

#define MAX_SIZE 100

struct Point{
    int row;
    int col;    
};

int bfs(int maze[MAX_SIZE][MAX_SIZE], int N, int M){
    queue<Point> q;
    q.push({0, 0});
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    while (!q.empty()){
        Point current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int newRow = current.row + dx[i];
            int newCol = current.col + dy[i];
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && maze[newRow][newCol] == 1){
                maze[newRow][newCol] = maze[current.row][current.col] + 1;
                q.push({newRow, newCol});
            }
        }
    }
    return maze[N-1][M-1];
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int maze[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }
    int result = bfs(maze, N, M);
    printf("%d\n", result);
    return 0;
}