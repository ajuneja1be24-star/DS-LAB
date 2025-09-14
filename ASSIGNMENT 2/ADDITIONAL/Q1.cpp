#include <iostream>
using namespace std;
int pairs(int arr[], int size, int k)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((arr[i] - arr[j] == k) || (arr[j] - arr[i] == k))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 5, 3, 4, 2};
    cout << "Count of pairs " << pairs(arr, 5, 2);
    return 0;
}
