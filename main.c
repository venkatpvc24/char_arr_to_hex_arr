#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IS_ALPHA(c) (isupper(c) ? 'A' - 10 : 'a' - 10)
#define TO_INT(c) (c - '0')

#ifndef SIZE
    #define SIZE 100
#endif

void chrarr_to_hexarr( unsigned char* data, size_t len, unsigned char out[SIZE][5])
{
    
    unsigned char* arr;
    int n = 0;

    if (len % 2 == 0) 
    {
        arr = data;
    }
    else
    {   
        arr = (unsigned char*)malloc(sizeof *arr * len + 1);
        memcpy(arr, data, len);
        arr[len] = '0';
    }
    for (int i = 0, j = 1; i < len; i += 2, j += 2)
    {
        
        unsigned int i1 = TO_INT(arr[i]), i2 = TO_INT(arr[j]);

        unsigned int a1 = i1 <= 9  ? i1 : (arr[i] - IS_ALPHA(arr[i]));
        unsigned int a2 = i2 <= 9  ? i2 : (arr[j] - IS_ALPHA(arr[j]));

        unsigned val = (a1 << 4) + a2;

        char hex[5];
        sprintf(hex, "0x%02x", val);
        hex[4] = '\0';
        memcpy(out[n++], hex, 5);
    }

}

int main()
{
    
    printf("%d\n", SIZE);
    unsigned char arr[] = "400004a005b20";
    unsigned char out[SIZE][5];
    int len = strlen((const char*)arr);
    chrarr_to_hexarr(arr, len, out);

    for (int i = 0; i < 7; i++) printf("%s\n", out[i]);

}
