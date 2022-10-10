import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class ComplimentToDNA
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner  s = new Scanner(System.in);
	    int t=s.nextInt();
	    while(t-->0)
	    {
	        int n=s.nextInt();
	        String str=s.next();
	        String ans="";
	        for(int i=0;i<n;i++)
	        {
	            if(str.charAt(i)=='T'){
	                ans+='A';
	            }
	            else if(str.charAt(i)=='A'){
	                ans+='T';
	            }
	            else if(str.charAt(i)=='G'){
	                ans+='C';
	            }
	            else{
	                ans+='G';
	            }
	        }
	        System.out.println(ans);
	    }
		// your code goes here
	}
}
