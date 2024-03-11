#include<stdio.h>
int arr[10], top=-1, n;

void push(){
	if(top >= n){
		printf("Stack is overflow.");
	}
	else 
	{
		int data;
		printf("Enter the data : ");
		scanf("%d", &data);
		top += 1;
		arr[top] = data;
	}
}

void pop(){
	if(top < 0){
		printf("Stack is underflow.");
	}
	else 
	{
		top -= 1;
	}
}

void display(){
	if(top < 0){
		printf("Stack is underflow.");
	}
	else 
	{
		for(int i = top; i >= 0; i--){
			printf("%d ", arr[i]);
		}
	}
}

int main(){
	int choice=0;
	printf("Enter the array limit : ");
	scanf("%d", &n);
	while(choice != 4){
		printf("Enter the choice 1 - push, 2 - pop, 3 - display, 4 - exit");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				push();
				break;
			case 2:
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				exit();
				break;
			default:
				printf("Invalid entry!");
		}
	}
}

