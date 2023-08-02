#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 100


int coinChange(int* coins, int coinsSize, int amount){
    int *dp = (int *)malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) dp[i] = INT_MAX - 1;
    for (int i = 1; i <= amount; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < coinsSize; j++)
        {
            if (i - coins[j] >= 0)
            {
                if (min > dp[i - coins[j]])
                {
                    min = dp[i - coins[j]];
                }
            }
        }
        if (min != INT_MAX)
            dp[i] = min + 1;
    }
    int result;
    if(dp[amount] >= INT_MAX - 1){
        return -1;
    } else {
        result = dp[amount];
    }
    free(dp);  
    return result;
}

int main(){
    int size;
    printf("Enter the number of coins: \n");
    scanf("%d", &size);
    int coins[size];
    printf("Coins: \n");
    for (int i = 0; i < size; i++){
        scanf("%d", &coins[i]);
    }
    int amount;
    printf("Amount: \n");
    scanf("%d", &amount);

    printf("Answer: \n");
    int answer = coinChange(coins, size, amount);
    printf("%d", answer);
    return 0;
}