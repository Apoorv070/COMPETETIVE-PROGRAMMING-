/*
A. Way Too Long Words
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sometimes some words like "localization" or "internationalization" are so long that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be replaced with a special abbreviation.

This abbreviation is made like this: we write down the first and the last letter of a word and between them we write the number of letters between the first and the last letters. That number is in decimal system and doesn't contain any leading zeroes.

Thus, "localization" will be spelt as "l10n", and "internationalization» will be spelt as "i18n".
*/
#include<bits/stdc++.h>
using namespace std;
int  main(){
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
	#endif
    int n;
    cin>>n;
    while(n--){
    	string s;
    	cin>>s;
    	if(s.length()<=10){
          cout<<s<<endl;
    	}else{
          string news;
          int n = s.length()-2;
          string alpha = to_string(n); 
          news = s[0]+alpha+s[n+1];
          cout<<news<<endl;
    	}
    }
 
}
