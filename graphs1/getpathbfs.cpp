/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;
void print(int ** edges , int n , int *visited , int a , int b){
    map<int , int> m;
    queue<int> aa;
    aa.push(a);
    visited[a]=1;
    while(aa.size()!=0){
        int curvertex = aa.front();
        aa.pop();
        if(curvertex==b){
            cout<<b<<" ";
            for(int i = b ; i!=a ; ){
                cout<<m[i]<<" ";
                i=m[i];
            }
            return ;}
        for(int i =0 ; i < n ; i++){
            if(i==curvertex)
                continue;
            if(edges[curvertex][i]==1&&visited[i]==0){
            m[i]=curvertex;
            aa.push(i);
            visited[i]=1;
            }
        }
    } 
    
    
}


int main()
{
  
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
    
    print(edges,n,visited,a,b);
  
    
    delete []visited;
    for(int i = 0 ; i < n ; i++){
        delete []edges[i];
    }
    delete []edges;

  return 0;
}
