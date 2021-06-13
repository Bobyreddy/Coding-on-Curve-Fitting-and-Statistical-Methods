import java.util.*;

class YAeBx {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double x[] = new double[15], y[] = new double[15], x2[] = new double[15], xy[] = new double[15], d[] = new double[4],a, b, Y[] = new double[15], A ;
        System.out.print("Enter the value of N: ");
        int n = sc.nextInt();
        double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumXY = 0.0;
        System.out.println("\nEnter the values of X : \n");
        for(int i=0; i<n; i++){
            x[i] = sc.nextDouble();
            x2[i] = x[i]*x[i];
            sumX += x[i];
            sumX2 += x2[i];
        }

        System.out.print("\nEnter the values of Y : \n");
        for(int i=0; i<n; i++){
            y[i] = sc.nextDouble();
            Y[i] = Math.log(y[i]);
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

        A = Math.exp(a);


        System.out.println("\n-----------------------------------------------------------------------\n");
        System.out.println("|\tx\t|\ty\t|\tY=logy\t|\txY\t|\tx2\t|\n");
        for(int i=0; i<n; i++){
            System.out.printf("|\t%.2f\t|\t%.2f\t|\t%.4f\t|\t%.4f\t|\t%.2f\t|\n", x[i], y[i], Y[i], x2[i], xy[i]);
        }
        System.out.print("-----------------------------------------------------------------------\n");


        System.out.printf("sumX: %.2f\nsumY: %.2f\nsumXY: %.2f\nsumX2: %.2f\n", sumX, sumY, sumXY, sumX2);
        System.out.printf("Y = %.4f e ^ %.4f x   is the required solution.\n", A, b );
        sc.close();
    }
}
