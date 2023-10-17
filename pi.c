#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 12 // this line is very important
static long num_steps = 100000; 
double step;

void main(){
    int i;
    double x,pi,sum[NUM_THREADS];
    step = 1.0/(double) num_steps;

    #pragma omp parallel private(i,x)
    {
        int id = omp_get_thread_num();
        double local_sum = 0.0;
        for(i = id,sum[id]=0.0;i<num_steps;i+=NUM_THREADS){
            x = (i+0.5)*step;
            local_sum+= 4.0/(1.0+x*x);
        }
        #pragma omp critical
        {
            sum[0] += local_sum;
        }
    }
    pi = sum[0]/num_steps;
    printf("pi = %6.12f\n",pi);
}

// sequential calculation of pi
int num_steps=100000;
double step;
int main(){
    int i;
    double x, pi, sum=0.0;
    step=1.0/(double)num_steps;
    for(i=0;i<num_steps;i++){
        x=(i+0.5)*step;
        sum=sum+4.0/(1.0+x*x);
    }
    pi=step*sum;
    printf("%6.12f ",pi);
}