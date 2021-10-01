// #include<iostream>
// using namespace std;

// int main(){
//     int size;
//     cin>>size;
//     int arr[size];
//     for(int i =0; i<size; i++){
//         cin>>arr[i];
//     }
//     int T;
//     cin>>T;
//     while(T--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         for(int i=a; i<=b; i++){
//             arr[i]+=c;
//         }
//     }
//     for(int i =0; i<size; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }



//scanline algorithm use:

// #include<iostream>
// using namespace std;

// int main(){
//     int size;
//     cin>>size;
//     int arr[size] , pre[size+1]={0};//taking an array of size+1
//     for(int i=0;i<size; i++){
//         cin>>arr[i];
//     }
//     int T;
//     cin>>T;
//     while(T--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         //formula of scanline algorithm
//         pre[a]+=c;
//         pre[b+1]-=c;
//     }
//     int sum =0;
//     for(int i=0; i<size; i++ ){
//         sum += pre[i];
//         cout<<arr[i]+sum<<" ";
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

int main(){
    int size, num;
    cin>>size>>num;
    int first,query;
    int prefix[size+1]={0};
    while(num--){
        cin>>first>>query;
        if(first-query>=0){
            prefix[first-query] += 1;
        }else{
            prefix[0]+=1;
        }
        if(first+query<=size){
            prefix[first+query+1] -= 1;
        }
    }
    int sum =prefix[0];
    int count =0;
    for(int i=1; i<size+1; i++){
        sum+=prefix[i];
        prefix[i] = sum;
    }
    for(int i=0; i<size+1; i++){
        if(prefix[i]!=1){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
