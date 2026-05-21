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
        for(int i=0;i<n;i++){
            int small=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[small]){
                    small=j;
                }
                swap(arr[j],arr[small]);
            }
        }
         for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
    }
    return 0;
}
