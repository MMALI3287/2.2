#include <stdio.h>
using namespace std;

int FindOutlier(std::vector<int> arr)
{
    if (arr[0] % 2 == 0 && arr[1] % 2 == 0 || arr[0] % 2 == 0 && arr[2] % 2 == 0 || arr[1] % 2 == 0 && arr[2] % 2 == 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 != 0)
            {
                return arr[i];
            }
        }
    }
    else if (arr[0] % 2 != 0 && arr[1] % 2 != 0 || arr[0] % 2 != 0 && arr[2] % 2 != 0 || arr[1] % 2 != 0 && arr[2] % 2 != 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 0)
            {
                return arr[i];
            }
        }
    }
}