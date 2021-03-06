#include <stdio.h>  
#include <string.h>  
  
/* 一个数组元素表示 4 个十进制位，即数组是万进制的 */  
#define BIG_RADIX 10000  
#define RADIX_LEN 4  
/* 10000! 有 35660 位 */  
#define MAX_LEN (35660/RADIX_LEN + 1)  
  
int x[MAX_LEN + 1];  
  
void Big_Print(){  
    int i;  
    int start_output = 0;
  
    for (i = MAX_LEN; i >= 0; --i){  
        if (start_output == 1){
            printf("%04d", x[i]);  
        }  
        else if (x[i] > 0){
            printf("%d", x[i]);  
            start_output = 1;  
        }  
    }  
    if (start_output == 0) 
        printf("0");  
}  
  
void Big_Multiple(int y){  
    int i,carry = 0,tmp;  
    for (i = 0; i < MAX_LEN; ++i)
    {  
        tmp = x[i] * y + carry;  
        x[i] = tmp % BIG_RADIX;  
        carry = tmp / BIG_RADIX;  
    }  
}  

void Big_Factorial(int N){  
    int i; 
    memset(x, 0, sizeof(x));  
    x[0] = 1;  
    for (i = 2; i <= N; ++i){  
        Big_Multiple(i);  
    }  
}  
  
int main(void){  
    int N;  
    while (~scanf("%d", &N)){  
        Big_Factorial(N);  
        Big_Print();  
        printf("\n");  
    }  
}  

