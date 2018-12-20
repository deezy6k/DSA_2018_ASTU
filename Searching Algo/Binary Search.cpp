#include<iostream>

using namespace std;

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<"\t"<<arr[i]<<" ";
	}
	cout<<endl;
}
//Display With Format
void DisplayWizF(int arr[],int n,int h,int l,int m){
	for(int i=0;i<n;i++){
		if(i==l)
			cout<<"\t"<<"["<<arr[i]<<" ";
		else if (i==h)
			cout<<"\t"<<" "<<arr[i]<<"]";
		else if (i==m)
			cout<<"\t"<<"("<<arr[i]<<")";
		else
			cout<<"\t"<<arr[i]<<" ";
	}
	cout<<endl;
}

int Binary_Search(int A[], int key, int n)
{
	int low = 0, high = n - 1, mid;

	while(low <= high)
	{ 
		mid = (low + high)/2; 
		cout<<"Low = "<<low<<" High = "<<high<<" Mid = "<<mid<<endl<<endl;
		DisplayWizF(A,7,high,low,mid);
		if(A[mid] == key){
			cout<<"\n"<<key<<" is found at position = "<<mid<<endl<<endl;
			return mid;
		} 
		else if(key<A[mid]){
			high = mid - 1;
			cout<<"\n"<<key<<" is not found at position = "<<mid<<
			". So search the left half "<<endl<<endl;
		}			
		else{
			low = mid + 1;
			cout<<"\n"<<key<<" is not found at position = "<<mid<<
			". So search the right half "<<endl<<endl;
		}
		DisplayWizF(A,7,high,low,mid);			
	}
	cout<<"\n"<<key<<" is not found in the list!"<<endl<<endl;
	return -1;
}


int main(){
	int arr[]={4,13,21,37,46,50,64};
	int num;
	cout<<"The content of the array"<<endl;
	display(arr,7);
	cout<<endl<<endl<<"Enter the number you want to search\n";
	cin>>num;
	Binary_Search(arr,num,7);
	return 0;
}
