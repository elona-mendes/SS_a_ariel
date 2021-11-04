#include <stdio.h>
#include "NumClass.h"
int main(){
    int num1;
    int num2;
    scanf("%d %d", &num1, &num2);
    int max;
    int min;
    if(num1>=num2){
        max=num1;
        min=num2;
    }
    else{
        max=num2;
        min=num1;
    }

    int i = min;
    printf("The Armstrong numbers are:");
    for(; i<=max; i++){
        if(isArmstrong(i)==1){
            printf(" %d", i);
        }
    }
    i=min;
    printf("\nThe Palindromes are:"); 
    for(; i<=max; i++){
        if(isPalindrome(i)==1){
            printf(" %d", i);
        }
    }
    i=min;
    printf("\nThe Prime numbers are:"); 
    for(; i<=max; i++){
        if(isPrime(i)==1){
            printf(" %d", i);
        }
    }
    i=min;
    printf("\nThe Strong numbers are:"); 
    for(; i<=max; i++){
        if(isStrong(i)==1){
            printf(" %d", i);
        }
    }
    printf("\n"); 
}
