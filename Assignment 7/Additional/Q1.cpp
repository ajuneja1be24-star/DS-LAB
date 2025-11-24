#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "ENTER NUMBER OF ELEMENTS:";
    cin >> n;
    int arr[100];
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int count[100] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 0; i <= max; i++)
    {
        while (count[i]--)
            cout << i << " ";
    }

    return 0;
}
