int lcm(int i, int j)
{
    int a = i;
    int b = j;
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return i * j / a;
}
Console.WriteLine(lcm(12, 18));