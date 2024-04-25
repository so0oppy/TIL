### 스마트 포인터

특징

- 포인터처럼 동장하는 클래스 템플릿
- 사용이 끝난 메모리를 자동으로 해제
- memory 헤더 파일을 include 해야 함

종류

- shared_ptr
- unique_ptr
- weak_ptr : 순환 참조 악순환을 끊기 위함

> `#include <stdio.h>`
> 
> 
> `#include <memory>`
> 
> `using namespace std;`
> 
> `class Player {`
> 
> `private:`
> 
> `int hp;`
> 
> `public:`
> 
> `Player(int _hp) : hp(_hp) {}`
> 
> `void Print() {`
> 
> `printf(”hp : %d”, hp);`
> 
> `}`
> 
> `};`
> 
> `int main()`
> 
> `{`
> 
> // make_shared함수 : 객체가 생성될 때 예외가 생겨도 안전하게 생성하도록 도와주는 함수
> 
> //`shared_ptr<Player> sp = make_shared<Player>(10);`
> 
> // unique_ptr
> 
> `unique_ptr<Player> up(new Player(100));`
> 
> 혹은
> 
> `unique_ptr<Player> up = make_unique<Player>(100);`
> 
> // `auto up2 = up;` ← 불가능 (유니크하므로 하나만 생성 가능, up을 up2에 할당 불가능)
> 
> `auto up2 = std::move(up);` ← 메모리는 옮길 수 있고, 대신 up은 이제 사용 불가능해짐
> 
> `up2 → Print();`
> 
> `shared_ptr<Player> sp(new int(10));` // new이므로 메모리 삭제도 같이 해줘야 하는데
> 
> `shared_ptr<Player> temp = sp;`
> 
> // weak_ptr
> 
> `weak_ptr<Player> wp = sp;` // 이걸 추가해도 sp의 참조카운트는 올라가지 않음
> 
> // weak_ptr의 참조 포인터가 만료되었는지 확인 필요
> 
> `printf(”wp 참조 포인터 만료? : %d”, wp.expired() ? “invalid” : “valid”);`  // wp 참조 포인터 만료? valid
> 
> `if(false == wp.expired()) {`
> 
> `wp.lock() → Print();  // hp : 10`
> 
> `}`
> 
> `sp → Print();  // hp : 10`
> 
> `printf(”sp 참조 카운트 : %d”, sp.use_count());`  // sp 참조 카운트 : 2
> 
> `printf(”sp 유니크한가? : %s”, sp.unique() ? “yes” :  “no”);`  // sp 유니크 한가? : no, 삼항 연산자 ‘?’활용
> 
> `// delete();` ← 스마트 포인터는 delete로 메모리 삭제를 하지 않고 내부적으로 자동으로 삭제 해줌.
> 
> `auto sp2(sp);`  // auto == shared_ptr<Player>와 동일
> 
> `printf(”sp 참조 카운트 : %d”, sp.use_count());`  // sp 참조 카운트 : 2
> 
> `printf(”sp2 참조 카운트 : %d”, sp2.use_count());`  // sp2 참조 카운트 : 2
> 
> `printf(”sp 유니크한가? : %s”, sp.unique() ? “yes” : “no”);`  // sp 유니크한가? : no
> 
> `printf(”sp와 sp2가 같은가? %s”, sp == sp2 ? “yes” : “no”);`  // sp와 sp2가 같은가? : yes
> 
> // 메모리 해제 (방법1)
> 
> `sp = nullptr;` // 매개 변수가 없을 때 사용
> 
> `printf(”sp 참조 카운트 : %d”, sp.use_count());`  // sp 참조 카운트 : 0
> 
> `printf(”sp2 참조 카운트 : %d”, sp2.use_count());`  // sp2 참조 카운트 : 1
> 
> `printf(”sp 유니크한가? : %s”, sp.unique() ? “yes” : “no”);`  // sp 유니크한가? : no
> 
> `printf(”sp와 sp2가 같은가? %s”, sp == sp2 ? “yes” : “no”);`  // sp와 sp2가 같은가? : no
> 
> `sp.swap(sp2);`
> 
> `printf(”sp 참조 카운트 : %d”, sp.use_count());`  // sp 참조 카운트 : 1
> 
> `printf(”sp2 참조 카운트 : %d”, sp2.use_count());`  // sp2 참조 카운트 : 0
> 
> // 메모리 해제 (방법2)
> 
> `sp.reset(new Player(100));` // 매개 변수가 있을 때 사용
> 
> `printf(”sp 참조 카운트 : %d”, sp.use_count());`  // sp 참조 카운트 : 1
> 
> `printf(”sp2 참조 카운트 : %d”, sp2.use_count());`  // sp2 참조 카운트 : 1
> 
> `printf(”sp 유니크한가? : %s”, sp.unique() ? “yes” : “no”);`  // sp 유니크한가? : yes
> 
> `printf(”sp와 sp2가 같은가? %s”, sp == sp2 ? “yes” : “no”);`  // sp와 sp2가 같은가? : no
> 
> `return 0;`
> 
> `}`
>