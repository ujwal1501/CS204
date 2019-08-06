
#include<iostream>
#include<cstdlib>
using namespace std;

struct node* head=NULL;

struct node
{
	int x;
	int y;
	node *next;
};

void Addfirst(int x,int y)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		cout<<-1<<endl;
		return;
	}
	new_node->x=x;
	new_node->y=y;
	new_node->next= (head);
	(head) = new_node;

}

void DelFirst()
{
	if(head==NULL)
	{cout<<"empty linked list";return;}

	node* temp=head;
	head=head->next;
	delete(temp);

}

int Del(int x,int y)
{
	if(head==NULL)
	{cout<<"empty linked list";return -1;}
	struct node* temp=head;
	struct node* prev=NULL;
	if((head->x)==x && (head->y==y))
	{
		head=temp->next;
		free(temp);
		return 0 ;
	}

	for(int i=0;temp!=NULL;i++)
	{
		if((temp->x)==x && (temp->y)==y)
		{
			break;
		}
		prev=temp;
		temp=temp->next;
	}

	if(temp==NULL)
	{return -1;}
	else return 0;
	struct node* next=temp->next;
	free(temp);
	prev->next=next;

}

void Search(int d)
{
	struct node* temp=head;
	if(temp==NULL)
	cout<<"EMPTY LIST"<<endl;
	while(temp!=NULL)
	{
		if(((temp->x)*(temp->x)+(temp->y)*(temp->y))<=d*d)
		{
			cout<<"("<<(temp->x)<<","<<(temp->y)<<")";

		}
	temp=temp->next;
	}
}

int Search(int x,int y)
{
	struct node* temp=head;
	int nots=0;
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		while(temp!=NULL)
		{
			if((temp->x==x)&&(temp->y==y))
			{
				nots++;

			}
			temp=temp->next;
		}

	}

	return nots;
}

int length()
{
	struct node* temp=head;
	int l=0;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
	return l;
}

int main()
{
    int op;
    cin>>op;

	while(op--)
	{
		int a;
		cin>>a;
		if(a==1)
		{
			int x,y;
			cin>>x>>y;
			Addfirst(x,y);
		}

		else if(a==2)
		{
			DelFirst();
		}

		else if(a==3)
		{
			int x,y;
			cin>>x>>y;
			Del(x,y);
		}

		else if(a==4)
		{
			int d;
			cin>>d;
			Search(d);
			cout<<endl;
		}

		else if(a==5)
		{
			int x,y;
			cin>>x>>y;
			cout<<Search(x,y)<<endl;
		}

		else if(a==6)
		{
			cout<<length()<<endl;

		}


	}
}
