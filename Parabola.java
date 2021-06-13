import java.util.*;

class Parabola {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        double x[] = new double[15], x2[] = new double[15], y[] = new double[15], x3[] = new double[15], x4[] = new double[15], xy[] = new double[15], x2y[] = new double[15];
        System.out.print("Enter the value of N: ");
        int n = sc.nextInt();
        double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumX3 = 0.0, sumX4 = 0.0, sumXY = 0.0, sumX2Y = 0.0;
        System.out.print("\nEnter the values of X : \n");
        for(int i=0; i<n; i++){
            x[i] = sc.nextDouble();
            x2[i] = x[i]*x[i];
            x3[i] = x2[i]*x[i];
            x4[i] = x3[i]*x[i];
            sumX += x[i];
            sumX2 += x2[i];
            sumX3 += x3[i];
            sumX4 += x4[i];
        }

        System.out.print("\nEnter the values of Y : \n");
        for(int i=0; i<n; i++){
            y[i] = sc.nextDouble();
            x2y[i] = x2[i] * y[i];
            xy[i] = x[i] * y[i];
            sumY += y[i];
            sumXY += xy[i];
            sumX2Y += x2y[i];
        }

        double D = ( sumX2 * sumX2 * sumX2 + sumX * sumX4 * sumX + n * sumX3 * sumX3 ) - ( sumX2 * sumX * sumX3 + sumX * sumX3 * sumX2 + n * sumX2 * sumX4 );
        double A = ( ( sumX * sumX2 * (-sumXY) + n * sumX2 * (-sumX2Y ) + (-sumY) * sumX * sumX3 ) - ( sumX * sumX * (-sumX2Y) + n * sumX3 * (-sumXY) + (-sumY) * sumX2 * sumX2 ) ) / D;
        double B = ( ( sumX2 * sumX * ( -sumX2Y )+ n * sumX4 * (-sumXY) + (-sumY) * sumX3 * sumX2 ) - ( sumX2 * sumX2 * (-sumXY) + n * sumX3 * (-sumX2Y) + (-sumY) * sumX * sumX4 ) ) / D;
        double C = ( ( sumX2 * sumX3 * (-sumXY) + sumX * sumX3 * (-sumX2Y) + (-sumY) * sumX2 * (sumX4) ) - ( sumX2 * sumX2 * (-sumX2Y) + sumX * (sumX4) * (-sumXY ) + (-sumY) * sumX3 * (sumX3) ) ) / D;


        System.out.print("\n--------------------------------------------------------------------------------------------------------------------\n");
        System.out.print("|\tX\t|\tY\t|\tX2\t|\tX3\t|\tX4\t|\tXY\t|\tX2Y\t|\n");
        for(int i=0; i<n; i++){
            System.out.printf("|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\n", x[i], y[i], x2[i], x3[i], x4[i], xy[i], x2y[i]);
        }
        System.out.print("---------------------------------------------------------------------------------------------------------------------\n");


        System.out.printf("sumX: %.2f\nsumY: %.2f\nsumXY: %.2f\nsumX2: %.2f\nsumX3: %.2f\nsumX4: %.2f\nsumX2Y: %.2f\n", sumX, sumY, sumXY, sumX2, sumX3, sumX4, sumX2Y);
        System.out.printf("Y = ( %.4f ) X^2 + (%.4f) x + (%.4f)    is the required solution.\n", A, B, C );
        sc.close();
    }    
}
