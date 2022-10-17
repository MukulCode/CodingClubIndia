public class Main
{
    static void carray(int a[],int b[], int c[])
	{
		for(int i=0;i<a.length;i++)
		{
		    c[i]=a[i];
		    //i++;
		   //System.out.print( "  " +  c[i]);
		    //System.out.print("\n");
		    
		for(int j=0;j<b.length;j++)
		{
		   c[a.length + j ]=b[j];
		   //System.out.print("  " + c[j]);
		    //System.out.print("\n");
		   //i++;
		}
		
		
		}
		for(int k=0;k<c.length;k++)
		
		{
		    System.out.print( "  " + c[k]);
		}
}
		
		public static void main(String[] args) {
	    
		int a[]= {1,4 ,6};
		int b[]= {3 ,5,9,8,6};
		int c[]=new int[a.length+b.length];
		
		
		 carray( a,  b, c);
		
	}
}