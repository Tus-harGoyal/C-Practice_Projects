#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size :";
    cin>>n;
    cin.ignore();
char arr[n+1];
cin.getline(arr,n);
cin.ignore();
// int countlen=0;
// int maxlen=0;
// int i=0;
// int strIdx=0;
// while(1){
//     countlen++;
//     if (arr[i]==' '||arr[i]=='\0'){
//         if (countlen>maxlen){
//             maxlen=countlen;
//             strIdx=i-maxlen+19;
//         }
//         countlen=0;
//     }
//     if (arr[i]=='\0'){
//         break;
//     }
//     else
//     i++;
//     }
int countlen = 0;
int maxlen = 0;
int sI=0;
int maxsI;
int i = 0;
int strIdx = 0;
while (i < n) {
    if (arr[i]==' ' ||arr[i]=='\0'){
        if (maxlen<countlen){
            maxlen=countlen;
            maxsI=sI;

        }
        countlen=0;
        sI=i+1;
    }
    else{
   countlen++;}
    if (arr[i] == '\0') {
        break;
    }
    i++;
}


cout<<maxlen<<"\n";
for (int i=0;i<maxlen;i++){
    cout <<arr[i+maxsI];
}
    return 0;
}
