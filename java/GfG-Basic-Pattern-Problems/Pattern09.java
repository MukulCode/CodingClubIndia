import java.util.Scanner;

public class Pattern9 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        int space = n-1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= space ; j++) {
                System.out.print(" ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print("*" + " ");
            }
            space--;
            System.out.println();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= space+1 ; j++) {
                System.out.print(" ");
            }
            for (int j = n; j >= i; j--) {
                System.out.print("*" + " ");
            }
            space++;
            System.out.println();
        }

    }
}
