import java.util.*;

class Rank{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the N: ");
        int n = sc.nextInt();
        int x[] = new int[n], y[] = new int[n], d[] = new int[n], D[] = new int[n];
        System.out.println("Enter the values of X: \n");
        for(int i=0; i<n; i++){
            x[i] = sc.nextInt();
        }
        System.out.println("Enter the values of Y: \n");
        for(int j=0; j<n; j++){
            y[j] = sc.nextInt();
        }
        int sumD = 0;
        for(int i=0; i<n; i++){
            d[i] = x[i] - y[i];
            D[i] = d[i]*d[i];
            sumD += D[i];
        }
        double a = 6 * sumD, b = (n*n*n) - n;
        double p = 1.0 - (a/b);
        System.out.printf("The rank of corelation = %.3f", p);
    }
}