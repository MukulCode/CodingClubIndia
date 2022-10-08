import java.util.Scanner;

public class Pattern15 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        for (int i = 1; i <= n; i++) {
            int a = 65;
            for (int j = n; j >= i; j--) {
                System.out.print((char)a);
                a++;
            }
            System.out.println();
        }
    }
}
