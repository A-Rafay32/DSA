#include<iostream>
using namespace std;

class DLLNode{
	public:
		int info;
		DLLNode* next , *prev ;
	public:
	    DLLNode() 
		{  next = 0 ; prev = 0 ; } 	
		DLLNode(int item , DLLNode *n = 0, DLLNode *p = 0  )
		{  info=item ; next = n ; prev = p ; }       
	
}; 

class Dlinkedlist{
	public:
		DLLNode *head , *tail;
	public:
	    Dlinkedlist()
		{ head = 0 ; tail = 0 ; }  
		 
		bool isEmpty()
			{ (head == 0 ) ? true : false ; }
			
		void addtoHead(int d){
			DLLNode* newNode = new DLLNode(d); // make new link
            if( isEmpty() ) 
                tail = newNode; 
            else 
                head->prev = newNode; // newLink <-- old first
            newNode->next = head; // newLink --> old first
            head = newNode; 
	} 	
		/*void addtoHead(int d){
			if (head!=0){
			    head = new DLLNode(d,0,head);
			    head->next->prev = head;  
			}    
			else 
			    head = tail = new DLLNode(d); 
			cout << "addtohead worked" << endl; }*/
		int deleteHead(){
			int d = head->info;
			if ( head == tail){
				delete head;
				head = tail = 0;} 
			else{
				head = head->next;	  
				delete head->prev;
				head->prev = 0;}
			}  	
		  	
				
		void addtoTail(int d){
			DLLNode* newNode = new DLLNode(d);
			if(isEmpty() )
			    head = newNode;
			else{
				tail->next = newNode;
				newNode->prev = tail;}
			tail = newNode; 		  
		cout <<"addtotail worked " << endl;	}
		
		int deleteTail(){
			int d = tail->info;
			if (head == tail ){  //if only one element 
				delete head ; 
				head = tail = 0;}
			else{
				tail = tail->prev;	  
				delete tail->next;
				tail->next = 0;}
			return d;	
		}
		
		void displayForward(){
			DLLNode* current =  head;
			while( current != 0){
				cout << current->info << " " ;
				current = current->next;   }  
		cout << "displayforward"<<endl; } 
		void displayBackward(){
			DLLNode* current = tail;
			while( current!=0){
				cout << current->info << " ";
				current = current->prev;}  
		cout << "displaybackward"<< endl;}
	
};

int main(){
	Dlinkedlist* DLL = new Dlinkedlist();
	DLL->addtoHead(44) ; DLL->addtoHead(33) ; 
	DLL->addtoHead(22) ; DLL->addtoHead(11) ;  
	DLL->addtoTail(55) ; DLL->addtoTail(66) ;
    DLL->displayForward()  ; cout << " " << endl;
	DLL->displayBackward() ; cout << " " << endl;  
}