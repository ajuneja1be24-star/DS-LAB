#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    int n = 0;
    int m = 0;
    vector <int> v;

    int t = 1;
    while(t==1){

        cout<<"enter the operation you want to perform : "<<endl;
        string o;
        cin>>o;

        if (o=="create")
        {
            cout<<"enter the size of array you want : ";
            cin>>n;
            v.resize(n);
            cout<<"enter the elements you want to enter in array : ";
            cin>>m;
            for (int i = 0; i < m; i++)
            {
                cout<<"enter the element "<<i+1<<" of the array :";
                cin>>v[i];
            }
        }
        else if (o=="display")
        {
            for (int i = 0; i < m; i++)
            {
                cout<<"the element "<<i+1<<" of the array is : "<<v[i]<<endl;
            }
        }
        else if (o == "insert")
        {

            if (m == n) {
                cout << "Array full! Resizing..." << endl;
                n++;
                v.resize(n);
            }

            cout<<"enter the element you want to insert : ";
            int x , y ;
            cin>>x;
            cout<<"enter the index you want to add element to : ";
            cin>>y;

            if (y < 0 || y > m) {
                cout << "Invalid index!" << endl;
                continue;
            }

            for (int i = m; i >= y; i--)
            {
                v[i+1]=v[i];
            }
            v[y]=x;
            m++;
            cout<<"the new updated array is : "<<endl;
            for (int i = 0; i < m ; i++)
            {
                cout<<"the element "<<i+1<<" of the array is : "<<v[i]<<endl;
            }
            
        }
        else if (o == "delete")
        {
            cout<<"enter the element index you want to delete : ";
            int z;
            cin>>z;

             if (z < 0 || z >= m) {
                cout << "Invalid index!" << endl;
                continue;


            for (int i = z; i < m; i++)
            {
                v[i]=v[i+1];
            }
            m--;

            cout<<"the new updated array is : "<<endl;
            for (int i = 0; i < m ; i++)
            {
                cout<<"the element "<<i+1<<" of the array is : "<<v[i]<<endl;
            }
        }
    }
        else if (o == "search")
        {
            cout<<"enter the element you want to find : ";
            int s;
            cin>>s;
            int f = 0; 
            for (int i = 0; i < m; i++)
            {
                if (v[i]==s)
                {
                    cout<<"the element you want to find is at index : "<<i<<endl;
                    f=1;
                    break;
                }
                else{
                    continue;
                }
            }
            if (f==0)
            {
                cout<<"the element you want to find is not in array "<<endl;
            }
        }
        else if (o=="exit")
        {
            t=0;
            break;
        }
    }

    return 0 ;
}
