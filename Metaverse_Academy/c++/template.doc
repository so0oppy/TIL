### 템플릿

특징

- 컴파일 타임에 코드가 구체화됨
- 함수 템플릿과 템플릿 클래스 두 종류
- 코드의 재사용
- 유지보수에 용이
- 타입 관련 오류 사전방지

주의사항

- 선언부와 구현부를 같은 파일에 작성해야 함

### 함수 템플릿

> `#include <stdio.h>`
> 
> 
> 
> // 함수 템플릿 (부분 특수화는 안 되고, 전체 특수화만 가능)
> 
> `template<typename T>`
> 
> `T Add(T a, T b)`
> 
> `{`
> 
>      `return a + b;`
> 
> `}`
> 
> // 부분 특수화 (불가능)
> 
> `template<typename T1, bool>`
> 
> `T1 Add(T1 a, bool b)`
> 
> `{`
> 
> `return a;`
> 
> `}`
> 
> // 전체 특수화
> 
> `template<>`
> 
> `char* Add(char* a, char* b)`
> 
> `{`
> 
> `int len = strlen(a) + strlen(b) + 1;`
> 
> `char* str = new char[len];`
> 
> `strcpy_s(str, len, a)` // 목적지, 사이즈, 소스(목적지에 소스를 복사) 
> 
> `strcat_s(str, len, b)` //목적지, 사이즈, 소스 (목적지에 소스를 붙여넣음)
> 
> `return str;`
> 
> `}`
> 

> // 함수 템플릿 오버로딩
> 
> 
> `template<typename T>`
> 
> `T Add(T a, T b, T c)`    // 같은 함수 이름을 사용하지만 변수는 다르게
> 
> `{` 
> 
> `return a + b + c;`
> 
> `}`
> 

> `int main()`
> 
> 
> `{`
> 
> `char str1[] = “ab”;`
> 
> `char str2[] = “cd”;`
> 
> `char* str = Add(str1, str2);`
> 
> `printf(”%s”, str);  // abcd` 
> 
> `delete str;`
> 
> `printf (”%d”, Add(10, 20)); //` 30
> 
> `printf (”%f”, Add(10.0f, 20.0f));` // 30.000000
> 
> `printf(”%d”, Add(10, 20, 30));` // 60, 함수 오버로딩을 이용
> 
> `return 0;`
> 
> `}`
> 

---

### 한글 인식되도록 모든 파일 변경하는 방법

1. 솔루션 탐색기 > 프로젝트에서 마우스 오른쪽 버튼 > 추가 > 새 editorconfig > 선택
2. 파일 경로 > .editorconfig > 에디터 편집 > `root = true` 밑에 
    
    `[*]`
    
    `charset = utf-8-bom`
    
    추가 및 저장
    
     
    

---

### 템플릿 클래스

위 코드에 이어서..

> // 템플릿 클래스
> 
> 
> `template<typename T1, typename T2>`
> 
> `class Calc {`
> 
> `private:`
> 
> `T1 a;`
> 
> `T2 b;`
> 
> `public:`
> 
> `T1 Add(T1 a, T2 b){`
> 
> `this → a = a;` //위에 있는 a를 가져옴
> 
> `this → b = b;`
> 
> `return a + b;`
> 
> `}`
> 
> `void Print() {`
> 
> `printf(”Calc : %d”, a+b);`
> 
> `}`
> 

> // 부분 특수화
> 
> 
> `template<typename T1>`
> 
> `class Calc<T1, float> {`
> 
> `private:`
> 
> `T1 a;`
> 
> `float b;`
> 
> `public:`
> 
> `T1 Add(T1 a, float b){`
> 
> `this → a = a;` //위에 있는 a를 가져옴
> 
> `this → b = b;`
> 
> `return a + b;`
> 
> `}`
> 
> `void Print_f(){`
> 
> `printf(”Calc 부분 특수화 : %f”, a+b);`
> 
> `}`
> 
> // 전체 특수화 
> 
> `template<>`
> 
> `class Calc<double, double> {`
> 
> `private:`
> 
> `double a;`
> 
> `double b;`
> 
> `public:`
> 
> `double Add(double a, float b){`
> 
> `this → a = a;` //위에 있는 a를 가져옴
> 
> `this → b = b;`
> 
> `return a + b;`
> 
> `}`
> 
> `void Print_d(){`
> 
> `printf(”Calc 전체 특수화 : %f”, a+b);`
> 
> `}`
> 

> `int main()`
> 
> 
> `{`
> 
> `Calc<int, int> calc;`
> 
> `printf(”%d”, calc.Add(100, 200));`  // 300 
> 
> `calc.Print(); // Calc : 300`
> 
> `Calc<float, float> calc_f;`
> 
> `printf(”%f”, calc_f.Add(100, 200));` // 300.000000
> 
> `calc_f.Print_f(); // Calc 부분 특수화` : 300.000000
> 
> `Calc<double, double> calc_d;`
> 
> `printf(”%d”, calc_d.Add(100.0, 200.0));`  // 300.000000
> 
> `calc_d.Print_d();`  // Calc 전체 특수화 : 300.000000
> 
> `}`
>