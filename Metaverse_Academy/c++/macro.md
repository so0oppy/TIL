문자열 치환 개념

### Main.cpp

`#include <stdio.h>`

`#include “Player.h”`

//매크로

`#define MAX 10`

`#define int_a int a`

//매크로 함수

`#define ADD(x, y) (x + y)`

`#define PRINT_INT(value) printf(”%d\n”, value);`

`#define PRINT_STRING(str) printf(str);`

`#define PRINT_STRING_NOMAX(str) printf(#str);`

`#define PRINT_STRING_MERGE(str1, str2) printf(str1##str2)`  //토큰 결합 연산자

//가변인자 매크로

`#define VA_PRINT(…) printf(##__VA_ARGS__)` //컴마가 너무 늘어나는 것 방지

`#define VA_PRINT_FMT(fmt, …) printf(fmt, ##__VA_ARGS__)`

`#define MY_LOG(…) printf(”%s (%d) %s”, __FUNCTION__, __LINE__, ##__VA_ARGS__)`

`#define QA_VERSION`

`int main()`

`{`

`int a = MAX;` //치환됨

`int result = ADD(10, 20);`

`PRINT_INT(result);`

`PRINT_STRING_NPMARK(Hello World\n);`

`PRINT_STRING_MERGE(”Hello  “, “   World!\n”);`

`VA_PRINT(”%s%s”, “반가워~”, “잘 지냈니?”);`  //반가워~잘 지냈니?

`VA_PRINT_FMT(”%s%s”, “반가워~”, “잘 지냈니?”);`  //반가워~잘 지냈니? ← 더 명시적이고, 무조건 앞에 %값 넣어야 함

`MY_LOG(”반가워!”);`  // main (현 위치의 줄 수) 반가워!

//———————————————————————

`Player p;`

`p.Print();`

`#ifdef QA_VERSION`

`p.SetData(10000, 1000000);`

`#else`

`p.SetData(100, 100);`

`#endif`

`return 0;`

`}`

### Player.h 파일 (클래스 파일)

`#pragma once` ←클래스 파일이 하나만 있다는 뜻

// 위에는 최근 방식

// 아래는 옛날 방식

`#ifndef _PLAYER_H_`  ←만약 해당 매크로가 define되어있지 않다면 아래 클래스 실행X

`#define _PLAYER_H_`

`class Player`

`{`

`private:`

`int hp;`

`int gold;`

`public:`

`void print();`

`inline void SetData(int newHP, int newGold)`  ← 인라인 함수(매크로와 흡사한 동작, inline글자가 없어도 인라인 함수임을 알아야 함)

`{`  

`hp = newHP;`

`gold = newGold;`

`}`

`};`

`#endif`  ← ifndef이 있다면 무조건 추가

### Player.cpp

`#include “Player.h”`

`#include <stdio.h>`

`void Player::Print()`

`{`

`printf(”hp : %d, gold : %d”, hp, gold);`

`}`

---

## C++ 빌드 과정

1. Player.cpp →(전처리기, Preprocessor)→ Player.i →(컴파일러, Compiler)→ Player.s →(어셈블러, Assembler)→ Player.o
2. Main.cpp →(Pre)→ Main.i →(Com)→ Main.s →(Asm)→ Main.o

**1, 2 → Linker → 실행파일**