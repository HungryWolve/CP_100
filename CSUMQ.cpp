#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;cin>>n;
        int arr[n];
        int pre[n];
        for(int i = 0; i< n; i++){
                cin>>arr[i];
        }
        for(int i = 0; i < n; i++){
                pre[i] = arr[i];
                if(i-1>=0){
                        pre[i] += pre[i-1]; 
                }
        }
        int q;cin>>q;
        int sum = 0;
        int res[q];
        int s = 0;
        while(q--){
                int l,r;cin>>l>>r;
                sum = pre[r];
                if(l-1>=0)
                        sum -= pre[l-1];
                res[s++] = sum;
        }
        for(int i : res){
                cout << i <<" ";
        }

}