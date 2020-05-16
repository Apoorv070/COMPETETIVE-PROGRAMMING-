/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/
bool dfs(char cake[][MAXN],int i,int j,int n,int m,int** visited,string str,int index)
{
    if(index == 11)
    {
        return true;
    }
    // cout<<index<<endl;
    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] == 1 || cake[i][j] !=str[index])
    {
        return false;
    }
    bool smallAns = false ;
    visited[i][j] = 1;
    
    smallAns |= dfs (cake,i+1,j,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i-1,j,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i,j+1,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i,j-1,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i-1,j-1,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i-1,j+1,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i+1,j+1,n,m,visited,str,index+1);
    smallAns |= dfs (cake,i+1,j-1,n,m,visited,str,index+1);
    
    visited[i][j] = 0;
    return smallAns;
}

int solve(char Graph[][MAXN],int n, int m)
{
	// Write your code here.
    string str="CODINGNINJA";
    int** visited = new int*[n];
    
    for(int i=0;i<n;i++)
    {
        visited[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j] = 0;
        }
    }
    
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(Graph[i][j] == 'C' && visited[i][j]==0)
            {
                bool val = dfs(Graph,i,j,n,m,visited,str,0);
                if(val==true)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
