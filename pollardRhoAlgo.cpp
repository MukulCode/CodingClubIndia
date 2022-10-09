#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//function to find the power of two numbers
ll power(ll b, int e, ll m)
{
	//initialize answer
	ll answer = 1;

	while (e > 0)
	{
		//if n is odd, multiply b with answer
		if (e % 2 == 1)
			answer = (answer * b) % m;

		e = e/2;
		b = (b * b) % m;
	}
	return answer;
}

//method to return prime divisor for n
ll pollRh(ll n)
{
	//initialize random seed
	srand (time(NULL));

	//no prime divisor for 1
	if (n==1) return n;

	//even number means one of the divisors is 2
	if (n % 2 == 0) return 2;

	//we will pick from the range [2, N)
	ll x = (rand()%(n-2))+2;
	ll y = x;

	//the constant in f(x).
	//Algorithm can be re-run with a different a
	//if it throws failure for a composite.
	ll a = (rand()%(n-1))+1;

	ll d = 1;

	//until the prime factor isn't obtained.
	//If n is prime, return n
	while (d==1)
	{
		//second person move x(i+1)=fx(i))
		x = (power(x, 2, n) + a + n)%n;

		//first person move y(i+1) = f(f(y(i)))
		y = (power(y, 2, n) + a + n)%n;
		y = (power(y, 2, n) + a + n)%n;

		//check gcd of |x-y| and n
		d = __gcd(abs(x-y), n);

		// retry if the algorithm fails to find prime factor with chosen x and a
		if (d==n) return pollRh(n);
	}

	return d;
}


int main(void)
{
	ll n = 91;
	cout<<"One of the divisor is"<<" "<<pollRh(n);
	return 0;
}
