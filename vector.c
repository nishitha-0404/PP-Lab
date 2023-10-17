#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void vector_add_parallel(int n,int * vector_a,int * vector_b ,int * res_vector){
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        res_vector[i]=vector_a[i]+vector_b[i];
    }
}
void main(){
    int n=100000;
    int vector_a[100000],vector_b[100000],res_vector[100000];
    for(int i=0;i<n;i++){
        vector_a[i]=rand()%10;
        vector_b[i]=rand()%10;
    }
    double start=omp_get_wtime();
    vector_add_parallel(n,vector_a,vector_b,res_vector);
    double end=omp_get_wtime();
    printf("time taken for parallel vector addition is%f",end-start);
}