#include<iostream>
#include<string>

using namespace std;

int main(){

    cout<<"enter the size of array you want : ";
    int n ; 
    cin>>n;
    int arr[n];
    for (int i = 0; i <= n-1; i++) // for missing element
    {
        cout<<"enter the element of the array : ";
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]==1){
            continue;
        }
        else cout<<"the missing element is "<<i+2<<endl;
    }
    

}
