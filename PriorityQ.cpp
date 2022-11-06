#include<iostream>
using namespace std; 
////////////////////////////////////////////////////////////////
class PriorityQ{
    private:
	     int maxSize;
         long queArray[20];
         int top;
//-------------------------------------------------------------
    public:
	    PriorityQ(int s){
         maxSize = s;
         queArray[maxSize];
         top =0 ;
        }
        void insert(long var) {
            int j;
            if(top == 0) // if no items,
                 queArray[top++] = var; // insert at 0
            else{
                for(j=top-1; j>=0; j--) {
                    if( var < queArray[j] ) // if new item larger,
                        queArray[j+1] = queArray[j]; // shift upward

                    else // if smaller,
                         break; // done shifting
                }  // end for
                queArray[j+1] = var; // insert it
                top++;
                } // end else (nItems > 0) 
        }    // end insert()

        long remove() // remove minimum item
             { return queArray[--top]; }

        long peekMin() // peek at minimum item
             { return queArray[top-1]; }

        bool isEmpty() // true if queue is empty
             { return (top==0); }

        bool isFull() // true if queue is full
             { return (top == maxSize); }

}; // end class PriorityQ

int main(){
	PriorityQ thePQ(20);
	thePQ.insert(30);
    thePQ.insert(50);
    thePQ.insert(10);
    thePQ.insert(40);
    thePQ.insert(20);
    while( !thePQ.isEmpty() ){
         long item = thePQ.remove();
	     cout << item << " " << endl ; // 10, 20, 30, 40, 50
    } // end while
    cout << " " << endl;

}