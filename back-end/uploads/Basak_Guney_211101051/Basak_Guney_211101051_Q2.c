#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double exponential(double ,int);
double modified_exponential(double x,int m);

int main(){



    printf("UNMODIFIED EXPONENTIAL FUNCTION IS RUNNING...\n\n");



    printf("Computing exp(x) for 1000 random values of 0.0 < x < 1.0 with M=10...\n");
    clock_t start=clock();
    for(int i=0;i<1000;i++){
        srand(time(NULL));
        double random_x=1/(double)(rand()+1);
        exponential(random_x,10);
    }
    clock_t end=clock();
    double total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total execution time: %.10f\n",total_time);


    printf("Computing exp(x) for 1000 random values of 0.0 < x < 1.0 with M=15...\n");
    start=clock();
    for(int i=0;i<1000;i++){
        srand(time(NULL));
        double random_x=1/(double)(rand()+1);
        exponential(random_x,15);
    }
    end=clock();
    total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total execution time: %.10f\n",total_time);
    

    printf("Computing exp(x) for 1000 random values of 0.0 < x < 1.0 with M=18...\n");
    start=clock();
    for(int i=0;i<1000;i++){
        srand(time(NULL));
        double random_x=1/(double)(rand()+1);
        exponential(random_x,18);
    }
    end=clock();
    total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total execution time: %.10f\n",total_time);



    printf("\nMODIFIED EXPONENTIAL FUNCTION IS RUNNING...\n\n");




    printf("Computing exp(x) for 1000 random values of 0.0 < x < 1.0 with M=10...\n");
    start=clock();
    for(int i=0;i<1000;i++){
        srand(time(NULL));
        double random_x=1/(double)(rand()+1);
        modified_exponential(random_x,10);
    }
    end=clock();
    total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total execution time: %.10f\n",total_time);


    printf("Computing exp(x) for 1000 random values of 0.0 < x < 1.0 with M=15...\n");
    start=clock();
    for(int i=0;i<1000;i++){
        srand(time(NULL));
        double random_x=1/(double)(rand()+1);
        modified_exponential(random_x,15);
    }
    end=clock();
    total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total execution time: %.10f\n",total_time);


    printf("Computing exp(x) for 1000 random values of 0.0 < x < 1.0 with M=18...\n");
    start=clock();
    for(int i=0;i<1000;i++){
        srand(time(NULL));
        double random_x=1/(double)(rand()+1);
        modified_exponential(random_x,18);
    }
    end=clock();
    total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total execution time: %.10f\n",total_time);


    return 0;
}

double exponential(double x,int m){
    double sum=1;
    for(int n=1;n<=m;n++){
        int fac_n=n;
        double pow_x=x;
        for(int i=fac_n-1;i>0;i--){
            fac_n=fac_n*i;
            pow_x=pow_x*x;
        }
        sum=sum+(pow_x/fac_n);
    }
    return sum;
}


double modified_exponential(double x,int m){
    double sum=1;
    double term=1;
    int k=1;
    for(int i=1;i<=m;i++){
        term=(term*x)/k;
        k=k*(i+1);
        sum=sum+term;
    }
    return sum;
}