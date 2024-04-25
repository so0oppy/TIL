STL (standard template library)

### Stack

LIFO (Last In First Out)

- push - pop
- top

### Queue

FIFO (First In First Out)

- push - pop
- front

---

### Stack

> #include <stdio.h>
> 
> 
> #include <stack>
> 
> using namespace std;
> 

> int main()
> 
> 
> {
> 
> stack<char> myStack;
> 
> char str[256] = {0};
> 
> scanf_s(”%s”, &str, 256);   // _s는 크기 지정을 해줘야 함
> 
> for (int i=0; i<256; i++)
> 
> {
> 
> if (str[i] == ‘\0’)  // 문자열의 끝을 만나면 for문 종료
> 
> {
> 
> break;
> 
> }
> 
> // 만약 문자가 숫자가 아니라면 continue;
> 
> if (str[i] < ‘0’ || str[i] > ‘9’)
> 
> {
> 
> continue; // 다시 for문 시작으로 돌아감
> 
> }
> 
> myStack.push(str[i]);  //숫자만 넣음
> 
> }
> 
> // 결과 값을 담을 스택
> 
> stack<char> result;
> 
> // ,를 추가하기 위한 카운트
> 
> int commaCount = 0;
> 
> while(true)
> 
> {
> 
> // myStack의 값을 result에 담고
> 
> result.push(myStack.top());
> 
> // 그 값은 스택에서 삭제할 것 (pop)
> 
> myStack.pop();
> 
> // myStack이 비었다면 반복 종료
> 
> if (true == myStack.empty())
> 
> break;
> 
> // 세 번을 카운트하고 3이 되면
> 
> if (++commaCount ≥ 3) {
> 
> commaCount =0;
> 
> // , 추가
> 
> result.push(’,’);
> 
> }
> 
> }
> 
> while (false == result.empty())
> 
> {
> 
> printf(”%c”, result.top());
> 
> result.pop(); // 입력 값과 순서가 반대로 출력됨
> 
> }
> 
> return 0;
> 
> }
> 

---

### Queue

> #include <stdio.h>
> 
> 
> #include <stack>
> 
> #include <queue>
> 
> using namespace std;
> 

> int main()
> 
> 
> {
> 
> queue<char> myQueue;
> 
> for (int i=0; i<256; i++)
> 
> {
> 
> char c;
> 
> scanf_s(”%c”, &c, 1);
> 
> // 만약 c가 숫자가 아니라면 입력에 대한 반복 종료
> 
> if (c<’0’ || c>’9’)
> 
> {
> 
> break;
> 
> }
> 
> myQueue.push(c);
> 
> }
> 
> while (false == myQueue.empty())
> 
> {
> 
> printf(”%c”, myQueue.front());
> 
> myQueue.pop(); // 입력 값과 순서가 동일하게 출력
> 
> }
> 
> int pos = 0;
> 
> char result[256] = {0};
> 
> int temp = myQueue.size() % 3;
> 
> for(int i=0; i<temp; i++) 
> 
> {
> 
> result[pos++] = myQueue.front();
> 
> myQueue.pop();
> 
> }
> 
> // 만약 숫자가 4자리 이상이고 temp가 0보다 크다면
> 
> if (size > 3 && temp > 0)
> 
> {
> 
> result[pos++] = ‘,’ ;
> 
> }
> 
> while (false == myQueue.empty())
> 
> {
> 
> for (int j = 0; j<3; j++)   // 3개씩 반복적으로 출력
> 
> {
> 
> result[pos++] = myQueue.front();
> 
> myQueue.pop();
> 
> }
> 
> // 만약 다 출력했다면 반복 멈춤
> 
> if ( myQueue.empty())
> 
> break;
> 
> // ,(컴마) 출력
> 
> result[pos++] = ‘,’ ;
> 
> }
> 
> result[pos++] = ‘\0’
> 
> }
>