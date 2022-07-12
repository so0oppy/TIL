#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int n = arr1.size();
    int m = arr1[0].size();
    
    vector<vector<int>> answer(n, vector<int>(m));
    
    for(int i = 0; i< n; i++){
        for(int j=0; j<m; j++){
            answer[i][j] = arr1[i][j] + arr2[i][j]; 
        }
    }
    
    return answer;
}