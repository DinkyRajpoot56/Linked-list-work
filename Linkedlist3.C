#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head;
int create()
{
	struct node *temp,*ptr;
	int n,i;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("No memory allocation");
	head=temp;
	printf("Enter your data:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	printf("How many node in LL:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter your data\n:");
		scanf("%d",&ptr->data);
		ptr->link=NULL;
		temp->link=ptr;
		temp=temp->link;
	}

}
int display()
{
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->link;
	}
}
int insertatbeg(int item)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	int data;
	printf("Enter the data:");
	scanf("%d",&item);
	ptr->data=item;
	if(head==NULL)
	ptr->link=NULL;
	else
	ptr->link=head;
	head=ptr;
	
}
int insertatlast(int item)
{
    struct node *ptr,*temp1;
	ptr=(struct node*)malloc(sizeof(struct node));
	int data;
	printf("Enter the data:");
	scanf("%d",&item);
	ptr->data=item;
	ptr->link=NULL;
	if(head==NULL)
	{head=ptr;
	}
	else
	{
		temp1=head;
		while(temp1->link!=NULL)
		{ temp1=temp1->link;
		}
		temp1->link=ptr;
	}
}
int insertpos(node *head,int item)
{
	struct node *ptr,*loc;
	int data;
	int k,temp;
	loc=head;
	printf("Enter the element");
	scanf("%d",&item);
	for(k=0;k<temp;k++)
	{
		loc=loc->link;
		if(loc==NULL)
		{
		   printf("Node in the list at less than one\n");
		   return item;	
		}
	}
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	ptr->link=loc->link;
	loc->link=ptr;
}
int delete_beg()
{
	struct node *ptr;
	printf("Delete the item\n");
	if(head==NULL)
	printf("List is empty");
	else
	{
		ptr=head;
		head=head->link;
		printf("Node deleted isn = %d\n",ptr->data);
		free(ptr);
	}
}
int delete_end()
{
	struct node *ptr,*loc;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=head;
		loc=head;
		while(ptr->link!=NULL)
		{
			loc=ptr;
			ptr=ptr->link;
		}
		if(ptr==head)
		{
			head==NULL;
		}
		else
		{
			loc->link=NULL;
		}
		free(ptr);
		printf("Successfully deleted last node");
	}
	
}
int delspec()
{
	struct node *ptr,*temp;
	int i,loc;
	printf("Enter the position to delete\n");
	scanf("%d",&loc);
	if(head==NULL)
	{
		printf("Empty list");
	}
	else
	{
		ptr=head;
		for(i=1;i<=loc;i++)
		{
			temp=ptr;
			ptr=ptr->link;
		}
		printf("Node deleted is =%d",ptr->data);
		temp->link=ptr->link;
		free(ptr);
	}
}
int main()
{
	create();
	delete_end();
	display();
}
