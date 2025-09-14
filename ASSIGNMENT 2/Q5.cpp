#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of matrix:" << endl;
    cin >> n;
    int diag[10];

    cout << "Enter diagonal elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> diag[i];
    }

    cout << "Diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    int lower[55];
    int index = 0;
    cout << "Enter lower triangular elements (row-wise):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> lower[index++];
        }
    }

    cout << "Lower Triangular Matrix:" << endl;
    index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << lower[index++] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    int upper[55];
    index = 0;
    cout << "Enter upper triangular elements (row-wise):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cin >> upper[index++];
        }
    }

    cout << "Upper Triangular Matrix:" << endl;
    index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
                cout << upper[index++] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    int sym[55];
    index = 0;
    cout << "Enter symmetric matrix lower triangular part:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> sym[index++];
        }
    }

    cout << "Symmetric Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                index = i * (i + 1) / 2 + j;
                cout << sym[index] << " ";
            }
            else
            {
                index = j * (j + 1) / 2 + i;
                cout << sym[index] << " ";
            }
        }
        cout << endl;
    }

    int tri[25];
    cout << "Enter tri-diagonal elements (lower, main, upper):" << endl;
    for (int i = 0; i < 3 * n - 2; i++)
        cin >> tri[i];

    cout << "Tri-diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == 1)
                cout << tri[i - 1] << " ";
            else if (i - j == 0)
                cout << tri[n - 1 + i] << " ";
            else if (i - j == -1)
                cout << tri[2 * n - 1 + i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
