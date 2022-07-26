#include <bits/stdc++.h>
using namespace std;

/*
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string S;
	cin >> S;
	
	for(char a='a'; a <= 'z'; a++){
		int cnt = 0;
		for(auto c: S){
			if(a == c) cnt++;
		}
		cout << cnt << ' ' ;
	}
}
*/

// 더 나은 코드
int freq[26];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string S;
	cin >> S;
	
	for(auto c : S){
		freq[c - 'a']++;
	}
	for(int i=0; i<26; i++){
		cout << freq[i] << ' ';
	}
}