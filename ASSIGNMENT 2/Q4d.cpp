#include<iostream>
using namespace std;


int main(){

    char a[100];
    cout<<"enter the string : ";
    cin>>a;

    int b = 0;
    while (a[b]!='\0')
    {
        b++;
    }
    cout<<b<<endl;
    
    for (int c = 0; c < b; c++)
    {
        for (int d = 0; d < b-c-1 ; d++)
        {
            if ((int)a[d]>(int)a[d+1])
            {
                char e = a[d];
                a[d]=a[d+1];
                a[d+1]=e;
            }
            
        }
        
    }
    cout<<"the sorted string is :";
    cout<<a;

}
