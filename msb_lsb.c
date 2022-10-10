#include <stdio.h>

/*
Test Cases : Inputs                 Outputs
                9                      3
                2                      0
                0                      ask for another input
                -1                      ask for another input
                10                      2
                1.5
*/



/*
Requires : 
positive integer which is entered by the user

Effects : 
Returns the position of the most significant bit
*/
int msb(unsigned int num);

/*
Requires : 
positive integer which is entered by the user

Effects : 
Returns the position of the least significant bit
*/
int lsb(unsigned int num);

const int NUMBER_OF_INTEGER_BITS = 32;

int main(){
    int num;
    printf("Enter a poistive integer : ");
    scanf("%d" , &num);
    while(num <= 0){
        printf("Invalid input. Enter a poistive integer : ");
        scanf("%d" , &num);
    }
    int x = msb(num);
    int y = lsb(num);

    printf("The distance between the first and last bits is %d" , x-y);
    return 0;
}

int msb(unsigned int num){
    int k = 0;

    while (num) {  // while num is not 0 keep shifting num to the right by 1 to find the msb
        k++;
        num *= 2; // shifting to the right y 1 is equivalent to multiplying by 2 power 1
    }

    return k - 1; // subtract 1 because its 0 indexed

}

int lsb(unsigned int num){
    int k = NUMBER_OF_INTEGER_BITS;

    while(num){
        k--;
        num /= 2;//shift to the left by 1 bit through dividing by 2 
    }
    return k;
}
