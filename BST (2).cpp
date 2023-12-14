#include<iostream>
using namespace std;
struct node {
	int info;
	node *lchild;
	node *rchild;
};
node *root,*even,*odd;
void find(int data, node **parent, node **loc,node **r){
	node *ptr, *ptrsave,*r1=*r;
	if(*r==NULL){
		*loc=NULL;
		*parent=NULL;
		return;
	}
	if(data==r1->info){
		*loc=*r;
		*parent=NULL;
		return;
	}
	
	if(data<r1->info){
		ptr=r1->lchild;
	}
	else{
		ptr=r1->rchild;
	}
	ptrsave=*r;
	
	while(ptr!=NULL){
		if(data==ptr->info){
			*loc=ptr;
			*parent=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(data<ptr->info){
			ptr=ptr->lchild;
		}
		else{
			ptr=ptr->rchild;
		}
	}
	*loc=NULL;
	*parent=ptrsave;
}
void insert(int data,node **r){
	node *temp,*parent,*location,*r1=*r;
	find(data,&parent,&location,r);
	if(location!=NULL){
		cout<<"Already Present";
		return;
	}
	temp=new node();
	temp->info=data;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(parent==NULL){
		*r=temp;
	}
	else{
		if(data<parent->info){
			parent->lchild=temp;
		}
		else{
			parent->rchild=temp;
		}
	}
}
case_a(node *par, node *loc)
{
	if(par==NULL)
	{
		root==NULL;
	}
	else
	{
		if(loc==par->lchild)
		{
			par->lchild==NULL;
		}
		else
		{
			par->rchild==NULL;
		}
	}
}
case_b(node *par, node *loc)
{
	node *child;
	if(loc->lchild!=NULL)
	{
		child=loc->lchild;
	}
	else
	{
		child=loc->rchild;
	}
	if(par==NULL)
	{
		root==child;
	}
	else
	{
		if(loc==par->lchild)
		{
			par->lchild=child;
		}
		else
		{
			par->rchild=child;
		}
	}
}
case_c(node *par,node *loc)
{
	node *ptr,*ptrsave,*suc,*parsuc;
	ptrsave=loc;
	ptr=loc->rchild;
	while(ptr->lchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	parsuc=ptrsave;
	if(suc->lchild==NULL&&suc->rchild==NULL)
	{
		case_a(parsuc,suc);
	}
	else
	{
		case_b(parsuc,suc);
	}
	if(par==NULL)
	{
		root=suc;
	}
	else
	{
		if(loc==par->lchild)
		{
			par->lchild=suc;
		}
		else
		{
			par->rchild=suc;
		}
	}
	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}
void del(int item,node **r)
{
	node *location,*parent;
	if(*r==NULL)
	{
		cout<<"The Tree is Empty"<<endl;
		return;
	}
	find(item,&parent,&location,r);
	{
		if(location==NULL)
		{
			cout<<"The item is not present in the tree"<<endl;
			return;
		}
	}
	if(location->lchild==NULL&&location->rchild==NULL)
	{
		case_a(parent,location);
	}
	if(location->lchild!=NULL&&location->rchild==NULL)
	{
		case_b(parent,location);
	}
	if(location->lchild==NULL&&location->rchild!=NULL)
	{
		case_b(parent,location);
	}
	if(location->lchild!=NULL&&location->rchild!=NULL)
	{
		case_c(parent,location);
	}
	delete location;
		
}

void preorder(node *ptr)
{
	if(ptr!=NULL)
	{
		cout<<" "<<ptr->info;
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		cout<<" "<<ptr->info;
		inorder(ptr->rchild);
		
	}
}
void postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		cout<<" "<<ptr->info;
	}
}
void value_greate_than_x(int x,node *ptr){
		if(ptr!=NULL)
	{
		value_greate_than_x(x,ptr->lchild);
		if(ptr->info > x){
			cout<<" "<<ptr->info;
		}
		value_greate_than_x(x,ptr->rchild);
	}
}
int number_of_nodes(node *ptr){
	static int count=0;
	if(ptr!=NULL)
	{
		count++;
		number_of_nodes(ptr->lchild);
		number_of_nodes(ptr->rchild);
	}
	return count;
}
int height(node *root){
	int h=0;
	if(root!=NULL){
		int Lheight=height(root->lchild);
		int Rheight=height(root->rchild);
		int maxheight= max(Lheight,Rheight);
		h= maxheight+1;
	}
	return h;
}
void even_and_odd(node **r){
	node *r1=*r;
	if(*r!=NULL)
	{
		if(r1->info % 2==0){
			insert(r1->info,&even);
		}
		else{
			insert(r1->info,&odd);
		}
		even_and_odd(&r1->lchild);
		even_and_odd(&r1->rchild);
	}
}
void display_terminal_node(node *r){
	if(r!=NULL){
		if(r->lchild==NULL && r->rchild==NULL){
			cout<<r->info<<endl;
		}
	display_terminal_node(r->lchild);
	display_terminal_node(r->rchild);	
	}	
}
int count_noof_nodes(node *ptr)
{
	int n=1;
	if(ptr!=NULL)
	{
		if(ptr!=NULL )
		{
			n++;
		}
		count_noof_nodes(ptr->lchild);
		count_noof_nodes(ptr->rchild);	
	}
	return n;
}
void greater_than_x(node *ptr,int x)
{
	if(ptr!=NULL)
	{
		if(ptr->info>x){
		cout<<" "<<ptr->info<<endl;	
		}
		greater_than_x(ptr->lchild, x);
		greater_than_x(ptr->rchild, x);
	}
}
void one_child(node *ptr)
{
	if(ptr!=NULL)
	{
		if((ptr->lchild!=NULL && ptr->rchild==NULL ) || (ptr->rchild!=NULL && ptr->lchild==NULL ))
		{
			cout<<ptr->info<<endl;
		}
		one_child(ptr->lchild);
		one_child(ptr->rchild);
	}
}
void two_child(node *ptr)
{
	if(ptr!=NULL)
	{
		if(ptr->lchild!=NULL && ptr->rchild!=NULL)
		{
			cout<<ptr->info<<endl;
		}
		two_child(ptr->lchild);
		two_child(ptr->rchild);
	}
}
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->info << " " ;
    else if (level > 1) {
        printCurrentLevel(root->lchild, level - 1);
        printCurrentLevel(root->rchild, level - 1);
    }
} 
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}
int main(){
	int choice,num;
	char choice1;
	root=NULL;
	do{
		cout<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Delete"<<endl;
		cout<<"3.Inorder Traversal"<<endl;
		cout<<"4.preorder Traversal"<<endl;
		cout<<"5.postorder Traversal"<<endl;
		cout<<"6.Value Greater than x"<<endl;
		cout<<"7.Total Number Of Nodes"<<endl;
		cout<<"8.Height"<<endl;
		cout<<"9.Even Odd Tree"<<endl;
		cout<<"10.Display Terminal Nodes"<<endl;
		cout<<"11.Count"<<endl;
		cout<<"12.Display Nodes Greater Than x"<<endl;		
		cout<<"13.Display One Child"<<endl;		
		cout<<"14.Display Two Child"<<endl;		
		cout<<"15.Dislay Level Order"<<endl;		
		cout<<"16.Dislay Level entered by user"<<endl;		
		cout<<"17.Exit"<<endl;
		cin>>choice;
		switch(choice){
//			case 1:{
//				cout<<"Enter The Number To be Inserted"<<endl;
//				cin>>num;
//				insert(num,&root);
//				break;
//			}
//			case 2:{
//				cout<<"Enter The Number To be Deleted"<<endl;
//				cin>>num;
//				del(num,&root);
//				break;
//			}
			case 3:{
				inorder(root);
				break;
			}
			case 4:{
				preorder(root);
				break;
			}
			case 5:{
				postorder(root);
				break;
			}
			case 6:{
				cout<<"Enter The Number X"<<endl;
				cin>>num;
				value_greate_than_x(num,root);
				break;
			}
			case 7:{
			int n= number_of_nodes(root);
			cout<<"Total Number Of Nodes are: "<<n<<endl;
			break;
			}
			case 8:{
				int n=height(root);
				cout<<"Height of Tree is: "<<n<<endl;
				break;
			}
			case 9:{
				even_and_odd(&root);
				
				cout<<"Even Numbers Are:"<<endl;
				inorder(even);
				cout<<endl;
				cout<<"odd Numbers Are:"<<endl;
				inorder(odd);
				break;
			}
			case 10:{
				cout<<"Terminal Nodes are:"<<endl;
				display_terminal_node(root);
				break;
			}
			case 11:{
				int count=count_noof_nodes(root);
				cout<<"Total Number Of Nodes are: "<<count<<endl;
				break;
			}
			case 12:{
				int data;
				cout<<"Enter number x"<<endl;
				cin>>data;
				greater_than_x(root,data);
				break;
			}
			case 13:{
				cout<<"One child nodes are"<<endl;
				one_child(root);
				break;
			}
			case 14:{
				cout<<"Two Child nodes are"<<endl;
				two_child(root);
				break;
			}
			case 15:{
				cout<<"Nodes in Level Order "<<endl;
				printLevelOrder(root);
				break;
			}
			case 16:{
				cout<<"Enter Level"<<endl;
				int level;
				cin>>level;
				printCurrentLevel(root,level);
				break;
			}
			case 17:{
			exit(0);
			break;
			}			
		}
		cout<<endl<<"continue(y/n)"<<endl;
		cin>>choice1; 
	}while(choice1!='n');

}
