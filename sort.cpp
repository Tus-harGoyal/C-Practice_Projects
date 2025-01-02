#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n;

    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int j=0;j<n;j++){
         for (int i=j+1;i<n;i++){
            int temp;
            if (arr[j]>arr[i]){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    }
   for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;

}