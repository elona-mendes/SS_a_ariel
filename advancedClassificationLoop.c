#include "NumClass.h"
#include <stdio.h>
int isPalindrome(int num){
    int n = num;
    int i, j;
    for(j = 0; n!=0; j++){
        n=n/10;
    }
    n=num;
    int arr[j]; 
    for(i = 0; n!=0; i++){
        arr[i] = n%10;
        n=n/10;
    }
    i = 0;   
    while(i<(j-1)){
        if(arr[i]!= arr[j-1]){
            return 0;
        }
        i+=1;
        j-=1;
    }
    return 1;
}

int isArmstrong(int num){
    int digitNum = 0;
    int n =num;
    for (int i = 0; n !=0; i++){
        digitNum+=1;
        n=n/10;
    }
    int sumAll = 0;
    int powerSum =1;
    n = num;
    for(int i=1; n!=0; i+=1){ //calculate the power for every digit
        for(int j=0; j<digitNum;j+=1){ //calculate the power
            powerSum *= (n%10);
        }
        sumAll+=powerSum;
        n=n/10;
        powerSum = 1;
    }
    if(sumAll==num) return 1;
    return 0;
}