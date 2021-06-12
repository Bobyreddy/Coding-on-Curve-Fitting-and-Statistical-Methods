#include<stdio.h>

int getMax(int a[], int n){
    int l = a[0], li;
    for(int i=0; i<n; i++){
        if(a[i]>=l){
        l = a[i];
        li = i;
        }
    }
    a[li] = '\0';
    return li;
}

void main(){
    int n, x[15], X[15], RX[15], y[15], Y[15], RY[15], d[15], D[15], sumD = 0;
    float p;
    printf("Enter the N: ");
    scanf("%d", &n);
    printf("Enter the values of X: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
        X[i] = x[i];
    }
    printf("Enter the values of Y: \n");
    for(int j=0; j<n; j++){
        scanf("%d", &y[j]);
        Y[j] = y[j];
    }

    int rx=1;
    for(int i=0; i<n; i++){
        int l = getMax(X, n);
        RX[l] = rx++;
    }
    int ry=1;
    for(int i=0; i<n; i++){
        int l = getMax(Y, n);
        RY[l] = ry++;
    }

    for(int i=0; i<n; i++){
        d[i] = RX[i] - RY[i];
        D[i] = d[i]*d[i];
        sumD += D[i];
    }
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("|\tx\t|\tRx\t|\ty\t|\tRy\t|\tdi\t|\tdi^2\t|\n");
    for(int i=0; i<n; i++){
    printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", x[i], RX[i], y[i], RY[i], d[i], D[i]);
    }
    printf("--------------------------------------------------------------------------------------------------\n");
    float a = 6 * sumD, b = (n*n*n) - n;
    p = 1.0 - (a/b);
    printf("The rank of corelation = %.3f", p);
}
