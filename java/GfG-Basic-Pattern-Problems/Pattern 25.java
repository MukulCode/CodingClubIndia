import java.util.*;

public class Main{

public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n=scn.nextInt();
     // write ur code here
     
     int st=n;
     int sp=0;
     
     for(int i=1;i<=n;i++){
         for(int j=1;j<=sp;j++){
             System.out.print("\t");
         }
         for(int j=1;j<=st;j++){
             if(i>1 && i<=n/2 && j>1 && j<st){
                System.out.print("\t"); 
             }else{
                System.out.print("*\t");
             }
         }
         if(i<=n/2){
             st-=2;
             sp++;
         }else{
             st+=2;
             sp--;
         }
         System.out.println();
     }

 }
}
