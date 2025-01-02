#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

float f1(float x){
    return 1;
}
float f2(float x){
    return x;
}
float f3(float x){
    return x*x;
}
float f4(float x){
    return x*x*x;
}


const int N = 4;

// Function to perform Gaussian Elimination
void gaussianElimination(float A[N][N], float b[N][1], float x[N][1]) {
    // Forward elimination
    for (int i = 0; i < N; i++) {
        // Partial pivoting
        int pivotRow = i;
        for (int j = i + 1; j < N; j++) {
            if (fabs(A[j][i]) > fabs(A[pivotRow][i]))
                pivotRow = j;
        }
        if (pivotRow != i) {
            // Swap rows if needed
            for (int k = 0; k < N; k++) {
                swap(A[i][k], A[pivotRow][k]);
            }
            swap(b[i][0], b[pivotRow][0]);
        }

        // Elimination
        for (int j = i + 1; j < N; j++) {
            float factor = A[j][i] / A[i][i];
            for (int k = i; k < N; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j][0] -= factor * b[i][0];
        }
    }

    // Backward substitution
    for (int i = N - 1; i >= 0; i--) {
        x[i][0] = b[i][0];
        for (int j = i + 1; j < N; j++) {
            x[i][0] -= A[i][j] * x[j][0];
        }
        x[i][0] /= A[i][i];
    }
}


int main(){

float a[4][1];
float F[6][4];
float FT[4][6];
float X[6]={0,1,2,3,4,5};
float Y[6][1]={1,2,9,28,65,126};

// cout <<f1(X[0])<<endl;

for (int i=0;i<6;i++){
    // cout<<"p";
    for (int j=0;j<4;j++){
        if (j==0){

                F[i][j]=f1(X[0]);
                // cout<<"q";
            }
        else if (j==1){

                F[i][j]=f2(X[i]);
                // cout<<"r";
            }
        else if (j==2){

                F[i][j]=f3(X[i]);
                // cout<<"s";
            }
        else if (j==3){

                F[i][j]=f4(X[i]);
                // cout<<"t";
            }

    }

    }


    for (int i=0;i<4;i++){
        for (int j=0;j<6;j++){
            FT[i][j]=F[j][i];
    }
    }
    cout<<endl;
// Print
    for (int i=0;i<4;i++){
        for (int j=0;j<6;j++){
            cout <<FT[i][j]<<"  ";
        }
        cout <<endl;
    }
    // Print
    cout <<endl<<endl;
    for (int i=0;i<6;i++){
        for (int j=0;j<4;j++){
            cout <<F[i][j]<<"  ";
        }
        cout <<endl;
    }


//FTF
float FTF[4][4];

    // Initialize FTY to zeros
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j< 4; j++){
                FTF[i][j] = 0;
        }

    }

    // Matrix multiplication
    for (int i = 0; i < 4; i++) {
        for (int j=0;j<4;j++){
                for (int k = 0; k < 6; k++) {

            FTF[i][j] += FT[i][k] * F[k][j];
        }
        }

    }
cout<<endl;
    // Print the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << FTF[i][j] << " ";
        }
        cout<<endl;
    }

cout<<endl<<endl;
//FTY
float FTY[4][1];

    // Initialize FTY to zeros
    for (int i = 0; i < 4; i++) {
        FTY[i][0] = 0;
    }

    // Matrix multiplication
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 6; k++) {
            FTY[i][0] += FT[i][k] * Y[k][0];
        }
    }

    // Print the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 1; j++) {
            cout << FTY[i][j] << endl;
        }
    }
cout<<endl;

    gaussianElimination(FTF,FTY , a);

    // Print the solution
    cout << "Solution (a):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "[" << i << "][0] = " << a[i][0] << endl;
    }

    return 0;
}



