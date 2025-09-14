#include<iostream>
#include<string>
using namespace std;

int main(){

    // transpose of a matrix

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
    
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;  j < m; j++)
        {
            b[i][j]=a[j][i];
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
    

    cout<<"the transposed matrix is : "<<endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < m; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

}
