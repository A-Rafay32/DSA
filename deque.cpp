#include<iostream>
using namespace std;

class deque{
	private:
	    enum { size = 20};
	    int dq[size];
		int top,bottom ;
	public:
		deque(){
			dq[size];
			top = -1; bottom = size+1; 		 
		}
		void insertLeft(int d){
			dq[++top] = d;		  
		} 
		void insertRight(int d){
			dq[--bottom] = d;			
		}
		void removeRight(){
			int temp = size;
			while(!dq[temp])
				dq[temp] = dq[temp-1];
		} 
	
			
			
		
		bool isFull(){
			(top == size) ? true : false;			
		}
		bool isEmpty(){
			(top == -1 )? true : false;
		}
		void display(){
			for(int j=0;j<=size;++j)
			   cout << dq[j] << " " ;
		}
		
		 
		  
	
}; 
int main(){
	deque deq;
	deq.insertLeft(11); deq.insertLeft(22);
	deq.insertLeft(33); deq.insertLeft(44);
	//deq.removeRight();
	deq.insertRight(55) ; deq.insertRight(66);
	deq.display();
	deq.isFull();
	
}