
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
  int step=sqrt(n);
int i=0;
bool found=false;
while(i<n&&arr[i]<k){
    i+=step;
}
int start=i-step;
if(start<0) start=0;
for(int j=start;j<i&&j<n;j++){
    if(arr[j]==k){
     found=true;
        cout<<"present "<<j+1<<endl;
        break;
    }
}
if(!found){
    cout<<"not present"<<endl;}}
return 0;}




















