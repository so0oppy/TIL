#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    int l = phone_number.length();
    
    for(int i=5; i<=l; i++){
        phone_number[l-i] = '*';
    }
    answer = phone_number;
    
    return answer;
}