#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void arrayDel(char*barr,int i,int* m){
    int max= *m;
    for(int j=i;j<max;j++){
        barr[j]= barr[j+1];
    }
    *m=*m-1;
}

char LSRB(char a,char b, char c){
    string temp={a,b,c};
if (temp=="LBR"){
    return 'B';
}
if (temp=="LBS"){
    return 'R';
}
if (temp=="RBL"){
    return 'B';
}
if (temp=="SBL"){
    return 'R';
}
if (temp=="SBS"){
    return 'B';
}
if (temp=="LBL"){
    return  'S';
}

}

void pathshorten(char* arr, int* n) {
    // cout << "pathshorten" << endl;
    int i = 0;
    while (i < *n) {
        if (arr[i] == 'B') {
            // cout << i << endl << LSRB(arr[i - 1], arr[i], arr[i + 1]);
            arr[i - 1] = LSRB(arr[i - 1], arr[i], arr[i + 1]);
            arrayDel(arr, i, n);
            arrayDel(arr, i, n);
            cout<<"shortened path : ";
            for (int i=0;i<*n;i++){
                cout<< arr[i];

                     }
                     cout<<endl;
    i=0;
        }
i++;
    }
}

int main(){
    char ipArray[1000];
    int i=0;
    string s;
    cin>>s;
    int n[1];
    while(true){

        if(s[i]=='\0'){
            ipArray[i]='E';
            n[0]=i;

            break;
        }
        ipArray[i]=s[i];
        i++;

    }


    pathshorten(ipArray,n);






}