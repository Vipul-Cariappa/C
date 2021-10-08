#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* WORDS[] = {
    "",         "one",      "two",      "three",   "four",    "five",
    "six",      "seven",    "eight",    "nine",    "ten",     "eleven",
    "twelve",   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen", "twenty",   "",        "",        "thirty",
    "forty",    "fifty",    "sixty",    "seventy", "eighty",  "ninety",
    "hundred",  "thousand", "and"};

int get_size(int number)
{
    int digit = 0, copy = number, place = 1;
    int size = 0;
    int and_flag = 0;

    while (copy)
    {
        if (place == 1)
        {
            digit = copy % 100;
            copy = copy / 100;

            if (digit <= 20)
            {
                size += strlen(WORDS[digit]);
            }
            else
            {
                int digit_copy = digit;
                int once_place = digit_copy % 10;
                digit_copy = digit_copy / 10;
                int tens_place = digit_copy % 10;
                if (tens_place)
                {
                    size += strlen(WORDS[tens_place + 20]);
                    and_flag = 1;
                }
                else if (once_place)
                {
                    and_flag = 1;
                }
                size += strlen(WORDS[once_place]);
            }

            place++;
        }
        if (place == 3)
        {
            digit = copy % 10;
            copy = copy / 10;

            size += strlen(WORDS[digit]);
            size += strlen("hundred");
            if (and_flag)
            {
                size += strlen("and");
            }
        }
        if (place == 4)
        {
            digit = copy % 10;
            copy = copy / 10;

            size += strlen(WORDS[digit]);
            size += strlen("thousand");
        }

        place++;
    }

    return size;
}

int main(int argc, char* argv[])
{
    int number;
    if (argc == 2)
    {
        number = atoi(argv[1]);
    }
    else
    {
        printf("Usage: %s <number>\n", argv[0]);
        exit(-1);
    }

    long sum = get_size(1000);
    // long sum = 0;

    // for (int i = 1; i <= number; i++)
    // {
    //     sum += get_size(i);
    // }

    printf("Count Size: %li\n", sum);
    return 0;
}
