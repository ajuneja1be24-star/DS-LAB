#include<iostream>

using namespace std;

int main(){
    
    char a[100];
    cout<<"enter the first string : ";
    cin>>a;

    int b = 0;
    while (a[b]!='\0')
    {
        b++;
    }
    cout<<b<<endl;
    
    // reversing a string
    char c[100];
    for (int d = 0 , e = b-1 ; d < b && e >= 0; e--, d++)
    {
        c[d]=a[e];
    }
    c[b]='\0';
    cout<<"the reversed string is : ";
    cout<<c;
    
}
