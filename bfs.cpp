#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF=1e9;
int path_finder(string maze) {
    char charToRemove='\n';
    maze.erase(remove(maze.begin(), maze.end(), charToRemove), maze.end());
    int sz = sqrt(maze.size());
    vector<vector<char>> graph(sz);
    for(int i=0;i<sz;i++){
        graph[i].resize(sz);
    }
    for(int i=0,q=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            graph[i][j]=maze[q];
            q++;
        }
    }
    for(int i=0,q=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            cout<<graph[i][j]<<"   ";
        }
        cout<<'\n';
    }
    vector<vector<int>> dist(graph.size(),vector<int>(graph.size(),INF));
    queue<pair<int,int>> q;
    dist[0][0]=0;
     q.push({0, 0}); // Using std::make_pair to create a pair

    static vector<int> dy={-1,0,1,0};
    static vector<int> dx={0,1,0,-1};
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(int i=0;i<dy.size();i++){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(0<=ty && ty<graph.size() && tx>=0 && tx<graph[0].size()
            && graph[ty][tx]=='.' && dist[ty][tx]>dist[x][y]+1){
                dist[ty][tx]=dist[x][y]+1;
                q.push({ty,tx});
            }
        }
    }
    if(dist[graph.size()-1][graph.size()-1]!=INF){
        return dist[graph.size()-1][graph.size()-1];
    }
  return -1;
}
int main(){
    std::string maze="......\n......\n......\n......\n.....W\n....W.";
    
    cout<<path_finder(maze);

}