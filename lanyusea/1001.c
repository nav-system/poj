#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

#define INPUT_SIZE 6

result_t char_num_shift_left(char* input, int input_size, int shift,
        char** result, int* result_size)
{
    int temp_size = input_size + shift;
    char *temp = (char*) calloc(temp_size, sizeof(char));
    if (temp == NULL)
    {
        return ERR_FAILURE;
    }
    memcpy(temp, input, input_size);
    memset(temp + input_size, '0', shift);
    *result = temp;
    *result_size = temp_size;
    return SUCCESS;
}

result_t char_num_shift_right(char* input, int input_size, int shift,
        char** result, int* result_size)
{
    if (input_size < shift)
    {
        return ERR_FAILURE;
    }
    int temp_size = input_size - shift;
    char *temp = (char*) calloc(temp_size, sizeof(char));
    if (temp == NULL)
    {
        return ERR_FAILURE;
    }
    memcpy(temp, input, temp_size);
    *result = temp;
    *result_size = temp_size;
    return SUCCESS;
}

result_t char_num_sum(char* input_1, int input_1_size,
        char* input_2, int input_2_size,
        char** result, int* result_size)
{
    int temp_size = (input_1_size > input_2_size)?input_1_size + 1:input_2_size + 1;
    char *temp = (char*) calloc(temp_size, sizeof(char));
    if (temp == NULL)
    {
        return ERR_FAILURE;
    }
    DEBUG_INFO("add %s, %s\n", input_1, input_2);
    DEBUG_INFO("add size %d, %d\n", input_1_size, input_2_size);
    int i, j, k;
    int carry = 0;
    for (i = input_1_size - 1, j = input_2_size - 1, k = temp_size - 1; i >= 0 && j >= 0; i --, j--, k--)
    {
        temp[k] = INT_TO_CHAR((carry + CHAR_TO_INT(input_1[i]) + CHAR_TO_INT(input_2[j]) )% 10 );
        carry = (carry + CHAR_TO_INT(input_1[i]) + CHAR_TO_INT(input_2[j])) / 10;
    }
    for (;i >= 0; i--, k--)
    {
        temp[k] = INT_TO_CHAR((carry + CHAR_TO_INT(input_1[i])) % 10);
        carry = (carry + CHAR_TO_INT(input_1[i]))/ 10;
    }
    for (;j >= 0; j--, k--)
    {
        temp[k] = INT_TO_CHAR((carry + CHAR_TO_INT(input_2[j])) % 10);
        carry = (carry + CHAR_TO_INT(input_2[j]))/ 10;
    }
    temp [k] = INT_TO_CHAR(carry);

    if (temp[0] == '0')
    {
        /* cause mem leak, but make it fast */
        temp += 1;
        temp_size -= 1;
    }
    DEBUG_INFO("sum result %s\n", temp);
    *result = temp;
    *result_size = temp_size;
    return SUCCESS;
}

result_t char_multiple (char* input_1, int input_1_size,
        char* input_2, int input_2_size,
        char** result, int* result_size)
{
    int i,j,k;
    char *result_shift, *result_sum, *result_temp;
    int temp_size = 0, result_size_shift, result_size_sum = 0;
    for (i = input_2_size - 1, j = 0; i >= 0; i --, j ++)
    {
         /* input1 char_num_shift_left */
         char_num_shift_left(input_1, input_1_size, j,
                 &result_shift, &result_size_shift);
         DEBUG_INFO("shift left %dst time %s\n", j, result_shift);
         /* (shifted input1 + shifted input1) for certain times */
         for (k = 0; k < CHAR_TO_INT(input_2[i]); k++)
         {
            DEBUG_INFO("times %d\n", CHAR_TO_INT(input_2[i]));
            DEBUG_INFO("before loop add result %s\n", result_sum);
            char_num_sum(result_sum, result_size_sum,
                    result_shift, result_size_shift,
                    &result_sum, &result_size_sum );
            DEBUG_INFO("loop add result %s\n", result_sum);
         }
         /* write down the result of current shift, then another loop */
         char_num_sum(result_temp, temp_size,
                 result_sum, result_size_sum,
                 &result_temp, &temp_size);
         result_size_shift = 0;
         result_size_sum = 0;
    }
    *result = result_temp;
    *result_size = temp_size;
    return SUCCESS;
}

result_t char_num_power (char* input, int input_size,
        int power_times,
        char** result, int* result_size)
{
    char* result_temp = "1";
    int temp_size = 1;
    int i;
    for (i = 0; i < power_times; i ++)
    {
        char_multiple (input, input_size,
                result_temp, temp_size,
                &result_temp, &temp_size);
        DEBUG_INFO("power %dst square result %s\n", i+1,  result_temp);
    }
    *result = result_temp;
    *result_size = temp_size;
    DEBUG_INFO( "result_temp %s \n",result_temp );
    return SUCCESS;
}

int main()
{
    char num[INPUT_SIZE] = {0};
    char num_char_no_ptr[INPUT_SIZE] = {0};
    int times = 0;
    while(scanf("%s%d",num,&times)==2)
    {
        DEBUG_INFO("original input %s %d\n", num, times);

        long long int num_without_point = 0;
        int num_before_point = 0;
        int num_after_point = 0;
        int num_size = 0;

        /* convert into num and write down where point is*/
        int i, j = 0;
        for (i = 0; i < INPUT_SIZE; i ++)
        {
            if (num[i] != '.')
            {
                num_without_point = num_without_point*10 + CHAR_TO_INT(num[i]);
                num_char_no_ptr[j] = num[i];
                j ++;
            }
            else{
                num_before_point = i;
            }
        }
        num_after_point = INPUT_SIZE - 1 - num_before_point;

        if (num_without_point == 0)
        {
            printf ("0\r\n");
            continue;
        }
        if (times == 0)
        {
            printf ("1\r\n");
            continue;
        }
        if (times == 1)
        {
            printf ("%s\r\n", num);
            continue;
        }
        while (num_char_no_ptr[0] == '0')
        {
            int i;
            for (i = 0; i < INPUT_SIZE - 1; i ++)
            {
                num_char_no_ptr[i] = num_char_no_ptr[i+1];
            }
            num_char_no_ptr[INPUT_SIZE - 1] = '0';
            num_before_point --;
        }
        num_size = num_before_point + num_after_point;
        DEBUG_INFO("num %lld\n", num_without_point);
        DEBUG_INFO("times %d\n", times);
        DEBUG_INFO("num before point %d\n", num_before_point);
        DEBUG_INFO("num after point %d\n", num_after_point);
        DEBUG_INFO("num size %d\n", num_size);

        char* result = NULL;
        int result_size = 0;
        char_num_power(num_char_no_ptr, num_size,
                times,
                &result, &result_size);
        DEBUG_INFO("result %s \n", result);

        int num_after_point_result = times*num_after_point;
        while (result[result_size - 1] == '0')
        {
            result_size -= 1;
            num_after_point_result -= 1;
        }
        /* if num_after_point_result > total num of result; start with 0. then until all number printed
         * if num_after_point_result < total_num of result; print delta num, then point, then the reset
         */
        if (num_after_point_result >= result_size)
        {
            printf(".");
            char *temp = malloc((num_after_point_result - result_size)*sizeof(char));
            memset (temp, '0', (num_after_point_result - result_size));
            printf("%s", temp);
            printf("%s", result);
            printf("\r\n");
        }
        else
        {
            printf("%.*s", result_size - num_after_point_result, result);
            printf(".");
            printf("%.*s", num_after_point_result, result + (result_size - num_after_point_result));
            printf("\r\n");
        }
    }

    return 0;
}
