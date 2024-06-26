) Insertion Sort:
#include <iostream>
using namespace std;
void insertionsort(int arr[],int n){
 int count=0;
 for(int i=1;i<n;i++)
 {
 count++;
 int j=0;
 count++;
 int key=arr[i];
 count++;
 for( j=i-1;j>=0 && arr[j]>key;j--)
 {
 count++;
 arr[j+1]=arr[j];
 count++;
 }
 count++;
 arr[j+1]=key;
 count++;
 }
 count++;
 cout<<"display the time complexity:"<<count<<endl;
}
int main()
{
 int n ,arr[]={5,4,3,2,1};
 n=sizeof(arr)/sizeof(arr[0]);
 insertionsort(arr,n);
 cout<<"DISPLAY SORTED ARRAY:"<<endl;
 for(int i=0;i<n;i++)
 {
 cout<<arr[i]<<" ";
 }
}