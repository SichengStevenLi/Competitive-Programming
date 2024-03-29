#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int isPerfectSquare(int n)
{
    int h = n & 0xF;
    if (h > 9)
        return 0;
    // Use lazy evaluation
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        int t = (int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return false;
}

int isPrime(int n){
    
  int i, isPrime = 1;
  
  if (n <= 1){
    isPrime = 0;
  }

  for ( i = 2 ; i <= n/2 ; i++)
  {
    if (n % i == 0)
    {
      isPrime = 0;
      break;
    }
  }
  if (isPrime == 1)
    return true;
  else
    return false ;

  return 0;
}


int main(){
    int n, m;
    scanf("%d", &n);
    
    //std::vector<int> num(n);

    for (int i = 0; i < n; i++){
        scanf("%d", &m);
        if (isPerfectSquare(m)){
            if (isPrime(sqrt(m))){
                printf("YES\n");
            }
            else printf("NO\n");
        }
        else{
            printf("NO\n");
        }
    }
}

