### friend : 함수와 클래스 형태로 사용할 수 있음

> `class Player {`
> 

> `private:`  // friend함수로 인해 private인데도 읽을 수 있게 됨
> 

> `int hp;`
> 

> `public:`
> 
> 
>      `Player(int _hp) : hp(_hp) {}`
> 
>      `friend class PlayerUtil;` // 전방선언 (약식으로 쓸 땐 이렇게 안 에 넣고, 원래는 class Player보다도 위에 적음)
> 
>      `friend void Print(const Player& p);` 
> 

> `};`
> 

> `void Print(const Player& p) {`
> 
> 
>      `printf(”hp : %d”, p.hp);`
> 

> `}`
> 

> `class PlayerUtil {`    // friend 덕에 사용가능해짐
> 

> `public:`
> 
> 
>      `void Print(const Player& p){`
> 
>      `printf(”hp : %d”, p.hp);`
> 
>      `}`
> 

> `}`
> 

> `int main()`
> 

> `{`
> 
> 
>      `Player player(100);`
> 
>      `Print(player);` // hp = 100 출력됨
> 
>    혹은
> 
>      `PlayerUtil util;`
> 
>      `util.Print(player);` // hp = 100 출력됨
> 
>      `return 0;`
> 

> `}`
> 

---

> …
> 
> 
>      // 이동 생성자
> 

> `Character(int&& value)`
> 
> 
>      `{`
> 
>      `this → hp = value;`
> 
>      `}`
> 
>      `void Print() {`
> 
>      `printf(”name: %s, hp: %d \n”, name, hp);`
> 
>      `}`
> 
>      // 아래 함수를 그대로 friend로 만든 것
> 
>      `friend Character operator+(int value, Character c);` 
> 
> `};`
> 

> `Character operator+(int value, Character c) {`
> 
> 
>      `c.hp += value;` // friend함수 덕에 hp변수를 위에서 참조가 가능해짐
> 
> `return c;`
> 
> `}`
> 

> `int main()`
> 

> `{`
> 
> 
>      `Character c1(”c1”, 100);`
> 
> `Character c2 = 10 + c1;`   // friend 함수 덕에 사용가능
> 
> `c2.SetName("c2");`
> 
> `c2.Print();`
> 
> `return 0;`
> 
> `}`
>