#include "NumClass.h"
#include <stdio.h>

int powerAr(int num, int digit);
int reverse(int num);

int isPalindrome(int num){
    if(num == reverse(num))
        return 1;
    return 0;
}
//reverse num to compare with original number
int reverse(int num)
{   
    if(num == 0){
        return 0;
    }
    int digit=1;
    int n = num/10;
    while(n!=0){
        n=n/10;
        digit*=10;
    }
    return ((num%10*digit) + reverse(num/10));
}

int isArmstrong(int num){
    int digitNum = 0;
    int n =num;
    for (int i = 0; n !=0; i++){
        digitNum+=1;
        n=n/10;
    }
    n = num;
    int numAfterPowers = powerAr(n, digitNum); //send to recursion function
    if(numAfterPowers==num) return 1;
    else return 0;
}

int powerAr(int num, int digit){
    if(num == 0) return 0; 
    else {
        int powerSum = 1;
        int n = num%10;
        for(int j=0; j<digit;j+=1){ //calculate the power
            powerSum *= n;
        }
        return (powerSum + powerAr(num/10, digit));
    }
}
