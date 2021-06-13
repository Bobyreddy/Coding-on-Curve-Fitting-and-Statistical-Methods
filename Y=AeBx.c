#include<stdio.h>
#include<math.h>

void main(){
    int n;
    float x[15], y[15], x2[15], Y[15], xy[15], d[4],a, b, A;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    float sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumXY = 0.0;
    printf("\nEnter the values of X : \n");
    for(int i=0; i<n; i++){
        scanf("%f", &x[i]);
        x2[i] = x[i]*x[i];
        sumX += x[i];
        sumX2 += x2[i];
    }

    printf("\nEnter the values of Y : \n");
    for(int i=0; i<n; i++){
        scanf("%f", &y[i]);
        Y[i] = log(y[i]);
        xy[i] = x[i] * Y[i];
        sumY += Y[i];
        sumXY += xy[i];
    }

    d[0] = ( sumY / n );
    d[1] = ( -1 ) * ( sumX / n );
    d[2] = ( sumXY / sumX );
    d[3] = ( -1 ) * ( sumX2 / sumX ); 
    b = ( ( d[2] - d[0] ) / ( d[1] - d[3] ) );
    a = d[0]+(d[1]*b);

    A = exp(a);

    printf("\n-----------------------------------------------------------------------------------\n");
    printf("|\tx\t|\ty\t|\tY=logy\t|\txY\t|\tx2\t|\n");
    for(int i=0; i<n; i++){
        printf("|\t%.2f\t|\t%.2f\t|\t%.4f\t|\t%.4f\t|\t%.2f\t|\n", x[i], y[i], Y[i], x2[i], xy[i]);
    }
    printf("------------------------------------------------------------------------------------\n");


    printf("sumX: %.2f\nsumY: %.2f\nsumXY: %.2f\nsumX2: %.2f\n", sumX, sumY, sumXY, sumX2);
    printf("Y = %.4f e ^ %.4f x   is the required solution.\n", A, b );
}