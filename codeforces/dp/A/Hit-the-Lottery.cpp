/*Hit the Lottery
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Allen has a LOT of money. He has n dollars in the bank. For security reasons, he wants to withdraw it in cash (we will not disclose the reasons here). The denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number of bills Allen could receive after withdrawing his entire balance?

Input
The first and only line of input contains a single integer n (1≤n≤109).

Output
Output the minimum number of bills that Allen could receive.
*/

#include<bits/stdc++.h>
using namespace std;
int  main(){
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
	#endif
    // int  n;
    // cin>>n;
    // int  * dp = new int[n+1];
    // dp[0]=0;
    // dp[1]=1;
    // for(int i = 2 ; i <= n ; i++){
    //    if((i-5)<0){
    //       dp[i] = 1+dp[i-1];
    //    }else if(i==5){
    //        dp[i]=1;
    //    }else if(i-10<0){
    //        dp[i]=1+min(dp[i-1],dp[i-5]);
    //    }else if(i==10){
    //      dp[i]=1;
    //    }else if(i-20<0){
    //        dp[i]=1+min(dp[i-1],min(dp[i-5],dp[i-10]));
    //    }else if(i==20){
    //    	   dp[i]=1;
    //    }else if(i-100<0){
    //    	   dp[i] = 1+min(dp[i-1],min(dp[i-5],min(dp[i-10],dp[i-20])));
    //    }else if(i==100){
    //        dp[i]=1;
    //    }
    //    else if(i>100){
    //        dp[i] = 1+min(dp[i-1],min(dp[i-5],min(dp[i-10],min(dp[i-20],dp[i-100]))));
    //    }
    //  }
    // cout<<dp[n];
    // delete []dp;
      //this approach is more better here 
int num,m=0; 
cin>>num; 
if(num/100) 
m+=(num/100);
num-=(num/100)*100; 
if(num/20) 
m+=(num/20);
num-=(num/20)*20; 
if(num/10) 
m+=(num/10);
num-=(num/10)*10; 
if(num/5) 
m+=(num/5);
num-=(num/5)*5; 
m+=num; 
cout<<m; 
return 0;
   
       
}
