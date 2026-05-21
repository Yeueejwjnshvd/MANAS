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
    bool found=false;
for(int i=0;i<n;i++){
    if(arr[i]==k){
      cout<<"present "<<i+1<<endl;
      found=true;
      break;
    }
}
   if(!found){
    cout<<"not present"<<endl;
   }

}
return 0;}




















