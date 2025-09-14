#include<iostream>
#include<string>
using namespace std;

int main(){

    cout<<"enter the size of array you want : ";
    int n;
    cin>>n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"enter the element "<<i+1<<" of the array : ";
        cin>>a[i];
    }
    
    // reversing the array
    int b[n];
    for (int i = 0 , j = n-1 ; i < n , j >= 0; i++ , j--)
    {
        b[i]=a[j];
    }
    for (int i = 0; i < n ; i++)
    {
        cout<<"the element "<<i+1<<" is : "<<b[i]<<endl;
    }
    
}
