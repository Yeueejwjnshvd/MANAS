#include<bits/stdc++.h>
using namespace std;
bool duplicates(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                cout<<"duplictaes presnt"<<endl;
            return true;
            break;
        }
    }
     cout<<"no duplicates"<<endl;
return false;
    }

int main(){
    int t;
    cout<<"no of test cases"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"size of array"<<endl;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cout<<"element "<<i<<endl;
            cin>>arr[i];
        }
        duplicates(arr);}
        return 0;}