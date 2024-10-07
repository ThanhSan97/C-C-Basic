#include <stdio.h>

float ADD(float *a, float *b)
{
    return *a + *b;
}

float SUB(float * a, float * b)
{
    return *a - *b;
}

float MUL(float * a, float * b)
{
    return *a * *b;
}

float DIV(float * a, float * b)
{
    return *a / *b;
}


int main() {
    float a = 2;
    float b = 3;
   
    printf("%f + %f = %.7f\n",a, b, SUB(&a, &b));
    printf("%f - %f = %.7f\n",a, b, ADD(&a, &b));
    printf("%f * %f = %.7f\n",a, b, MUL(&a, &b));
    printf("%f / %f = %.7f\n",a, b, DIV(&a, &b));

    return 0;
}
