/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
*/
#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
void printbfs(int** edges , int n ,int * visited , int sv , vector<int> v){
    queue<int> a;
    a.push(sv);
    visited[sv]=1;
    while(a.size()!=0){
        int curvertex = a.front();
        //cout<<curvertex<<" ";
        v.push_back(curvertex);
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
    sort(v.begin(),v.end());  
     for(int i = 0 ; i < v.size() ; i++){
                cout<<v[i]<<" ";
     } 
    // cout<<sv<<" ";
    // visited[sv]=1;
    // for(int i = 0 ; i < n ; i++){
    //     if(sv==i)
    //         continue;
    //     if(edges[sv][i]==1&&visited[i]!=1)
    //     printbfs(edges,n,visited,i);
    // }
}

void print(int** edges , int n){
    int * visited = new int[n]();
    for(int i =0 ; i < n ; i++){
        if(visited[i]==0){
            vector<int> v;
            printbfs(edges,n,visited,i,v);        
            cout<<endl;
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
