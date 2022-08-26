#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  Deque<int> D;
  int n;   //입력 받을 횟수
  cin >> n;
  
  while(n--){
    string q; //명령어
    cin >> q;
    
    if(q == "push_front"){
      int X;
      cin >> X;
      D.push_front(X);
    }
    else if(q == "push_back"){
      int X;
      cin >> X;
      D.push_back(X);
    }
    else if(q == "pop_front"){
      if(D.empty()) cout << -1 << '\n';
      else{
        cout << D.front() << '\n';
        D.pop_front();
      }
    }
    else if(q == "pop_back"){
      if(D.empty()) cout << -1 << '\n';
      else{
        cout << D.back() << '\n';
        D.pop_back() << '\n';
      }
    }
    else if(q == "size"){
      cout << D.size() << '\n';
    }
    else if(q == "empty"){
      cout << D.empty() << '\n';
    }
    else if(q == "front"){
      if(D.empty()) cout << -1 << '\n';
      else cout << D.front() << '\n';
    }
    else if(q == "back"){
      if(D.empty()) cout << -1 << '\n';
      else cout << D.back() << '\n';
    }
  }
}  
