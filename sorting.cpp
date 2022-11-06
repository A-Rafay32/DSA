/*There is no way to determine the length inside the function. However you pass arr,
sizeof(arr) will always return the pointer size. So the best way is to pass the
number of elements as a separate argument.
sizeof only works to find the length of the array if you apply it to the original array.

int arr[5]; //real array. NOT a pointer
sizeof(arr); // :)
However, by the time the array decays into a pointer, sizeof will give the 
size of the pointer and not of the array.

void getArraySize(int arr[]){
sizeof(arr); // will give the pointer size
}
There is some reasoning as to why this would take place. How could we make things
so that a C array also knows its length? A first idea would be not having arrays
decaying into pointers when they are passed to a function and continuing to keep 
the array length in the type system.
When you pass an array to a function it decays to pointer. So the sizeof function
will return the size of int *. This is the warning that your compiler complining
about*/

#include<iostream>
using namespace std;

void swap(int x, int y){
	int temp = x;
	x = y;
	y = temp ;
}

void print_array(int arr[],int n){

	for(int k=0 ; k<n ;++k)
	   cout << " " << arr[k]  ; 
	cout << endl ;
}

void  bubble_sort(int arr[], int n ){
	for ( int i=0 ; i<n-1 ; ++i ){
		for (int j=0 ; j<n-i ; ++j){
			if (arr[j] > arr[j+1])
				swap(arr[j+1],arr[j]);			   
		}
	}
	print_array(arr,10);
	
}

void insertion_sort(int arr[],int n){
	for(int j=2 ; j<n; ++j ){
		int i = 1;
		while(arr[j]>arr[i])
		      i+=1; 
		int  m = arr[j];
		for (int k=0 ; k<j-i-1 ; k++ )
		    arr[j-k] = arr[j-k-1];
		arr[i] = m ;
			      
	}
	print_array(arr,10);
	  
} 

void insertion_sort2(int arr[],int n){
	for(int i=1; i<n ; ++i){
		int j = i;
		while(arr[j]<arr[j-1]){
			swap(arr[j],arr[j-1]);
			j = j-1 ;
		}
	}
	print_array(arr,10);
}

void selection_sort(int arr[],int n) {
   int i, j, imin;
   for(i = 0; i<n-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<n; j++)
         if(arr[j] < arr[imin])
            imin = j;
         //placing in correct position
         swap(arr[i], arr[imin]);
   }
   print_array(arr,10);
}


int main(){
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	cout << "Bubble sort :    " ; bubble_sort(array,10); 
	cout << "Insertion sort  :"; insertion_sort(array,10);
	cout << "Insertion sort2 :"; insertion_sort2(array,10);
	cout << "Selection sort  :";  selection_sort(array,10);
}