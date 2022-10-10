#include <stdio.h>
 /*
 Requires : 
 Two integers which are chosen by the user
 Effect : 
 Returns the hamming distance between the two integers
 */
int hammingdistance(int num1 , int num2);
 
int main(){
 
   int num1;
   int num2;
   printf("Enter first number : ");
   scanf("%d" , &num1);
   printf("\nEnter second number : ");
   scanf("%d" , &num2);
 
   printf("\nThe hamming distance between %d and %d is equal to : %d" , num1 , num2 , hammingdistance(num1, num2));
 
   return 0;
}
 /*
Test Cases : 
Inputs : num1 ___ num2  : Ouput
          0   ___   3   : 2
          1   ___   3   : 1
          0   ___   0   : 0
          -10 ___ -20   : 3
          ab   ___  (doesn't allow the user to put another integer)   : 7
        2,147,483,647 (aka largest integer value) ___  (doesn't allow the user to put another integer) : 2
        -10 ___ 90 : 0
        100 ___ 200 : 4
        20 ___ ab(takes it as 1) : 3
        2.3 --- (desn't take an input) : 2
        5 --- 2.3         : 3
 */
int hammingdistance(int x, int y)
{
   int exclusive_num = x ^ y; //If the aligned bits don't match the 1 is outputed in the exclusive_num , otherwise 0 is outputed
   int z = 0;
   while (exclusive_num  > 0) {
       z += (exclusive_num & 1); //If a bit in exclusive_num is 0, then x and y don't differ in that bit and so the operation (exclusive_num & 1) give 0, otherwise it gives 1
 
       exclusive_num /= 2; //Divide by two inorder to go over the whole exclusive_num bit by bit literally :)
   }
   return z; //Returns the number of different bits
}
