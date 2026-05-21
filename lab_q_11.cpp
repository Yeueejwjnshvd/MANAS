//quick sort
#include<bits/stdc++.h>
using namespace std;
long long comparisons = 0;
long long swaps = 0;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        comparisons++;
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1],arr[high]);
    swaps++;
    return i+1;
}
void quicksort(vector<int>&arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
    
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);}
}
int main(){
    int t;
    cin>>t;
    while(t--){
        comparisons = 0;
        swaps = 0;
        int n;
        cout<<"Enter size of array: ";
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    
        quicksort(arr,0,n-1);
        
        for(int i=0;i<n;i++){
            cout<< arr[i] <<" ";
        }
        cout<<endl;
    
    cout<<"Comparisons: "<<comparisons<<endl;
        cout<<"swap: "<<swaps<<endl;}
    return 0;
}