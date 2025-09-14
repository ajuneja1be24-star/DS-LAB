#include<iostream>

using namespace std;

int main(){

    char str1[100] , str2[100];
    cout<<"enter the first string : ";
    cin>>str1;
    cout<<"enter the second string : ";
    cin>>str2; 
    int u = 0;
    while (str1[u]!='\0')
    {
        u++;
    }
    cout<<u<<endl;

    int y = 0;
    while (str2[y]!='\0')
    {
        y++;
    }
    cout<<y<<endl;

    int o = u+y ;
    for (int i=u,j=0; i<o , j<y; j++,i++)
    {
        str1[i]=str2[j];
    }
    cout<<"complete string : ";
    for (int i = 0; i < o; i++)
    {
        cout<<str1[i];
    }


}
