#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct node{
		int info;
		struct node* link;
	};
	
class linkedList{
				
	private:		// by the way, default visibility of member variables is **private** 
		struct node* START;
	
		struct node* createNode(){
				struct node* tmp = new struct node; 
				return tmp;
		} 
	public:
		linkedList(){ 	//constructor function
			this->START=NULL;
		}
		
		void insertNodeAtStart(){
		
			struct node* tmp = this->createNode();
			cout<<"Enter integer value to insert: "; 
			cin>>tmp->info;
			
			if(this->START==NULL)
				tmp->link=NULL;
			else // if list is not empty
				tmp->link=START;
				
			this->START=tmp;
		}
	
		void deleteNodeFromEnd(){
			
			if(this->START==NULL)
				cout<<"List is already empty!\n";
			else{
				struct node* toDel = this->START;
				if(toDel->link==NULL){  // if list has only one node
					delete toDel;
					this->START=NULL;
				}
				else{  // if list has more than one node		
					while((toDel->link)->link!=NULL){   // toDel is prev node to the node (to be deleted)
						toDel=toDel->link;
					}
					free(toDel->link);  // or del toDel->link
					toDel->link=NULL;		
				}
				cout<<"Deleted node from end.";
			}
		}
	
		void view(){
			if(this->START==NULL)
				cout<<"List is empty!";
			else{
				struct node* trvs = START;
				while(trvs!=NULL){
					cout<<trvs->info<<" ";
					trvs= trvs->link;
				}
			}
		}
				
};

int menu(){
	int ch;
	cout<<"\n1. Insert node at start";
	cout<<"\n2. Delete node from end";
	cout<<"\n3. View list";
	cout<<"\n4. Exit";
	cout<<"\n\nPlease, your choice? "; cin>>ch;
	return ch;
}

int main(){
	
	linkedList list;
	while(1){
		system("cls");
		switch(menu()){
			case 1: list.insertNodeAtStart(); break;
			case 2: list.deleteNodeFromEnd(); break;
			case 3: list.view(); break;
			case 4: return 0; break;
			default: {
					cout<<"Invalid Choice!";
					return 1;
			} 	
		}
		getch();
	}
	
	return 0;
}
