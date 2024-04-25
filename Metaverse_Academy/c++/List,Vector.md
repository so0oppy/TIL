container이다.

### List

`#include <stdio.h>`

`#include <list>`

`using namespace std;` 

`int main()`

`{`

`List<int> myList{10, 20, 30};`

`myList.emplace_front(5); // 맨 앞에 넣음`

`myList.emplace_back(40); // 맨 뒤에 넣음`

`auto it = myList.begin(); // 0번 인덱스`

`advance(it, 2); // 인덱스 + 2 = 2`

`myList.emplace(it, 1); // it위치 앞에 1 넣음`

`// 5 10 15 20 30 40`

`// 리스트에서 30을 찾아서 그것의 it (iterator)을 얻고 싶음`

`auto find_it = find(myList.begin(), myList.end(), 30);`

`// 만약 검색 결과가 끝이 아니라면 25 삽입`

`if ( find_it ≠ myList.end())`

`{`

`myList.emplace(find_it, 25);`

`}`

`myList.remove(15);`

`List<int> myList2 = { 100, 200 };`

`myList.merge(myList2);  // 전체를 맨 뒤에 병합 (병합된 것의 리스트엔 아무것도 남지 않음)`

`auto splice_it = myList.begin();`

`auto end_it = myList2.begin();`

`advance(end_it, 1);  // myList2의 1번 인덱스`

`myList.splice(splice_it, myList2, myList2.begin(), end_it);  // splice_it 위치에 병합됨, begin()부터 end_it 인덱스까지만 병합됨`

`for (auto item : myList)`

`{`

`printf(”%d”, item);`

`}`

`for (auto item : myList2)`

`{`

`printf(”%d”, item);`

`}`

`return 0;`

`}`

---

### Vector

연속적인 메모리 공간

- size
- capacity

`#include <stdio.h>`

`#include <list>`

`#include <vector>`

`using namespace std;`

`class Player {`

`private:`

`int hp;`

`public:`

`Player(int _hp) : hp(_hp) {}`

`void Print() {`

`printf(”hp : %d”, hp);`

`}`

`Player(const Player& p) : hp(p.hp) {`

`prinft(”복사 생성자가 호출됨”);`

`}`

`Player(Player&& p) : hp(move(p.hp)) {`

`prinft(”이동 생성자가 호출됨”);`

`}`

`int main()`

`{`

`// vector<int> v = { 10, 20, 30 };`

`vector<Player> v;`

`v.reserve(2);  // vector의 capacity를 지정하고 싶을 땐 reserve함수를 쓰는 게 좋음 (메모리 복사가 안 일어남) → 아래 두 줄이 있어도 ‘size : 2, capacity : 2’ 가 됨`

`// v.emplace_back(Player(1));  ← ‘이동 생성자가 호출됨, capacity : 1’`

`v.emplace_back(1);  // 이렇게 해도 Player 호출됨 ← ‘size : 1, capacity : 1‘`

`printf(”size : %d”, v.size());  // 벡터의 사이즈`

`printf(”capacity : %d”, v.capacity());  // 메모리 공간 (값을 변경하면 사용하지 않는 메모리 공간도 생기므로 벡터의 사이즈보다 클 수 있음)`

`v.emplace_back(40);  // 뒤에 넣는 이유 : 가장 빠름, O(1)`

`v. pop_back();  // O(1)`

`auto it = v.begin();`

`advance(it, 1);`

`v.emplace(it, 15);  // it위치에 15 추가, O(N)`

`auto find_it = find(v.begin(), v.end(), 20);`

`if (find_it ≠ v.end())`

`{`

`v.erase(find_it);  // O(N)`

`}`

`printf(”v : “);`

`for (auto item : v)`

`{`

`printf(”%d”, item);`

`}`