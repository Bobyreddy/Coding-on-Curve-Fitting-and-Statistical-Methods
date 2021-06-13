#include<stdio.h>

void main(){
    int n;
    float x[15], y[15], x2[15], xy[15], d[4],a, b, c, Y;
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
        xy[i] = x[i] * y[i];
        sumY += y[i];
        sumXY += xy[i];
    }
    printf("\nEnter the constant C: ");
    scanf("%f", &c);

    d[0] = ( sumY / n );
    d[1] = ( -1 ) * ( sumX / n );
    d[2] = ( sumXY / sumX );
    d[3] = ( -1 ) * ( sumX2 / sumX ); 
    b = ( ( d[2] - d[0] ) / ( d[1] - d[3] ) );
    a = d[0]+(d[1]*b);

    Y = a+(b*c);

    printf("\n-----------------------------------------------------------------------\n");
    printf("|\tX\t|\tY\t|\tX2\t|\tXY\t|\n");
    for(int i=0; i<n; i++){
        printf("|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\n", x[i], y[i], x2[i], xy[i]);
    }
    printf("------------------------------------------------------------------------\n");


    printf("sumX: %.2f\nsumY: %.2f\nsumXY: %.2f\nsumX2: %.2f\n", sumX, sumY, sumXY, sumX2);
    printf("Y = %.2f X + %.2f    is the required solution.\n", b, a );
    printf("When c = %.2f => Y = %.4f", c, Y);
}