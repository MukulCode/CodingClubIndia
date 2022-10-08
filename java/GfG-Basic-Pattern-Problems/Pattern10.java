import java.util.Scanner;

public class Pattern10 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("*" + " ");
            }
            System.out.println();
        }
        for (int i = 1; i <= n-1; i++) {
            for (int j = n-1; j >= i; j--) {
                System.out.print("*" + " ");
            }
            System.out.println();
        }

    }
}
