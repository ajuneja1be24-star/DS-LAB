#include<iostream>
using namespace std;


int main(){

    char a;
    cout<<"enter the character : ";
    cin>>a;
    if ((int)a>=65 && (int)a<91)
        {
            a+=32;
        }
    
    cout<<"the character in lowercase is : ";
    cout<<a;

}
