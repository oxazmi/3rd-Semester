#include <iostream>
using namespace std;

int main(){
int data[]= {5,4,3,2,1,3,2,1,2,1,-79,-21};
int temp;

for(int i=0; i<12; i++){
    for(int j=i+1; j<12; j++){
        if(data[i]>data[j]){
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
    }
}

for (int i=0; i<12; i++){
    cout<<data[i]<<" ";
}
}
