#include<iostream>

using namespace std;

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<"\t"<<arr[i]<<" ";
	}
	cout<<endl;
}
//display with format
void DisplayWizF(int arr[],int n,int j){
	for(int i=0;i<n;i++){
		if(i==j)
			cout<<"\t"<<"["<<arr[i]<<"]";
		else
			cout<<"\t"<<arr[i]<<" ";
	}
	cout<<endl;
}

// function for bubble sort for array A having n elements
void bubblesort(int A[], int n)
{
	int i, j,temp;
	for(i = 1; i < n; i++) // number of passes
	{
		cout<<"\nIteration "<<i<<endl<<endl;
		for(j = 0; j < n - i; j++) // j varies from 0 to n - i
		{
			if( A[j] > A[j + 1] ) // compare two successive numbers
			{
				cout<<"\tSwapping "<<A[j]<<" with "<<A[j+1]<<endl<<endl;
				temp = A[j]; // swap A[j] with A[j + 1]
				A[j] = A[j + 1];
				A[j + 1] = temp;
				DisplayWizF(A,7,j+1);
			}else{
				cout<<"\tNo Change "<<endl<<endl;
				DisplayWizF(A,7,j+1);
			}
		}		
	}
}

int main(){
	int arr[]={45,3,12,7,56,10,34};
	cout<<"The content of the array b4 sort"<<endl;
	display(arr,7);
	cout<<endl<<endl;
	bubblesort(arr,7);
	cout<<"The content of the array after sort"<<endl;
	display(arr,7);	
	return 0;
}
