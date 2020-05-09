/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
*/
#include <iostream>
#include<queue>
using namespace std;
bool printdfs(int** edges , int n ,int * visited , int a , int b ){
    if(edges[a][b]==1)
        return true;
    
    visited[a]=1;
    int i;
    for( i =0 ; i < n ; i++){
        if(i==a)
            continue;
        if(edges[a][i]==1){
          if(visited[i]==1)
              continue;
          return  printdfs(edges,n,visited,i,b);   
        }
    }
    return false;

}

// bool printbfs(int** edges , int n ,int * visited , int a,int b){
//     queue<int> aa;
//     aa.push(a);
//     visited[a]=1;
//     while(aa.size()!=0){
//         int curvertex = aa.front();
//         aa.pop();
//         if(curvertex==b){
//             return true;
//             break;}
//         for(int i =0 ; i < n ; i++){
//             if(i==curvertex)
//                 continue;
//             if(edges[curvertex][i]==1&&visited[i]==0){
//             aa.push(i);
//             visited[i]=1;
//             }
//         }
//     }
//     return false;
// }

int main(){
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
    int a,b;
    cin>>a>>b;
    int * visited = new int[n]();
    
    if(printdfs(edges,n,visited,a,b))
        cout<<"true";
    else
        cout<<"false";
    
    delete []visited;
    
    for(int i = 0 ; i < n ; i++){
        delete []edges[i];
    }
    delete []edges;

 
  return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int flag=0;
// void print(int **matrix,int v,int st,int end,bool *visited)
// {
// 	bool chek;
// 	//cout<<st<<endl;
// 	visited[st]=true;
// 	if(st==end)
//     {
//         flag=1;
// 	    return;
//     }
// 	for(int i=0;i<v;i++)
// 	{
 
// 		if(i==st)
// 		continue;
// 		if(matrix[st][i]==1)
// 		{
// 			if(visited[i])
// 	     	continue;
 
// 	     	print(matrix,v,i,end,visited);
// 		}
// 	}
 
// }
 
// int main()
// {
 
//   int v,e;
//   cin>>v>>e;
 
//  int **matrix=new int*[v];
 
// for(int i=0;i<v;i++)
// {
// 	matrix[i]=new int[v];
 
// 	for(int j=0;j<v;j++)
// 	{
 
// 		matrix[i][j]=0;
 
// 	}
 
// 	}	
// while(e--)
// {
 
// 	int st,end;
// 	cin>>st>>end;
// 	matrix[st][end]=1;
// 	matrix[end][st]=1;
// 	}	
 
// 	bool *visited=new bool[v];
// 	for(int i=0;i<v;i++)
// 	visited[i]=false;
//     int st,end;
//     cin>>st>>end;
// 	print(matrix,v,st,end,visited);
// 	if(flag==1)
// 	cout<<"true";
// 	else
// 	cout<<"false";   //send matrix total vertices and starting edges
 
 
// 	return 0;
// }
