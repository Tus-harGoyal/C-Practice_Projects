#include<bits/stdc++.h>
using namespace std;
int n=3;vector<double> d(3),b(3),x(3);
vector<vector<double>> L(3,vector<double>(3)),U(3,vector<double>(3)),a(3,vector<double>(3));
int main(){

    d[0]=b[0]/L[0][0];
    for(int i=1;i<n;i++){
        double sum=0;
        for(int j=0;j<i-1;j++){
            sum=sum+L[i][j]*d[j];
            d[i]=(b[i]-sum)/L[i][i];
        }
    }
    x[n-1]=d[n-1]/U[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        double sum1=0;
        for(int j=i+1;j<n;j++){
            sum1=sum1+U[i][j]*x[j];
        }
        x[i]=(d[i]-sum1)/U[i][i];
    }
    int n=3;
    vector<int> x(n);
    vector<int> b(n);
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    x[n-1]=b[n-1]/matrix[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        double sum=0;
        for(int j=i+1;j<n;j++){
            sum=sum+matrix[i][j]*x[j];
        }
        x[i]=(b[i]-sum)/matrix[i][i];
    }
    for(int i=0;i<n;i++){
        if(i==1){
            cout<<x[i]-1<<endl;
            continue;
        }
        cout<<x[i]<<endl;
}
}