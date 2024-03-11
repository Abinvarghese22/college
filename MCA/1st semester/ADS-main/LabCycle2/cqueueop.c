//Implement Circular Queue operations (Insert, delete, display front & rear values) 04/10/2023
#include<stdio.h>
# define MAX 5
int cqueue_arr[MAX];
int front=-1;
int rear =-1;
void insert(int item)
{
if((front==0 && rear==MAX-1) || (front==rear+1))
{
printf("Queue Overflow \n");
return;
}
if(front==-1)
{
front=0;
rear=0;
}
else
{
if(rear==MAX-1)
rear=0;
else
rear=rear+1;
}
cqueue_arr[rear]=item ;
}
void deletion()
{
if(front==-1)
{
printf("Queue Underflow\n");
return ;
}
printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
if(front==MAX-1)
front=0;
else
front=front+1;
}
}
void display()
{
int front_pos=front,rear_pos=rear;
if(front==-1)
{
printf("Queue is empty\n");
return;
}
printf("Queue elements :\n");
if( front_pos<=rear_pos )
while(front_pos<=rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos<=MAX-1)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
front_pos = 0;
while(front_pos<=rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
}
printf("\nFront element is %d ", cqueue_arr[front]);
printf("\nRear element is %d ", cqueue_arr[rear]);
printf("\n");
}
int main()
{
int ch,item;
do
{
printf("Menu:\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
insert(item);
break;
case 2 :
deletion();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Invalid choice\n");
}
}while(ch!=4);
return 0;
}
