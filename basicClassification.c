#include "NumClass.h"
#include <stdio.h>

int isPrime(int num){

    if (num == 2) return 1;
    if (num%2 ==0) return 0;
    // otherwise see if divisible by anything
    int i=3;
    while (i*i <= num){
        if (num%i == 0) {
            return 0;
    }
        i++;
    }
    return 1;
}

int isStrong(int num){
    int sumMult = 1;
    int sumAll = 0; 
    int n = num;
    int lastNum = num%10;
    while(n!=0){
     for(int i=1; i<=lastNum; i++){
          sumMult*=i; 
        }
        n = n/10;
        lastNum=n%10;
        sumAll = sumAll + sumMult;
        sumMult=1;
    }
    if(sumAll==num) return 1;
    return 0;
}
