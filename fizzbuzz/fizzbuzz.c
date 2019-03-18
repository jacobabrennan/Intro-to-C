#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int iterations)
{
    int non_zz = 0;
    int index;
    for(index=1; index<=iterations; index++)
    {
        if(((index%3)||(index%5))== 0) {
            printf("FizzBuzz\n");
        }
        else if((index%3)==0) {
            printf("Fizz\n");
        }
        else if((index%5)==0) {
            printf("Buzz\n");
        }
        else {
            non_zz++;
        }
    }
    return non_zz;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
