#include <stdio.h>
#include <algorithm>
#include <vector>

int k, least; 
long *dp_meet_table; 
long *dp_nomeet_table; 
//long *dp_table; 

long dp(int sum, bool least_meet)
{
    long local_sum = 0;
    int possible_choices = std::min(k,sum);

    if (sum == 0){
        if(least_meet) return 1; 
        return 0;
   }

    if (least_meet){
        if (dp_meet_table[sum] != -1) return dp_meet_table[sum]; 
    } else {
        if (dp_nomeet_table[sum] != -1) return dp_nomeet_table[sum];  
    }
    
    for (int i=1; i<=possible_choices; i++) {  
        local_sum += dp(sum -i, least_meet | (i>= least))% 1000000007; 
        local_sum = local_sum % 1000000007;
    }
    
    if (least_meet){
        dp_meet_table[sum] = local_sum;
    } else {
        dp_nomeet_table[sum] = local_sum;
    }

    return local_sum; 
}


int main() {
    int sum;
    long result;
    
    // Using scanf to read three integers
    scanf("%d %d %d", &sum, &k, &least);

  /*
    dp_table = (long*) malloc((sum+1) * sizeof(long) * 2);
    for (int i=0; i<(sum+1)*2; i++) {
        dp_table[i]=-1;
    }
  */
  
    dp_meet_table = (long*) malloc((sum+1) * sizeof(long));
    dp_nomeet_table = (long*) malloc((sum+1) * sizeof(long));
    for (int i=0; i<sum+1; i++) {
        dp_nomeet_table[i]=-1;
        dp_meet_table[i]=-1;
    }
    
    result = dp(sum, false);
    result = result % 1000000007; 
    
    // Printing the values entered
    printf("%d\n", (int) result);
    
    return 0;
}
