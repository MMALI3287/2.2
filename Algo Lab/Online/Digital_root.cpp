#include <bits/stdc++.h>
using namespace std;
int digital_root(int n)
{
    int sum = 0, temp = n;
    cout << "Temp: " << temp << endl;
    while (temp != 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    cout << "Sum: " << sum << endl;
    if (sum / 10 != 0)
    {
        cout << "Root: " << digital_root(sum) << endl;
        sum = digital_root(sum);
    }
    cout << "Sum: " << sum << endl;
    return sum;
}
int main()
{
    cout << digital_root(195) << endl;

    return 0;
}