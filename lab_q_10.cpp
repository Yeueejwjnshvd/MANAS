#include<bits/stdc++.h>
using namespace std;
long long comparisons = 0;
long long inversions = 0;
void merge(vector<int>&arr,int low,int high,int mid){
int n1=mid-low+1;
int n2=high-mid;
vector<int> left(n1),right(n2);
for(int i=0;i<n1;i++){
left[i]=arr[low+i];
}
for(int j=0;j<n2;j++){
right[j]=arr[mid+1+j];
}
int i=0,j=0,k=low;
while(i<n1&&j<n2){
    comparisons++;
if(left[i]<=right[j]){
    arr[k]=left[i];
i++;}

else {
    arr[k]=right[j];
     inversions+=(n1-i);
    j++;
}
k++;
}
while(i<n1){
    arr[k]=left[i];
    i++;
    k++;
}
while(j<n2){
    arr[k]=right[j];
    j++;
    k++;
}
}
void merge_sort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    {
 int mid=low+(high-low)/2;
merge_sort(arr,low,mid);
merge_sort(arr,mid+1,high);
merge(arr,low,high,mid);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
         comparisons = 0;
        inversions = 0;
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        merge_sort(arr,0,n-1);
        
        for(int i=0;i<n;i++){
            cout<< arr[i] <<" ";
        }
        cout<<endl;
    
    cout<<"Comparisons: "<<comparisons<<endl;
        cout<<"Inversions: "<<inversions<<endl;}
    return 0;
}