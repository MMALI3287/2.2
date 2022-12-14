#include <bits/stdc++.h>
using namespace std;

float functionEvaluate(float x)
{
    return 2 * x * x * x * x - 2 * x * x * x - 3 * x - 2;
}

int main()
{
    float a = -1.0, b = 1.0001, c = 0.0, prev = 0, count = 1;
    if (functionEvaluate(a) * functionEvaluate(b) > 0)
    {
        printf("There is no root for the function between %d and %d\n", a, b);
    }
    else
    {

        cout << "------------------------------------------------------------" << endl;
        cout << "|"
             << "Iterations"
             << "|"
             << "Approximate Root"
             << "|"
             << "Absolute Error"
             << "|"
             << "Relative Error"
             << "|" << endl;
        cout << "------------------------------------------------------------" << endl;
        do
        {
            prev = c;
            c = (a * functionEvaluate(b) - b * functionEvaluate(a)) / (functionEvaluate(b) - functionEvaluate(a));
            if (functionEvaluate(c) == 0.0)
            {
                break;
            }
            else if (functionEvaluate(c) * functionEvaluate(a) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
            // cout << "|  " << count << "  |  " << c << "  |  " << fabs(c - prev) << "  |  " << fabs((c - prev) / c) << "  |" << endl;
            printf("|   %0.0f     |    %0.6f   |   %0.6f   |    %0.6f   |\n", count, c, fabs(c - prev), fabs((c - prev) / c));
            count++;
            cout << "------------------------------------------------------------" << endl;
        } while (fabs(prev - c) > 0.00001);
    }
    cout << "The root of the function is: " << c << endl;
    return 0;
}