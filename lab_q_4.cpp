#include<bits/stdc++.h>
using namespace std;
int firstoccur(vector<int>&arr,int k){
    int low=0;
    int n=arr.size();
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
ans=mid;
high=mid-1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else high=mid-1;
        }
    return ans;}

    int lastoccur(vector<int>&arr,int k){
    int low=0;
    int n=arr.size();
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
ans=mid;
low=mid+1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else high=mid-1;
        }
    return ans;}

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
int k;
cin>>k;
int first=firstoccur(arr,k);
int last=lastoccur(arr,k);
if(first==-1){
    cout<<"-1 -1"<<endl;
}
else cout<<last-first+1<<endl;}
    return 0;
}