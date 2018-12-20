#include<iostream>

using namespace std;

int SeqSearch (int A[], int key, int n)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		cout<<"Searching for "<<key<<" in position "<<i;
		if(key == A[i])
		{
			cout<<" : Found"<<endl<<endl;
			cout<<key<<" is found at position = "<<i<<endl;
			return i;
		}
		cout<<" : Not Found!"<<endl;
	}
	cout<<key<<" is not found in the list"<<endl;
	return(-1);
}

int main(){
	int arr[]={45,3,12,7,56,10,34};
	int num;
	cout<<"The content of the array"<<endl;
	for(int i=0;i<7;i++){
		cout<<" "<<arr[i]<<" ";
	}
	cout<<"\n\nEnter the key you want search\n";
	cin>>num;
	SeqSearch(arr,num,7);
}
