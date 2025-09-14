#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    cout<<"enter the array size you want to create : ";
    int n;
    cin>>n;
    vector <int> v;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout<<"enter the element "<<i+1<<" of the array : ";
        cin>>v[i];
    }
    
    cout<<"the updated array with the duplicate array elements is : "<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<"the element "<<i+1<<" of the array is : "<<v[i]<<endl;
    }


    cout<<"checking for duplicate elements "<<endl;

    int t = 1;
    while (t==1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (v[i]==v[j])
                {
                    for (int k = j; k < n; k++)
                    {
                        v[k]=v[k+1];
                        n--;
                        v.resize(n);
                    }
                    
                }
                else{
                    continue;
                }
                
            }
            
        }
        t=0;
        
    }
    cout<<"the updated array without the duplicate array elements is : "<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<"the element "<<i+1<<" of the array is : "<<v[i]<<endl;
    }
    
    
}
