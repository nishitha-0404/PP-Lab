#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isPrime(int n){
    if(n == 0 || n == 1){
        return 0;
    }
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void main(){
    int x=1;
    int n=50;
    double start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        if(isPrime(i)){
            int t=omp_get_thread_num();
            printf("thread %d prime number %d\n",t,i);
        }
    }
    double end=omp_get_wtime();
    printf("\n Time taken is %f",end-start);
}