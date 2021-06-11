#include<stdio.h>


void main(){
    int n, x[100], y[100], d[100], D[100], sumD = 0;
    float p;
    printf("Enter the N: ");
    scanf("%d", &n);
    printf("Enter the values of X: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }
    printf("Enter the values of Y: \n");
    for(int j=0; j<n; j++){
        scanf("%d", &y[j]);
    }
    for(int i=0; i<n; i++){
        d[i] = x[i] - y[i];
        D[i] = d[i]*d[i];
        sumD += D[i];
    }
    float a = 6 * sumD, b = (n*n*n) - n;
    p = 1.0 - (a/b);
    printf("The rank of corelation = %.3f", p);

}
