/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
*/
#include <iostream>
#include<queue>
using namespace std;
void printbfs(int** edges , int n ,int * visited , int sv){
    queue<int> a;
    a.push(sv);
    visited[sv]=1;
    while(a.size()!=0){
        int curvertex = a.front();
        cout<<curvertex<<" ";
        a.pop();
        for(int i =0 ; i < n ; i++){
            if(i==curvertex)
                continue;
            if(edges[curvertex][i]==1&&visited[i]==0){
            a.push(i);
            visited[i]=1;
            }
        }
    }
}

void print(int** edges , int n){
    int * visited = new int[n]();
    for(int i =0 ; i < n ; i++){
        if(visited[i]==0){
            printbfs(edges,n,visited,i);
        }
    }
    delete []visited;
}

int main() {
    int n, e;
    cin >> n >> e;
    int ** edges = new int*[n];
    for(int i =0 ; i< n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0 ; i < e ; i++){
        int fv , sv;
        cin>>fv>>sv;
        edges[fv][sv] = 1;
        edges[sv][fv]=1 ;
    }
    
    print(edges,n);
    
    for(int i = 0 ; i < n ; i++){
        delete []edges[i];
    }
    delete []edges;

  

  return 0;
}
