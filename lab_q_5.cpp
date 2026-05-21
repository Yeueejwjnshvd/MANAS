#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    bool found=false;
for(int k=n-1;k>=2;k--){
int i=0;
int j=k-1;
while(i<j){
int sum=arr[i]+arr[j];
if(sum==arr[k]){
    found=true;
    cout<<arr[i]<<"+"<<arr[j]<<"="<<arr[k]<<endl;
    break;
}
else if(sum<arr[k]){
    i++;}

else j--;}
}
 if(!found) cout<<"No such triplet"<<endl;
}
    return 0;
}