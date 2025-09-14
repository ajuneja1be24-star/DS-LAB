#include<iostream>
// #include<vector>
using namespace std;

int main(){

    char str[100];
    cout<<"enter the string : ";
    cin>>str;

    int u = 0;
    while (str[u]!='\0')
    {
        u++;
    }
    cout<<u<<endl;
    
    for (int i = 0; i < u; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            for (int j = i; j < u; j++)
            {
                str[j]=str[j+1];
            }
            u--;
            i--;
        }
        
    }

    cout<<u<<endl;

    cout<<"the string without the vowels is :";
    for (int i = 0; i < u; i++)
    {
        cout<<str[i];
    }

}
