/*
A. Petya and Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.
*/
#include<bits/stdc++.h>
using namespace std;
int  main(){
	// #ifndef ONLINE_JUDGE
 //      freopen("input.txt","r",stdin);
 //      freopen("output.txt","w",stdout);
	// #endif
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int n = s1.length();
    int i;
    for( i = 0 ; i < n ;)
    {
 
    	if(s1[i]==s2[i]||s1[i]==s2[i]+32||s1[i]==s2[i]-32){
           i++;
        }else{
        	int a = s1[i];
        	int b = s2[i];
        	if((a<97&&b<97)||(a>=97&&b>=97)){
        		if(s2[i]>s1[i]){
        			cout<<"-1";
        			break;
        		}else{
        			cout<<"1";
        			break;
        		}
        	}else if(b>=97&&a<97){
        		if(s2[i]-32>s1[i]){
        			cout<<"-1";
        			break;
        		}else{
        			cout<<"1";
        			break;
        		}
        	}else if(b<=97&&a>=97){
        		if(s2[i]+32>s1[i]){
        			cout<<"-1";
        			break;
        		}else{
        			cout<<"1";
        			break;
        		}
 
        	}else{
 
        	}
        }
 
        
 
    	 
 
    }if(i==n){
    	cout<<"0";
    }
   
 
}
