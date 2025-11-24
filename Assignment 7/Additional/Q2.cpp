#include <iostream>
using namespace std;

void radix(int arr[], int size, int exp)
{
    int res[100];
    int Count[10] = {0};

    for (int i = 0; i < size; i++)
        Count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        Count[i] += Count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        res[Count[digit] - 1] = arr[i];
        Count[digit]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = res[i];
}

int main()
{
    int n;
    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;

    int arr[100];
    int largest = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }

    for (int exp = 1; largest / exp > 0; exp = exp * 10)
        radix(arr, n, exp);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
