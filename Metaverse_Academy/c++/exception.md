비정상적인 상황 처리하는 것

`class InvalidArgumentException{`

`private:`

`string msg;`

`public:`

`InvalidArgumentException(const string& _msg) : msg(_msg) {}`

`const char* what() {`

`return msg.c_str();`  ←c_str()은 const char라는 뜻

`}`

`};`

`if (범위 외){`

`throw “예외발생”;` ← catch(const char* e) 쓸 때

`혹은` 

`throw -1;` ← catch(int e)를 쓸 때

혹은

`string errMsg = __FUNCTION__ + to_string(__LINE__) + string(” 입력 값이 범위를 벗어남”) + to_string(newHP);`  ← __FUNCTION__은 현재 함수 명을 문자로 표시해줌, __LINE__은 현재 줄 위치, to_string(newHP)는 어떤 값인지 보여줌 

`throw InvalidArgumentException(errMsg);` ← 위 Invalid 클래스 쓸 때

`}`

`int main() {`

`…`

`try{`

`원래 작성하고 싶은 값;`

`}`

`catch (int e){`  ←catch안 쓰면 에러남

`printf(”%d”, e);` ← 위 throw의 “예외발생” 내용 출력

`}`

`catch (const char* e){`

`printf(”%s”, e);` ← 위 throw의 “예외발생” 내용 출력

`}`

`catch(InvalidArgumentException e){`

`printf(”%s”, e.what());`  // 입력 값이 범위를 벗어남

`}`

`}`

---

### c++에서 제공하는 예외처리

`..`

`#include <stdexcept>` 

// assert 라는 것도 있음 

`#include <cassert>`  ← c에서의 assert함수 추가 가능

// assert(~) ← ~내의 내용이 거짓이면 오류 발생

`class InvalidArgumentException : public std::exception {`

`private:`

`string msg;`

`public:`

`InvalidArgumentException(const string& _msg) : msg(_msg) {}`

virtual `const char* what() const noexcept override{`  ← noexcept = 절대 예외 발생 안 하게 하겠다.

`return msg.c_str();`  ←c_str()은 const char라는 뜻

`}`

`};`

`class TestException : public std::exception {`

`private:`

`string msg;`

`public:`

`TestException(const string& _msg) : msg(_msg) {}`

`virtual const char* what() const noexcept override{` 

`return msg.c_str();`  ←c_str()은 const char라는 뜻

`}`

`};`

`…`

`int main() {`

`…`

`try{`

`…`

`}`

`catch (std::exception& e)`

`{`

`printf(”%s”, e.what());` ← what은 가상함수 

`}`

`return 0;`

`}`