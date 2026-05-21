#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int k;
    int t;
    cout<<"test cases"<<endl;
    cin>>t;
    while(t--){
        cout<<"size of array"<<endl;
        cin>>n;
    vector<int>arr(n);
    cout<<"array elemnets"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"elemnt to search"<<endl;
    cin>>k;
   
    sort(arr.begin(),arr.end());
    int low=0;
    int high=n-1;
    bool found=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            cout<<"present"<<mid+1<<endl;
            found=true;
            break;
        }
        else if(arr[mid]>k){
            high=mid-1;
        }
        else low=mid+1;
    }
    if(!found){
        cout<<"not present"<<endl;
    }
}
return 0;
}




















