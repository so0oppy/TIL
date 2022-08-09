#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//콜라츠(Collatz) 추측

int solution(int num) {
    int answer = 0;
    int cnt = 0; //반복 횟수
    long n = (long)num;
    
    while(n != 1){
        if(cnt == 500) {    //작업이 500번 넘어갈 때
            cnt = -1;
            break;
        }
        if(n % 2 == 0){   //짝수일 경우
            n = n / 2;
            cnt++;
        }else if(n % 2 == 1){             //홀수일 경우
            n = n * 3 + 1;
            cnt++;
        }
    }
    
    answer = cnt;
    
    return answer;
}