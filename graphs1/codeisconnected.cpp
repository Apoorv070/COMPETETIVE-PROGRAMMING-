/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
*/
#include<iostream>
#include<queue>
using namespace std;
void print(int** edges , int n ,int * visited , int sv){
    queue<int> a;
    a.push(sv);
    visited[sv]=1;
    while(a.size()!=0){
        int curvertex = a.front();
        //cout<<curvertex<<" ";
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
        edges[sv][fv]= 1 ;
    }
    int a,b;
    cin>>a>>b;
    
    int * visited = new int[n]();
    
    print(edges,n,visited,0);
    int i ;
    for( i = 0 ; i < n ; i++){
        if(visited[i]!=1){
            cout<<"false";
            break;
        }
    }
    //cout<<i;
    if(i==n){
        cout<<"true";
    }
    
    delete []visited;
    for(int i = 0 ; i < n ; i++){
        delete []edges[i];
    }
    delete []edges;

  return 0;
}
