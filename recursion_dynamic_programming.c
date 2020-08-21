#include <stdio.h>
#include <time.h>

long recursive_solution(int n, int k){
    if(n > 0 && k > 0)
        return recursive_solution(n-1, k-1) + recursive_solution(n-1, k);
    
    else if(n >= 0 && k == 0)
        return 1;
    
    else if(n == 0 && k > 0)
        return 0;
    else
        return 1;
}

long DP_solution(int n, int k){
    long dp[n+1][k+1];
    
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < k+1; j++){
            if(i > 0 && j > 0)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else if(i >= 0 && j == 0)
                dp[i][j] = 1;
            else if(i == 0 && j > 0)
                dp[i][j] = 0;
            else if(i == j)
                dp[i][j] = 1;
        }
    }

    return dp[n][k];

}

int main(){

    int n = 0, k = 0;
    clock_t start_d, start_r, end_d, end_r;
    float dp, re;

    printf("Enter two numbers for the combination <C(n, k)> = n k >> ");
    scanf("%d %d", &n, &k);

    start_d = clock();
    printf("DP_solution = %lu\n", DP_solution(n, k));
    end_d = clock();

    dp = (float)(end_d - start_d) / CLOCKS_PER_SEC;
    printf("DP_solution TIME: %.4f\n", dp);

    start_r = clock();
    printf("recursive_solution = %lu\n", recursive_solution(n, k));
    end_r = clock();

    re = (float)(end_r - start_r) / CLOCKS_PER_SEC;
    printf("recursive_solution TIME = %.4f\n", re);
    
    return 0;
}