/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
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
*/
                                  ///my code 
// #include <iostream>
// using namespace std;
// bool print(int **edges , int n , int *visited , int a , int b ){
  
//     if(a==b)
//     {
//         visited[a]=1;
//         return true;
//     }
//     visited[a]=1;
//     for(int i =0 ; i < n ; i++){
//          if(a==i)
//             continue;
        
//         if(edges[a][i]==1&&visited[i]!=1){
//             if(print(edges,n,visited,i,b)){
//             cout<<i<<" ";
//             return true;
//             }
//         }
        
//     }
//     return false;
    
// }
// int main()
// {
  
//     int n, e;
//     cin >> n >> e;
//     int ** edges = new int*[n];
//     for(int i =0 ; i< n ; i++){
//         edges[i] = new int[n];
//         for(int j = 0 ; j < n ; j++){
//             edges[i][j] = 0;
//         }
//     }
//     for(int i = 0 ; i < e ; i++){
//         int fv , sv;
//         cin>>fv>>sv;
//         edges[fv][sv] = 1;
//         edges[sv][fv]= 1 ;
//     }
//     int a,b;
//     cin>>a>>b;
    
//     int * visited = new int[n]();
    
//     bool ata = print(edges,n,visited,a,b);
//     if(ata)
//         cout<<a<<" ";
  
    
//     delete []visited;
//     for(int i = 0 ; i < n ; i++){
//         delete []edges[i];
//     }
//     delete []edges;

  

//   return 0;
// }

                                                 //new code
// #include <iostream>
// using namespace std;
// bool dfs (int**edge,bool *visited,int si,int ei,int v)
// {      if(si==ei)
        
//     {
//         visited[si]=true;
        
//         return true;
//     }
//     visited[si]=true;
//     for(int i=0;i<v;i++)
//     {
//         if(i==si)
//         {continue;
//         }
//         if(edge[si][i]==1 )
//         { if(visited[i])
//             continue;
//             if(dfs(edge,visited,i,ei,v))
//             { cout<<i<<" ";
//                  return true;
//             }
        
//         }
//     }
//     return false;
    
// }

// int main()
// {
//   int v, e, tempX, tempY;
//   cin >> v >> e;
//     int **edge=new int*[v];
//     for(int i=0;i<v;i++)
//         edge[i]=new int[v];
//    for(int i=0;i<v;i++)
//    {
//     for(int j=0;j<v;j++)
//         edge[i][j]=0;
//    }
 
//      for(int j=0;j<e;j++)
//      {
//          int x,y;
//          cin>>x>>y;
//          edge[x][y]=1;
//          edge[y][x]=1;
//      }
     
 
//     cin>>tempX>>tempY;
    
//     bool *visited=new bool[v];
//     for(int i=0;i<v;i++)
//     {
//         visited[i]=false;
    
//     }
//     if(dfs(edge,visited,tempX,tempY,v))
//         cout<<tempX;
//   /*

//   	   Write Your Code Here
// 	   Complete the Rest of the Program
// 	   You have to Print the output yourself
	 
//   */

//   return 0;
// }

                                ///using vector approach
#include <bits/stdc++.h>
using namespace std;

vector<int>* getPath(int **input,int v,bool *visit,int sv,int ev)
{
    
    if(sv==ev)
    {
        
        vector<int> *output=new vector<int>();
        output->push_back(sv);
        return output;
        
    }
    visit[sv]=true;
    for(int i=0;i<v;i++)
    {
        
        
        if(input[sv][i] && !visit[i])
        {
            
            
            vector<int>*smallinput=getPath(input,v,visit,i,ev);
            if(smallinput!=NULL)
            {
                
                smallinput->push_back(sv);
                return smallinput;
            }
        }
        
        
    }
    
    
    
    
    
    return NULL;
}



int main() 
{
    int V, E;
    cin >> V >> E;
    
    int **matrix=new int*[V];
    
    for(int i=0;i<V;i++)
    {
        matrix[i]=new int[V];
        
        for(int j=0;j<V;j++)
            matrix[i][j]=0;
        
    }
    
    while(E--)
    {
        int st,end;
        cin>>st>>end;
        matrix[st][end]=1;
        matrix[end][st]=1;
        
    }
    int st,end;
    cin>>st>>end;
    bool *visit=new bool[V];
    
    for(int i=0;i<V;i++)
        visit[i]=false;
    vector<int>* output=getPath(matrix,V,visit,st,end);
    
    if(output!=NULL)
    {
      for(int i=0;i<output->size();i++)
        cout<<output->at(i)<<" ";  
    }
    

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}
