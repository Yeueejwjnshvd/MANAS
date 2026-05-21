#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cout<<"no of test cases"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"size of array"<<endl;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cout<<"element "<<i<<endl;
            cin>>arr[i];
        }
        int totalc=0;
        int totalsh=0;
        for(int i=1;i<n;i++){
            int j=i-1;
            int comp=0;
            int shift=0;
            int key=arr[i];
            while(j>=0&&arr[j]>key){
                arr[j+1]=arr[j];
                shift++;
                comp++;

            j--;}
            if(j>=0) comp++;
            arr[j+1]=key;
        
totalc+=comp;
totalsh+=shift;
            }
         // Print sorted array
        for(int i = 0;i<n; i++) {
            cout<<arr[i] << " ";
        }
        cout<<"totalcompare:"<<totalc<<" |total shift :"<<totalsh<<endl;
        cout<<endl;
    
    }
        return 0;}
