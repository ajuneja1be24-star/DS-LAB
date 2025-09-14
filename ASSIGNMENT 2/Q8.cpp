#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of array : ";
    int a;
    cin>>a;

    int b[a];

    for (int d = 0; d < a; d++)
    {
        cout<<"enter the element "<<d+1<<" of the array : ";
        cin>>b[d];
    }
        for(int i=0;i<a;i++){
            for(int j=i;j<a;j++){
                if(b[i]>b[j]){
                    swap(b[i],b[j]);
                }
            }
        }
        int c=0;
        for(int i=0;i<a;i++){
            if( b[i]!=b[i+1]){
                c++;
            }
        }
        cout<<"the no of distinct elements in the given array is "<<c<<endl;
}
