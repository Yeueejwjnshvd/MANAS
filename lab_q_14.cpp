#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
cout<<"size of array"<<endl;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            int k;
            cout<<"the element to find"<<endl;
            cin>>k;
        sort(arr.begin(),arr.end());
int low=0;
int high=n-1;
bool found=false;
while(low<=high){
    int sum=arr[low]+arr[high];
    if(sum==k) {
        cout<<"sum is present"<<arr[low]<<arr[high]<<endl;
        found=true;
        break;
    }
    else if(sum>k) high--;
    else low++;
}
if(!found) {
    cout<<"sum is not present"<<endl;
}
    }
return 0;
    }