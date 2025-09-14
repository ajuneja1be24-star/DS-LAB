#include <iostream>
using namespace std;

void dup(int arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 2)
        {
            for (int j = size; j > i + 1; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = 2;
            size++;
            i++;
        }
    }
}
int main()
{
    int arr[50] = {1, 2, 1, 2, 4};
    int size = 5;
    dup(arr, size);

    cout << "Modified array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
