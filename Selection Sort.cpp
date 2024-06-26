Selection Sort:
#include <iostream>
using namespace std;
void swap(int &a, int &b){
 int temp = a;
 a=b;
 b=temp;
}
void selectionsort(int arr[],int n){
 int count=0,mid_index;
 for(int i=0;i<n;i++)
 {
 count++;
 mid_index=i;
 count++;
 for(int j=i+1;j<n;j++){
 count++;
 if(arr[j]<arr[mid_index]){
 count++;
 mid_index=j;
 count++;
 }
 count++;
 }
 count++;
 swap(arr[mid_index],arr[i]);
 count++;
 }
 count++;
 cout<<"display the time complexity:"<<count<<endl;
}
int main()
{
 int n ,arr[]={5,4,3,2,1};
 n=sizeof(arr)/sizeof(arr[0]);
 selectionsort(arr,n);
 cout<<"DISPLAY SORTED ARRAY:"<<endl;
 for(int i=0;i<n;i++)
 {
 cout<<arr[i]<<" ";
 }
}