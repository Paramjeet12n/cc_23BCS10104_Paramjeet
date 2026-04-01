import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long S = sc.nextLong();
        long[] a = new long[n];
        for (int i=0;i<n; i++) {
            a[i]=sc.nextLong();
        }
        int s = 0, e = n;
        int bk = 0;
        long bc = 0;
        while (s<=e) {
            int k = s+(-s+e) / 2;
            long[] cost = new long[n];
            for (int i=0; i<n; i++) {
                cost[i]=a[i]+(long)(i+1)*k;
            }
            Arrays.sort(cost);
            long sum = 0;
            for (int i=0; i<k; i++) {
                sum+=cost[i];
            }
            if (sum<=S) {
                bk=k;
                bc=sum;
                s=k + 1;
            } else {
                e=k-1;
            }
        }
 
        System.out.println(bk+" "+bc);
    }
}