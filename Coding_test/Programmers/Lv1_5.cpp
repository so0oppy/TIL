#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0; //평균값
    double sum = 0; //합
    
    for(int i=0; i < arr.size(); i++){
        sum += arr[i];
    }
    answer = sum / arr.size();
    
    return answer;
}