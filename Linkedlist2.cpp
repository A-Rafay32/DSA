#include<iostream>
using namespace std;

class link
{
	public :
		int data ;
		link *next;
	public :
		link(){
			next = NULL;    }
		link(int d){
			data = d;
			next = NULL;
        }
};

class Linkedlist
{
	private :
		link *first;
	public :
	    Linklist()
		{ first = NULL ;}
		
		void addItem(int d)
		{
		  	link* newlink = new link;
			newlink->data = d ;
			newlink->next = first ;
			first = newlink ;
		}
		
		link* deletefirst(){
			link* temp = first;
			first = first->next;
			return temp;
		}
		/*void insertfirst(int d){
			link* newlink = new link ;
			newlink->data = d;
			newlink->next = first ;
			first = newlink ;
		}*/
		link* find(int d){
			link* current = first;
			while(current->data != d ){
				if (current->next == NULL)
				    return NULL;
				else 
				    current = current->next; }
			return current; 
		}
		link* deleteItem(int d){
			link* current = first;
			link* previous = first ;
			while(current->data != d){
				if (current->next = NULL)
				    return NULL;
				else{
					previous = current ;
					current = current->next;}		     				
			}
			if (current==first)
			     first = first->next;
			else 
			     previous->next = current->next;
			return current;	      	
		}
		
		void display()
		{
		    link* current = first ;
			while( current != NULL )
			{
				cout << current->data << endl;
				current = current->next ; 
			}
		}	
};

int main()
{
	Linkedlist l  ;
	l.addItem(11) ; l.addItem(22) ;
	l.addItem(33) ; l.addItem(44) ;
	l.addItem(55) ;
    l.addItem(66) ;
    
    l.deletefirst();
    
    /*link* f = l.find(11);    
	if (f != NULL)
        cout << "link found with data "<< f->data << endl;
    else 
	    cout <<"Link doesnot exist" << endl;*/   
    /*link* del = l.deleteItem(33);
    if (del != NULL)
      	cout << "link deleted with data "<< del->data << endl;
    else 
	   	cout <<"Link doesnot exist" << endl;   */
	   	
    l.display();
    
	
 
   
}