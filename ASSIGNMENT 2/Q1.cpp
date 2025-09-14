#include<iostream>
#include<string>
using namespace std;

int b(int a[] , int n , int k){

    int l = 0 , r = n-1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == k)
        {
            return m;
        }
        else if (a[m] < k)
        {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main(){

    cout<<"enter the size of array : ";
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the "<<i+1<<" element of the array : ";
        cin>>a[i];
    }

    cout<<"the entered sorted array is : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
    cout<<"enter the number you want to find in array : ";
    int k;
    cin>>k;

    int f = b(a , n , k);

    if (f == -1)
    {
        cout<<"the number you have entered is not found ";
    }
    else {
        cout<<"The number is found";
    }
}
