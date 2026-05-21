#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        unordered_map<int,int> freq;
        int maxfreq = 0;
        int ans= -1;

        for(int i=0;i<n;i++){
            freq[arr[i]]++;

            if(freq[arr[i]] > maxfreq){
                maxfreq = freq[arr[i]];
                ans = arr[i];
            }
        }
        cout<<ans<<endl;
    }
return 0;
}