#include <stdio.h>

unsigned long long combination(unsigned long long n, unsigned long long k) {
  if (k > n)
    return 0;

  if(k > n - k)
    k = n - k;

  unsigned long long res = 1;

  for(unsigned long long i = 1; i <= k; i++) {
    res *= n--;
    res /= i;
  }

  return res;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T > 0) {

      unsigned long long n, k;

      scanf("%llu", &n);
      scanf(" %llu", &k);

      printf("%llu\n", combination(--n, --k));

      T--;
    }

    return 0;
}
