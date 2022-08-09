#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max; //최대공약수
    int min; //최소공배수

    //최대공약수 구하기
    for(int i=1; i<=n; i++){ //n으로 하든 m으로 하든 결과는 동일
        if(n % i == 0 && m % i == 0){
            max = i; //max 업데이트
        }
    }
    //최소공배수 구하기
    //최소공배수 = n * m / 최대공약수
    min = (n * m) / max;

    answer = {max, min};

    return answer;
}