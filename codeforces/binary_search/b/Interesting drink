/*
B. Interesting drink
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasiliy likes to rest after a hard work, so you may often meet him in some bar nearby. As all programmers do, he loves the famous drink "Beecola", which can be bought in n different shops in the city. It's known that the price of one bottle in the shop i is equal to x i coins.

Vasiliy plans to buy his favorite drink for q consecutive days. He knows, that on the i-th day he will be able to spent m i coins. Now, for each of the days he want to know in how many different shops he can buy a bottle of "Beecola".

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of shops in the city that sell Vasiliy's favourite drink.

The second line contains n integers x i (1 ≤ x i ≤ 100 000) — prices of the bottles of the drink in the i-th shop.

The third line contains a single integer q (1 ≤ q ≤ 100 000) — the number of days Vasiliy plans to buy the drink.

Then follow q lines each containing one integer m i (1 ≤ m i ≤ 109) — the number of coins Vasiliy can spent on the i-th day.

Output
Print q integers. The i-th of them should be equal to the number of shops where Vasiliy will be able to buy a bottle of the drink on the i-th day.
*/
#include<bits/stdc++.h>
using namespace std;
int  main(){
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
	#endif
      int no_of_shops;
      cin>>no_of_shops;
      int price[no_of_shops];
      for(int i = 0 ; i<no_of_shops ; i++)
      	  cin>>price[i];
      int no_of_days;
      cin>>no_of_days;
      sort(price,price+no_of_shops);
      while(no_of_days--){
      	int i = 0;
      	int j = no_of_shops-1;
      	int spend;
      	cin>>spend;
      	int ans = 0;
      	while(1){
          int mid = (i+j)/2;
          if(price[mid]<spend&&i==j||i>j){
          	ans = mid;
          	break;
          }else if(price[mid]>spend){
            j = mid -1;

          }else{
          	i = mid + 1;
          }
      	}
      	if(price[0]>spend&&ans==0)
      		 cout<<ans<<endl;
      	else
      	    cout<<ans+1<<endl;
      }
    
}
