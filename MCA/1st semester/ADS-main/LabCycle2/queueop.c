// Implement Queue operations (Insert, delete, display front & rear values) 
#include<stdio.h>
#include <stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
int queue_array[MAX];
int rear=-1;
int front=-1;
int main()
{
int ch;
while(1)
{
printf("Menu: \n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Diplay\n");
printf("4.Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
       insert();
       break;
case 2:
       delete();
       break;
case 3:
       display();
       break;
case 4:
       exit(1);  
default:
       printf("Invalid Choice!");                  
}
}
}
void insert()
{
int item;
if(rear==MAX-1)
printf("Queue Overflow\n");
else
 {
  if(front==-1)
  front=0;
  printf("Insert element to queue\n");
  scanf("%d",&item);
  rear=rear+1;
  queue_array[rear]=item;
 }
}
void delete()
{
if(front==-1|| front>rear)
{
printf("Queue is Underflow\n");
return ;
}
else
{
printf("Element deleted from queue is %d\n",queue_array[front]);
front=front+1;
}
}
void display()
{
int i;
if(front==-1)
printf("Queue is empty");
else
printf("Queue is: \n");
for(i=front;i<=rear;i++)
{
printf("%d",queue_array[i]);
printf("\nFront element is %d ", queue_array[front]);
printf("\nRear element is %d ", queue_array[rear]);
printf("\n");
}
}






















