// Count inversions in an array 

#include<iostream>
#include<vector>
using namespace std;

int countInversions(vector<int>&array,int N){
    int count=0;
    
    for(int i=0; i<array.size(); i++){
        for(int j=i+1; j<array.size(); j++){
            if(array[j]<array[i]){
                count++;
            }
        }
    }
    
    return count;
}

int main(){
    vector<int>array={1,2,3,4,5};
    int N=5;
    cout<<countInversions(array,N);
}