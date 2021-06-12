import java.util.*;

class RankOfCorel{
    static int getMax(int a[], int n){
        int l = a[0];
        int li=0;
        for(int i=0; i<n; i++){
            if(a[i]>=l){
            l = a[i];
            li = i;
            }
        }
        a[li] = '\0';
        return li;
    }
    

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int x[] = new int[15], X[] = new int[15], RX[] = new int[15], y[] = new int[15], Y[] = new int[15], RY[] = new int[15], d[] = new int[15], D[] = new int[15], sumD = 0;
        double p;
        System.out.println("Enter the N: ");
        int n = sc.nextInt();
        System.out.print("Enter the values of X: \n");
        for(int i=0; i<n; i++){
            x[i] = sc.nextInt();
            X[i] = x[i];
        }
        System.out.print("Enter the values of Y: \n");
        for(int j=0; j<n; j++){
            y[j] = sc.nextInt();
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
        System.out.print("\n-------------------------------------------------------------------------------------------------\n");
        System.out.print("|\tx\t|\tRx\t|\ty\t|\tRy\t|\tdi\t|\tdi^2\t|\n");
        for(int i=0; i<n; i++){
        System.out.printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", x[i], RX[i], y[i], RY[i], d[i], D[i]);
        }
        System.out.print("--------------------------------------------------------------------------------------------------\n");
        double a = 6 * sumD, b = (n*n*n) - n;
        p = 1.0 - (a/b);
        System.out.printf("The rank of corelation = %.3f", p);
        sc.close();
    }
}