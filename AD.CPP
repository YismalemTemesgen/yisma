#include <iostream>
using namespace std;
int main(){
    int A[2][2],B[2][2],C[2][2],i,j;
    cout<<"Enter 4 Elements for A Matrix";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
         cin>>A[i][j];
}
cout<<"Enter 4 Elements for B Matrix";
     for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
           cin>>B[i][j];
     }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
          C[i][j]=A[i][j]-B[i][j];
          C[i][j]=A[i][j]+B[i][j];
    }
    cout<<"C[i][j]";
return 0;
}