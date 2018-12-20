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

void SelectionSort(int A[], int n)
{
	int i, j, minpos, temp;
	for(i = 0; i < n - 1; i++)
	{
		cout<<"\nIteration "<<i+1<<endl<<endl;
		minpos = i;
		cout<<"\tFinding the smallest number in the list..."<<endl<<endl;
		for(j = i + 1; j < n; j++) 	//fi nd the position of min element as minpos from i + 1 to n - 1
		{
			if(A[j] < A[minpos])
				minpos = j;
		}
		cout<<"\tSmallest number in the list = "<<A[minpos]<<endl<<endl;
		if(minpos != i)
		{
			cout<<"\tSwapping "<<A[i]<<" with "<<A[minpos]<<endl<<endl;
			temp = A[i]; // swap the ith element and minpos element
			A[i] = A[minpos];
			A[minpos] = temp;
		}
		DisplayWizF(A,7,i);
	}
}


int main(){
	int arr[]={45,3,12,7,56,10,34};
	cout<<"The content of the array b4 sort"<<endl;
	display(arr,7);
	SelectionSort(arr,7);
	cout<<"\nThe content of the array after sort"<<endl;
	display(arr,7);
	return 0;
}
