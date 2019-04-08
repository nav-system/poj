#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "lib.h"

#define INPUT_SIZE 6

result_t char_num_shift_left(char* input, int input_size, int shift,
        char* result, int* result_size)
{
    *result_size = input_size + shift;
    result = (char*) calloc(*result_size, sizeof(char));
    if (result == NULL)
    {
        return 1;
    }
    memcpy(result, input, input_size);
    return 0;
}

result_t char_num_shift_right(char* input, int input_size, int shift,
        char* result, int* result_size)
{
    if (input_size < shift)
    {
        return 1;
    }
    *result_size = input_size - shift;
    result = (char*) calloc(*result_size, sizeof(char));
    if (result == NULL)
    {
        return 1;
    }
    memcpy(result, input, *result_size);
    return 0;
}

result_t char_num_sum(char* input_1, int input_1_size,
        char* input_2, int input_2_size,
        char* result, int* result_size)
{
    *result_size = (input_1_size > input_2_size)?input_1_size + 1:input_2_size + 1;
    result = (char*) calloc(*result_size, sizeof(char));
    if (result == NULL)
    {
        return 1;
    }

    int i, j;
    int carry = 0;
    for (i = input_1_size - 1, j = input_2_size - 1; i >= 0 && j >= 0; i --, j--)
    {
        result[i+1] = INT_TO_CHAR((carry + CHAR_TO_INT(input_1[i]) + CHAR_TO_INT(input_2[i]) % 10 ));
        carry = (carry + CHAR_TO_INT(input_1[i]) + CHAR_TO_INT(input_2[i])) / 10;
    }
    for (;i >= 0; i--)
    {
        result[i+1] = INT_TO_CHAR((carry + CHAR_TO_INT(input_1[i])) % 10);
        carry = (carry + CHAR_TO_INT(input_1[i]))/ 10;
    }
    for (;j >= 0; i--)
    {
        result[j+1] = INT_TO_CHAR((carry + CHAR_TO_INT(input_1[j])) % 10);
        carry = (carry + CHAR_TO_INT(input_1[j]))/ 10;
    }
    result [i] = INT_TO_CHAR(carry);

    if (result[0] == '0')
    {
        /* cause mem leak, but make it fast */
        result += 1;
        *result_size -= 1;
    }
    return 0;
}

void char_multiple (char* input_1, int input_1_size,
        char* input_2, int input_2_size,
        char* result, int* result_size)
{

}

int main()
{
    char num[INPUT_SIZE] = {0};
    int times = 0;
    while(scanf("%s%d",num,&times)==2)
    {
        printf ("original input %s %d\n", num, times);

        uint64_t num_without_point = 0;
        int num_before_point = 0;
        int num_after_point = 0;

        /* convert into num and write down where point is*/
        int i;
        for (i = 0; i < INPUT_SIZE; i ++)
        {
            if (num[i] != '.')
            {
                num_without_point = num_without_point*10 + CHAR_TO_INT(num[i]);
            }
            else{
                num_before_point = i;
            }
        }
        num_after_point = INPUT_SIZE - 1 - num_before_point;

        printf ("num %lld\n", num_without_point);
        printf ("times %d\n", times);
        printf ("num before point %d\n", num_before_point);
        printf ("num after point %d\n", num_after_point);

#if 0 //code need refactor cause of overflow
        /* result in num without point*/
        uint64_t result = 1;
        for (i = 0; i < times; i++)
        {
            result *= num_without_point;
        }
        printf ("result %lld\n", result);

        /* convert num into char in reserve order*/
        char result_char_reserve[1024];
        int result_num;
        for (i = 0; i < 1024 && result != 0; i ++)
        {
            if (i == times * num_after_point)
            {
                result_char_reserve[i] = '.';
                continue;
            }
            result_char_reserve[i] = result % 10 + '0';
            result /= 10;
        }
        result_num = i;

        /* print*/
        for (i = result_num - 1; i >= 0; i --){
             printf ("%c", result_char_reserve[i]);
        }
        printf("\n");
#endif
    }

    return 0;
}
