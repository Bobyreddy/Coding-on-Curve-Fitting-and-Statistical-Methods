#include<stdio.h>

void main(){
    int n;
    float x[15],x2[15], y[15], x3[15], x4[15], xy[15], x2y[15];
    printf("Enter the value of N: ");
    scanf("%d", &n);
    float sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumX3 = 0.0, sumX4 = 0.0, sumXY = 0.0, sumX2Y = 0.0;
    printf("\nEnter the values of X : \n");
    for(int i=0; i<n; i++){
        scanf("%f", &x[i]);
        x2[i] = x[i]*x[i];
        x3[i] = x2[i]*x[i];
        x4[i] = x3[i]*x[i];
        sumX += x[i];
        sumX2 += x2[i];
        sumX3 += x3[i];
        sumX4 += x4[i];
    }

    printf("\nEnter the values of Y : \n");
    for(int i=0; i<n; i++){
        scanf("%f", &y[i]);
        x2y[i] = x2[i] * y[i];
        xy[i] = x[i] * y[i];
        sumY += y[i];
        sumXY += xy[i];
        sumX2Y += x2y[i];
    }
    
    float D = ( sumX2 * sumX2 * sumX2 + sumX * sumX4 * sumX + n * sumX3 * sumX3 ) - ( sumX2 * sumX * sumX3 + sumX * sumX3 * sumX2 + n * sumX2 * sumX4 );
    float A = ( ( sumX * sumX2 * (-sumXY) + n * sumX2 * (-sumX2Y ) + (-sumY) * sumX * sumX3 ) - ( sumX * sumX * (-sumX2Y) + n * sumX3 * (-sumXY) + (-sumY) * sumX2 * sumX2 ) ) / D;
    float B = ( ( sumX2 * sumX * ( -sumX2Y )+ n * sumX4 * (-sumXY) + (-sumY) * sumX3 * sumX2 ) - ( sumX2 * sumX2 * (-sumXY) + n * sumX3 * (-sumX2Y) + (-sumY) * sumX * sumX4 ) ) / D;
    float C = ( ( sumX2 * sumX3 * (-sumXY) + sumX * sumX3 * (-sumX2Y) + (-sumY) * sumX2 * (sumX4) ) - ( sumX2 * sumX2 * (-sumX2Y) + sumX * (sumX4) * (-sumXY ) + (-sumY) * sumX3 * (sumX3) ) ) / D;


    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
    printf("|\tX\t|\tY\t|\tX2\t|\tX3\t|\tX4\t|\tXY\t|\tX2Y\t|\n");
    for(int i=0; i<n; i++){
        printf("|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\n", x[i], y[i], x2[i], x3[i], x4[i], xy[i], x2y[i]);
    }
    printf("---------------------------------------------------------------------------------------------------------------------\n");


    printf("sumX: %.2f\nsumY: %.2f\nsumXY: %.2f\nsumX2: %.2f\nsumX3: %.2f\nsumX4: %.2f\nsumX2Y: %.2f\n", sumX, sumY, sumXY, sumX2, sumX3, sumX4, sumX2Y);
    printf("Y = ( %.4f ) X^2 + (%.4f) x + (%.4f)    is the required solution.\n", A, B, C );
    
}