
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
        sort(arr.begin(),arr.end());
    cout<<"elemnt to search"<<endl;
    cin>>k;
    int low=0;
    int high=1;
    bool found=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        int diff=arr[high]-arr[low];
if(diff==k){
found=true;
cout<<"presnt"<<endl;
break;
}
else if(diff>k){
high--;
}
    else low++;}

if(!found){
    cout<<"not presnt"<<endl;
}}

return 0;
}













