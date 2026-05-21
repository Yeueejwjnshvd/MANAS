#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cout<<"Enter number of test cases: ";
    cin >> t;
    cin.ignore();
    while(t--) {
        int n1, n2;
        cout <<"\nEnter size of first array: ";
        cin >>n1;
        cout <<"Enter size of second array: ";
        cin >>n2;
        cin.ignore();

        vector<int> arr(n1), brr(n2);
        cout << "Enter " << n1 << " elements of first array: ";
        for(int i=0;i<n1;i++)
            cin >> arr[i];
        cout << "Enter "<<n2<< " elements of second array: ";
        for(int i=0;i<n2;i++)
            cin >> brr[i];
        unordered_set<int> s;
        bool f = false;

        for(int i = 0; i < n1; i++)
            s.insert(arr[i]);

        cout << "Common elements: ";
        for(int i = 0; i < n2; i++) {
            if(s.count(brr[i])) {
                f = true;
                cout << brr[i] << " ";
            }
        }

        if(!f) {
            cout << "not found";
        }

        cout << endl;
    }

    return 0;
}