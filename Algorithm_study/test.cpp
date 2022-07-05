

int func2(int arr[], int N){
    //0<= i <=100
    //1<= N <= 1000
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(arr[i] + arr[j] == 100)
            return 1;
        }
    }
    return 0;
}

int func3(int N){
    for(int i=1; i*i<=N; i++){
        if(i*i == N) return 1;
    }
    return 0;
}

int func4(int N){
    int val = 1;
    while(2*val <= N) val *= 2;
    return val;
}