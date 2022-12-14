#include <bits/stdc++.h>
using namespace std;
double fx(int func[], int n, double x)
{
    double result = func[n];
    for (int i = n - 1; i >= 0; i--)
    {
        result = result * x + func[i];
    }
    return result;
}
int main()
{
    cout << "Secant Method" << endl;
    int n;
    double x0;
    double x1;
    double x2;
    double prev;
    double fx0;
    double fx1;
    double fPrimeX;
    int itr = 0;
    cout << "Input the value of x0: ";
    cin >> x0;
    cout << "Input the value of x1: ";
    cin >> x1;
    cout << "Enter the degree of the equation: ";
    cin >> n;
    int poly[n + 1];
    int der[n];
    for (int i = 0; i <= n; i++)
    {
        cout << "Input the coefficient of x^" << i << " of the polynomial: ";
        cin >> poly[i];
    }
    cout << "INITIAL Approximation for Secant Method \t x1---->" << x1 << "\tx0--->" << x0 << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Iteration \t Current Root \t Previous Root \t Absolute Error" << endl;
    cout << "---------------------------------------------------------------" << endl;
    do
    {
        fx0 = fx(poly, n, x0);
        fx1 = fx(poly, n, x1);
        if (fx1 == 0.00)
        {
            cout << "Root Found" << endl;
            x2 = x1;
            break;
        }
        prev = x1;
        x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
        x0 = x1;
        x1 = x2;
        itr++;
        printf("  %d \t  \t %.4f \t  %.4f \t  %.4f\n", itr, x2, prev, fabs(x2 - prev));
    } while (fabs(x2 - prev) > 0.00001);
    cout << "Root found in Secant Method: " << x2 << endl;
    cout << "<-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><->" << endl;
    cout << "Newton Raphson Method" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Input the coefficient of x^" << i << " of the derivative: ";
        cin >> der[i];
    }
    itr = 0;
    cout << "Input the value of x0: ";
    cin >> x0;
    cout << "INITIAL Approximation for Newton Raphson Method \t x0--->" << x0 << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Iteration \t Current Root \t Previous Root \t Absolute Error" << endl;
    cout << "---------------------------------------------------------------" << endl;
    do
    {
        prev = x0;
        fx0 = fx(poly, n, x0);
        if (fx0 == 0.0)
        {
            cout << "Root Found" << endl;
            x1 = x0;
        }
        fPrimeX = fx(der, n - 1, x0);
        if (fPrimeX == 0.0)
        {
            cout << "Calculation error" << endl;
            break;
        }
        x1 = x0 - (fx0 / fPrimeX);
        x0 = x1;
        itr++;
        printf("  %d \t \t  %.4f \t  %.4f \t  %.4f\n", itr, x1, prev, fabs(x1 - prev));
    } while (fabs(x1 - prev) > 0.00001);
    cout << "Root found in Newton Raphson Method: " << x1 << endl;
    return 0;
}
