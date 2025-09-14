#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of an array : ";
    int a;
    cin>>a;
    int b[a];
    int c = 0;

    for (int d = 0; d < a; d++)
    {
       cout<<"enter the "<<d+1<<" element of the array : ";
       cin>>b[d];
    }
    for (int e = 0; e < a; e++)
    {
        for (int f = e; f < a; f++)
        {
            if (e<f && b[e]>b[f])
            {
                c++;
            }
            else{
                continue;
            }
        }
    }
    cout<<"the total number of inversions in the array are : "<<c;

}
