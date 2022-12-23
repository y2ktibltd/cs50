#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_len(int long a)
{
    int len;
    int long tmp = a;
    for (len = 0; tmp > 0; tmp /= 10)
    {
        len++;
    }
    return len;
}

void convert_to_array(int long a, int ary[])
{
    int len = get_len(a), i;
    for (i = len - 1; i >= 0; i--)
    {
        ary[i] = a % 10;
        a = a / 10;
    }
}

char *check_brand(int a, int b, int len)
{
    if (((a == 3 && b == 4) || (a == 3 && b == 7)) && len == 15)
    {
        return "AMEX";
    }
    if ((a == 5) && (b == 1 || b == 2 || b == 3 || b == 4 || b == 5) && len == 16)
    {
        return "MASTERCARD";
    }
    if ((a == 4) && (len == 13 || len == 16))
    {
        return "VISA";
    }
    return "INVALID";
}

bool check_digit(int ary[], int len)
{
    int i, j, sum1 = 0, sum2 = 0, total = 0;
    //printf("Check_Digit function return array len(%d)\n: ",len);
    //printf("\n");
    for (i = len - 1, j = 0 ; i >= 0 ; i--, j++)
    {
        if (j % 2 == 0)
        {
            //printf("J is even, ary[%d]\t",ary[i]);
            //printf("%d+%d=",sum1,ary[i]);
            sum1 += ary[i];
            //printf("%d\n",sum1);
        }
        if (j % 2 != 0)
        {
            //printf("J is odd, ary[%d]\t",ary[i]);
            //printf("%d+%d*2=",sum2,ary[i]);
            if ((ary[i]) > 4)
            {
                sum2 += (2 * ary[i]) - 9;

            }
            else
            {
                sum2 += (ary[i] * 2);
            }
            //printf("%d\n",sum2);
        }
    }
    //printf("add total %d\n",sum1);
    //printf("multiply total %d\n",sum2);
    total = sum1 + sum2; //(sum2/10)+(sum2%10);
    //printf("total =: %d\n",total);
    return total % 10;
}

int main(void)
{
    long int cc;
    printf("Number: ");
    scanf("%ld", &cc);
    int len = get_len(cc);
    int ary[len];
    convert_to_array(cc, ary);
    char *brand = check_brand(ary[0], ary[1], len);
    //printf("%s\n",brand);
    if (strcmp(brand, "INVALID") != 0)
    {
        bool valid = check_digit(ary, len);
        if (!valid)
        {
            printf("%s\n", brand);
            return 0;
        }
    }
    printf("INVALID\n");
}
