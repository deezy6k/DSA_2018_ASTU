#include<iostream>

using namespace std;

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<"\t"<<arr[i]<<" ";
	}
	cout<<endl;
}
//Display with format
void DisplayWizF(int arr[],int n,int j){
	for(int i=0;i<n;i++){
		if(i==j)
			cout<<"\t"<<"["<<arr[i]<<"]";
		else
			cout<<"\t"<<arr[i]<<" ";
	}
	cout<<endl;
}

void InsertionSort(int A[], int n)
{
	int i, j, element;
	for(i = 1; i < n; i++)
	{
		cout<<"\nIteration "<<i<<endl<<endl;
		element = A[i]; // insert ith element in 0 to i - 1 array
		j = i;
		while((j > 0) && (A[j - 1] > element)) //compare if A[j - 1] > element
		{
			cout<<"\tSwapping "<<A[j]<<" with "<<A[j-1]<<endl<<endl;
			A[j] = A[j - 1]; // shift elements
			j = j - 1;
		}
		A[j] = element; // place element at jth position
		DisplayWizF(A,6,i);
	}
}

int main(){
	int arr[]={64,5,1,98,8,6};
	cout<<"The content of the array b4 sort"<<endl;
	display(arr,6);
	cout<<endl<<endl;
	InsertionSort(arr,6);
	cout<<"\nThe content of the array after sort"<<endl;
	display(arr,6);
	return 0;
}
