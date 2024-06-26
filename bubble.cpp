#include <iostream>
using namespace std;
void swap(int &a, int &b){
 int temp = a;
 a=b;
 b=temp;
}
void bubblesort(int arr[],int n){
 int count=0;
 for(int i=0;i<n-1;i++)
 {
 count++;
 for(int j=0;j<n-i-1;j++){
 count++;
 if(arr[j+1]<arr[j]){
 count++;
 swap(arr[j+1],arr[j]);
 count++;
 }
 count++;
 }
 count++;
 }
 count++;
 cout<<"display the time complexity:"<<count<<endl;
}
int main()
{
 int n ,arr[]={5,4,3,2,1};
 n=sizeof(arr)/sizeof(arr[0]);
 bubblesort(arr,n);
 cout<<"DISPLAY SORTED ARRAY:"<<endl;
 for(int i=0;i<n;i++)
 {
 cout<<arr[i]<<" ";
 }
}
