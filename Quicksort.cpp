#include<iostream>
using namespace std;
//quicksort with partition method
/*class quicksort{
	private :
		int arr[10]; // sorted array
	public :
	    quicksort(){
	    	for(int i=0 ; i<10  ; ++i)
			     arr[i] = i;	}
		int* partition(int *left , int *right ){
			
			int *pivotPos = right   ;
			int pivot = arr[*pivotPos] ;
			right -= 1 ;
			
			while (true){				
				while( arr[*left] < pivot)
				   left += 1 ;
				while (arr[*right] > pivot )
				   right -= 1;
				if (left >= right)
				    break;
				else 
				    swap(left , right);			
			}
			swap(*left , *pivotPos );
			return left ;  
		}
			     
			
};
void swap(int *pointer1 , int *pointer2  ){
			int *temp = arr[pointer1];
			arr[pointer1] = arr[pointer2];
			arr[pointer2] = temp; 
		} */
		
void mySwap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void myQsort(int myArray[], int min, int max){
    int pivot = myArray[(min + max) / 2]; //3 
//    cout << "pivot " << pivot << endl; 

    int left = min, right = max;  //
//    cout << "left " <<left << endl; // 0
//    cout << "right " <<right << endl; // 4

    while (left < right) {
        while (myArray[left] < pivot) {  // if left pointer < pivot
            left++;  // move left pointer forward
  //          cout << "left after comparsion"<<  left << endl;
        }
        while (myArray[right] > pivot) { // if right pointer > pivot
           	right--; // move right pointer forward
 //          	cout << "right after comparsion"<<  right << endl;
        }

        if (left <= right) { 
            // if left and right points to same value
            // swap them
            mySwap(myArray[left], myArray[right]);
   //         cout << "swapped" << endl; //2,1,3,4,5
            left++; // continue the process
            right--; 
        }
    }

    if (min < right) {  
        cout <<"min: "<< min << endl << "right: " << right << "\n\n";
        myQsort(myArray, min, right); 
    }
    if (max > left) { 
        cout <<"left: "<< left << endl << "max: " << max << "\n\n";
        myQsort(myArray, left, max); 
    }
}

int main()
{
    int myArray[] = {2,1,3,4,5,8,6,7,9,0} ;
    int min = 0 ;
    int max = sizeof(myArray) / sizeof(int) ;

    myQsort(myArray, min, max-1);

    for (int i = 0; i < max; i++) {
        cout<<myArray[i]<<" ";
    }

    return 0;
}