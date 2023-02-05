#include <bits/stdc++.h>
using namespace std;

double applyHorners(int func[], int n, double x)
{
    double result = func[n];
    for (int i = n - 1; i >= 0; i--)
    {
        result = result * x + func[i];
    }
    return result;
}
void modifiedBisection(int poly[], int n, double Xlower, double Xupper)
{
    double root, f1, f2, f3, dx = 0.1, x1, x2, Err, k = 0;
    int i = 0;

    while (x2 < Xupper)
    {
        x1 = Xlower;
        x2 = Xlower + dx;
        f1 = applyHorners(poly, n, x1);
        f2 = applyHorners(poly, n, x2);
        if ((f1 * f2) > 0)
        {
            Xlower = x2;
            continue;
        }
        else
        {
            do
            {
                root = (x1 + x2) / 2;
                f3 = applyHorners(poly, n, root);
                if ((applyHorners(poly, n, x1) * applyHorners(poly, n, root)) < 0)
                {
                    x2 = root;
                }
                else
                {
                    x1 = root;
                }
                i++;
            } while (fabs((x2 - x1) / x2) >= 0.0001);
            cout << "Approximate root: " << root << endl;
        }
        Xlower = x2;
        k++;
    }
}
int main()
{
    int n;
    double Xlower, Xupper;
    cout << "Enter the degree of the equation: ";
    cin >> n;
    int poly[n + 1];
    cout << "Enter the lower limit: ";
    cin >> Xlower;
    cout << "Enter the upper limit: ";
    cin >> Xupper;
    cout << "Enter the coefficients of the equation: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cin >> poly[i];
    }
    cout << "For interval size: " << Xlower << " - " << Xupper << endl;
    modifiedBisection(poly, n, Xlower, Xupper);

    return 0;
}
