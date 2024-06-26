1)	Merge Sort:
#include<iostream>
using namespace std;
void merge(int arr[],int mid,int low,int high,int &count)
 {
    int i,j,k;
    int B[high-low+1];
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid && j<=high)
    {  count++;
        if(arr[i]<arr[j])
        {
            count++;
            B[k]=arr[i];
            count++;
            i++;
            count++;
            k++;
            count++;
        }
        else
        {
            count++;
            B[k]=arr[j];
            count++;
            j++;

 count++;
 k++;
 count++;
 }
 }
 count++;
 while(i<=mid)
 {
 count++;
 B[k]=arr[i];
 count++;
 i++;
 count++;
 k++;
count++;
 }
 count++;
 while(j<=high)
 {
 count++;
 B[k]=arr[j];
 count++;
 j++;
 count++;
 k++;
 count++;
 }
 count++;
 for (i = low, k = 0; i <= high; i++)
 {
 count++;
 arr[i] = B[k];
 count++;
 k++;
 count++;
 }
 count++;
}
void mergesort(int arr[],int low,int high,int &count){
count++;
 if(low<high)
 { count++;
 int mid=(low+high)/2;
 mergesort(arr ,low,mid,count);
 mergesort(arr ,mid+1,high,count);
 merge(arr ,mid,low,high,count);
 }
}
int main()
{
 int arr[] = {5,4,3,2,1};
 int n = sizeof(arr) / sizeof(arr[0]);
 int count=0;
 mergesort(arr, 0, n - 1,count);
 cout<<"Display time complexity:"<<count<<endl;
 cout << "Sorted Array: ";
 for (int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
 return 0;
}