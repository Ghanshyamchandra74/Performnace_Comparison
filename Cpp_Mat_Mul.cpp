#include <iostream>
#include <time.h>
#include <omp.h>

int main(){
    int n = 700;int A[n][n] , B[n][n], C[n][n];
    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(4);
    #pragma omp parallel
    #pragma omp parallel for collapse(2)
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand()%101;
            B[i][j] = rand()%101;

        }
    }
    clock_t start = clock();int C_ = 0;
    //#pragma omp parallel
    for(int i= 0; i <n; i++){
        #pragma omp parallel for collapse(2)
        for(int j = 0; j <n;j++){
            for(int k = 0; k<n; k++){
                C[i][j] = A[j][k] * B[k][j] + C_;

            }
        }
        C_ = 0;
    } 
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time is = %f", seconds) ;  
    return 0;
}