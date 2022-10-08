import java.util.Scanner;

public class Pattern12 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j <= i) {
                    System.out.print(j + " ");
                } else {
                    System.out.print("  ");
                }
            }
            for (int j = n; j >= 1; j--) {
                if (j > i) {
                    System.out.print("  ");
                } else {
                    System.out.print(j + " ");
                }
            }
            System.out.println();
        }
    }
}
