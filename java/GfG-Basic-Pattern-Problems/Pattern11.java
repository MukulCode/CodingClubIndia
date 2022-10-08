import java.util.Scanner;

public class Pattern11 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        int a = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(a + " ");
                a = 1 - a;
            }
            a = (i-1)%2;
            System.out.println();
        }
    }
}
