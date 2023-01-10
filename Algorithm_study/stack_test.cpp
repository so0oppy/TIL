#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
	dat[pos++] = x;
}

void pop(){
	pos--;  //pos값을 하나 줄여놓고, 어차피 push를 하면 pos위치에 해당 숫자가 덮여 씌워질 것이므로 굳이 맨 위 값을 지우지 않아도 된다.
}

int top(){
	return dat[pos-1];
}

void test(){
  push(5); push(4); push(3);
  cout << top() << '\n'; // 3
  pop(); pop();
  cout << top() << '\n'; // 5
  push(10); push(12);
  cout << top() << '\n'; // 12
  pop();
  cout << top() << '\n'; // 10
}

int main(void) {
	test();
}