/*
The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so
*/public class SieveOfEratosthenes {
    static void sieve(int n,boolean[] primes)
    {
        for (int i = 0; i <= n; i++)
        {
            primes[i]=true;                      //first step is to initialize all the values with true
        }
            
        for(int i=2;i*i<=n;i++)
        {
            if(primes[i]==true)                 //if no. @ index is prime then sure its multiples cannot be prime so that is done in nested loop...we are making multiples false as they are not prime.
            {
                for(int j=i*2;j<=n;j+=i)        //initializing is done from j=i*2 means we are starting from the multiples of that no..j will definitely move as j=j+i...as we are concerned with multitples... for example muliples of 2 are 4,6,8...so on at each iterastion +2 is increasing 
                {
                    primes[j]=false;           //simply make all the multiples of that no. false else they cannot be prime very obvious
                }                                                                                               
            }
        }

        for(int i=2;i<=n;i++)
        {
            if(primes[i]==true)
            {
                System.out.print(i + " ");
            }
        }
    }
    
    public static void main(String[] args) {
        int n=50;
        boolean[] primes=new boolean[n+1];              //because we have to include 50 in the boolean array as well..and as the index starts with zero it will just add uptil 39 only...so the size is 1+ the n.
        sieve(n, primes);      
    }
}
