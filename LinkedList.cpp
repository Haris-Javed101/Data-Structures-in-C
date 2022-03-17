#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Node{
		int Info;
		struct Node* Link;
	};
	
class LinkedList{				
	private:		// by the way, default visibility of member variables is **private** 
		struct Node* START;
	
		struct Node* CreateNode()
		{
				struct Node* Tmp = new struct Node; 
				return Tmp;
		} 
	public:
		LinkedList()
		{ 	//constructor function
			this->START=NULL;
		}		
		void InsertNodeAtStart()
		{
			struct Node* Tmp = this->CreateNode();
			cout<<"Enter integer value to insert: "; 
			cin>>Tmp->Info;
			
			if(this->START==NULL)
				Tmp->Link=NULL;
			else // if list is not empty
				Tmp->Link=START;		
			this->START=Tmp;
		}	
		void DeleteNodeFromEnd()
		{	
			if(this->START==NULL)
				cout<<"List is already empty!\n";
			else{
				struct Node* ToDel = this->START;
				if(ToDel->Link==NULL){  // if list has only one node
					delete ToDel;
					this->START=NULL;
				}
				else{  // if list has more than one node		
					while((ToDel->Link)->Link!=NULL){   // ToDel is pointer to the previous node to the node to be deleted
						ToDel=ToDel->Link;
					}
					free(ToDel->Link);  // or del toDel->link
					ToDel->Link=NULL;		
				}
				cout<<"Deleted node from end.";
			}
		}	
		void View()
		{
			if(this->START==NULL)
				cout<<"List is empty!";
			else{
				struct Node* Trvs = START;
				while(Trvs!=NULL){
					cout<<Trvs->Info<<" ";
					Trvs = Trvs->Link;
				}
			}
		}
		~LinkedList()
		{ 	
			/* free heap memory of created object here */
		}
};
int Menu(){
	int Ch;
	cout<<"\n1. Insert node at start";
	cout<<"\n2. Delete node from end";
	cout<<"\n3. View list";
	cout<<"\n4. Exit";
	cout<<"\n\nPlease, your choice? "; cin>>Ch;
	return Ch;
}

int main()
{	
	LinkedList List;
	while(1){
		system("cls");
		switch(Menu()){
			case 1: List.InsertNodeAtStart(); break;
			case 2: List.DeleteNodeFromEnd(); break;
			case 3: List.View(); break;
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
