#include<stdio.h>

int linearSearch(int arr[], int n, int key){
	for(int i = 0; i<n; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

int binarySearch(int array[], int key, int low, int high){
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (array[mid] == key)
            return mid;
            
        if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(){
	int n=5, key, choice=0, isKey;
	int arr[n];
	printf("Enter the array elements : ");
	for(int i = 0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	
	while(choice != 3){
		printf("\nEnter the choice 1 - Linear search 2 - Binary search 3 - Exit : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter the key : ");
				scanf("%d", &key);
				isKey = linearSearch(arr, n, key);
				if(isKey == -1){
					printf("Not found!");
				}else{
					printf("Key found at %d", isKey+1);
				}
				break;
			case 2:
				printf("Enter the key : ");
				scanf("%d", &key);
				isKey = binarySearch(arr, key, 0, n-1);
				if(isKey == -1){
					printf("Not found!");
				}else{
					printf("Key found at %d", isKey+1);
				}
				break;
			case 3:
				printf("Exiting..");
				break;
		}
	}
}

