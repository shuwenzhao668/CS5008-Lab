#include <stdio.h>

int f(int n) {
    if(n == 1) return 1;
    else return n * f(n-1);
}


int main() {
    int input;
    printf("Input the number for factorial calculation:");
    scanf("%d", &input);

    int output;
    output = f(input);
    printf("The factorial is %d\n", output);

    return 0;
}