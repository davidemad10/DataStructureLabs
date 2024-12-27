#include <iostream>
using namespace std;


int linearSearch(int arr[],int size,int target){
    int iterations = 0 ;
    for (int i = 0; i < size ; i++){
        iterations++;
        if (arr[i] == target) { cout<<"LinearSearch iterate "<<iterations<<" Times"<<endl; return i;}
     }
    return -1;
}

int binarySearch(int arr[],int size,int target){
    int mid,start = 0,end = size-1, iterations = 0 ;
;
    do {
        iterations++;
        mid = ((end - start) / 2) + start;
        if (arr[mid] == target ) {cout<<"BinarySearch iterate "<<iterations<<" Times"<<endl; return mid;}
        else if (arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }while(start<=end);
    return -1;
}



int main(){
    int arr[8] = {1,2,3,4,5,6,7,8};
    int l = linearSearch(arr,8,8);
    l == -1 ? cout<<"Target is not in the array. "<<endl : cout<<"Target founded at index "<<l<<endl;
    int b = binarySearch(arr,8,8);
    b == -1 ? cout<<"Target is not in the array. "<<endl : cout<<"Target founded at index "<<b<<endl;


    return 0;
}