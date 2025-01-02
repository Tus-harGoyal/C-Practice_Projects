#include <stdio.h>
void printmax(int arr[], int n, int *max) {
    int i;
    *max = arr[0];  // assume first element is max

    for (i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];  // update max if current element is larger
        }
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    int box;
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printmax(arr, n, &box);
    printf("%d",box);

    return 0;
    }
// void printmax(int m,int arr[],int *ptr){
//     int i;
//         *ptr=arr[0];

//         for(i=0;i<m;i++){
//             if (arr[i]>*ptr){
//                 *ptr=arr[i];
//             }
//         }
//     }
