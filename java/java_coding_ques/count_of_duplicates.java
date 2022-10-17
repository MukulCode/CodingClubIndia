public class count_of_duplicates
{
	public static void main(String[] args) {
	int ar[]={10,20,40,60,20,80};
	
//	int temp[] = new int[ar.length];
//	int k= 0;
	int count=0;
	for(int i=0;i<ar.length-1;i++)
	{
	    for(int j=i+1;j<ar.length-1;j++)
	    {
	        if(ar[i]==ar[j])
	        {
	            count++;
	            System.out.println(count);
	            i++;
	        }
	        
	    }
	    //temp[k++]=ar[ar.length-1];
    }
    
}
}