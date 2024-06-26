) Linear Search :
 #include<iostream>
using namespace std;
void linear(int arr[],int n,int key,int &count)
{
for(int i=0;i<n;i++)
{
count++;
if(arr[i]==key)
{
count++;
cout<<"found at: "<<i+1<<endl;
count++;
return;
}
count++;
}
count++;
cout<<"Not found"<<endl;
}
int main()
{
int key,count=0;
int arr[]={5,6,8,1,3};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<"Enter the element to be search:";
cin>>key;
linear(arr,n,key,count);
cout<<"Time complexity :"<<count<<endl;
}


Binary Search:
#include<iostream>
using namespace std;
void BINARY(int arr[],int n,int key,int &count)
{
int low =0,mid;
int high=n;
 while(low<=high)
 {
 count++;
 mid=(low+high)/2;
 count++;
 if(arr[mid]==key)
 {
 count++;
 cout<<"Element found at "<<mid+1<<endl;
 count++;
 return;
}
else if(arr[mid]>key)
{
count++;
high=mid-1;
count++;
}
else
{
count++;
low=mid+1;
count++;
}
}
cout<<"elemnt not found."<<endl;
}
int main()
{
int key,count=0;
int arr[]={1,2,3,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<"Enter the element to be search:";
cin>>key;
BINARY(arr,n,key,count);
cout<<"Time complexity :"<<count<<endl;
}
