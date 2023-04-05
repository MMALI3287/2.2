#include <stdio.h>
#include <string.h>

int find_odd(size_t length, int array[length])
{
    int count = 0;
    int index[length];
    memset(index, -1, sizeof(index));
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == array[i + 1])
        {
            count++;
        }
        else if (array[i] != array[i + 1])
        {
            array[i];
            count++;
            if (count % 2 != 0)
            {
                return array[i];
            }
            else if (count % 2 == 0)
                count = 0;
        }
    }
    return -1;
}
int main()
{
    int array[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10};
    size_t length = sizeof(array) / sizeof(array[0]);
    printf("%d", find_odd(length, array));
    return 0;
}