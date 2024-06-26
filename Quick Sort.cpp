Quick Sort:
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
 int temp = a;
 a = b;
 b = temp;
}
int partition(int arr[], int low, int high,int &count)
{
 int pivot = arr[low];
 int i = (low+1);
 int j=high;
do
{
count++;
while(arr[i]<=pivot)
 {
 i++;
 count++;
}
while(arr[j]>pivot)
{
j--;
count++;
}
if(i<j)
{
count++;
swap(arr[i], arr[j]);
count++;
}

} while(i<j);
 swap(arr[low], arr[j]);
 count++;
 return j;
}
int quickSort(int arr[], int low, int high,int &count) {
count++;
 if (low < high) {
 count++;
 int pivotIndex = partition(arr, low, high,count);
 count++;
 quickSort(arr, low, pivotIndex - 1,count);
 count++;
 quickSort(arr, pivotIndex + 1, high,count);
 count++;
 }
 return count;
}
int main() {
 int arr[] = {5,4,3,2,1};
 int count=0;
 int n = sizeof(arr) / sizeof(arr[0]);
 quickSort(arr, 0, n - 1,count);
 cout<<"Display time complexity:"<<count<<endl;
 cout << "Sorted Array: ";
 for (int i =0; i<n; i++) {
 cout << arr[i] << " ";
 }
}