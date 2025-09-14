#include<iostream>
#include<string>
using namespace std;

int main(){

    int m,n;
    cout<<"enter the rows of array you want : ";
    cin>>m;
    cout<<"enter the columns of array you want : ";
    cin>>n;
    int a[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"enter the element "<<i<<j<<" : ";
            cin>>a[i][j];
        }
    }

    cout<<"the normal matrix is : "<<endl;
    
    for (int i = 0; i < m; i++)
    {
        for (int j= 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"rows addition : "<<endl;

    for (int i = 0; i < m; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += a[i][j];
        }
        cout<<"the sum of row "<<i+1<<" is : "<<s<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < m; j++)
        {
            s += a[j][i];
        }
        cout<<"the sum of column "<<i+1<<" is : "<<s<<endl;
    }
}
