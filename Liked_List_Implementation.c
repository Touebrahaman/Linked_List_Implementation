#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
void append();
void addatbegin();
void insertion();
int length();
void display();
void del();
struct node
{
	int data;
	struct node* link;
};
struct node* root=NULL;
int len;
int main()
{
	int ch;
	while(1)
	{
		printf("1.Append\n");
	printf("2.Add at begin\n");
	printf("3.Insertion\n");
	printf("4.length\n");
	printf("5.display\n");
	printf("6.delete\n");
	printf("7.quit\n");
	
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append();
			break;
		case 2:
			addatbegin();
			break;
		case 3:
			insertion();
			break;
		case 4:
			len=length();
			printf("Length is %d\n",len);
			break;
		case 5:
			display();
			break;
		case 6:
			del();
			break;
		case 7:
			exit(0);
		default:
			printf("invalid choice\n");
			
	}
	}
	
}
void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
		
	}
}

void addatbegin()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}


void insertion()
{
	int loc;
	printf("Enter which location you will insert\n");
	scanf("%d",&loc);
	int len=length();
	if(loc>len)
	{
		printf("This list is having %d nodes\n",len);
	}
	else
	{
		struct node* temp,*p;
		p=root;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data\n");
		scanf("%d",&temp->data);
		int i=1;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
		printf("%d is inserted\n",temp->data);
	}
}

int length()
{
	int count=0;
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}

void display()
{
	struct node* temp;
	temp=root;
	if(temp==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
void del()
{
	int loc,i;
	struct node* temp;
	printf("Enter which location you will delete\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location\n");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		printf("%d is deleted\n",temp->data);
		free(temp);
	}
	else
	{
		int i=1;
		struct node* p,*q;
		p=root;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		printf("%d is deleted\n",q->data);
		free(q);
	}
}
