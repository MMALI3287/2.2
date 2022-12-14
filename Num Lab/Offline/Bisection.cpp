#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
float f(float x)
{
    return x * x - 4 * x - 10;
}
int main()
{
    float count = 1;
    float a, b, c = 0.0, prev, error;
    cout << "Enter the value of a and b: ";
    cin >> a >> b;
    if (f(a) * f(b) > 0)
    {
        printf("No root found between %f and %f b", a, b);
    }
    else
    {
        do
        {
            prev = c;
            c = (a + b) / 2;
            if (f(c) == 0)
                break;
            else if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;
            count++;
            printf("Number of count is %f\t", count);
            printf("Root is %f\t", c);
            float error = fabs(f(c)) - fabs(f(prev));
            printf("The value of error %f\t", error);
            printf("\n");
        } while (fabs((c - prev)) > 0.002);
    }
    return 0;
}