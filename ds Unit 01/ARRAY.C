#include<stdio.h>
#include<conio.h>
#define max 10

void add(int arr[],int val,int size){
	int i;
	printf("enter %d element\n",size);
	for(i = 0; i < size; i++){
		scanf("%d",&arr[i]);
	}
	printf("element add\n");

	printf("\nelement in the array are :\n");
	for(i = 0;i < size; i++){
		printf("\t%d",arr[i]);
	}
}
void del(int arr[],int size,int val){
	int i,j,found = 0;
	for(i = 0; i < size; i++){
		if(arr[i] == val){
		     found = 1;
		     for(j = i;j < size-1; j++){
			arr[j] = arr[j + 1];
		     }
		     size--;
		     printf("Deleted value :- %d",val);
		     break;
		}
	}
	if(found == 0){
		printf("value %d not found in array.\n",val);
	}
	printf("\nelement in the array are :\n");
	for(i = 0;i < size; i++){
		printf("\t%d",arr[i]);
	}
}
void modify(int arr[],int size,int val){
	int i,val1,found = 0;
	for(i = 0; i < size; i++){
		if(arr[i] == val){
			found = 1;
			printf("enter new value :-");
			scanf("%d",&val1);
			arr[i] = val1;
			printf("Modify..\n");
			printf("%d",arr[i]);
			break;
		}
	}
	 if(found == 0){
		printf("value %d not found in array.\n",val);
	}
	printf("\nelement in the array are :\n");
	for(i = 0;i < size; i++){
		printf("\t%d",arr[i]);
	}

}
void sort(int arr,int size){
	int i,m,j,temp;
	for(i = 0;i < size-1; i++){
		m = i;
		for(j = i+1; j < size; j++){
			if(arr[j] < arr[m]){
				m = j;
			}
			temp = arr[m];
			arr[m] = arr[i];
			arr[i] = temp;
		}
	}
	printf("\nelement in the array are :\n");
	for(i = 0;i < size; i++){
		printf("\t%d",arr[i]);
	}
}
/*void display(int arr[],int size){
	int i;
	printf("\nelement in the array are :\n");
	for(i = 0;i < size; i++){
		printf("\t%d",arr[i]);
	}
} */

void main(){
	int choice,val,size;
	int arr[5];
	clrscr();
	printf("enter the size of array (max %d) :- ",max);
	scanf("%d",&size);
	if(size > max || size <= 0 ){
		printf("invliad size entered. please enter size between 1 and %d.\n",max);
	}
	else{
		add(arr,val,size);
		while(1){
			printf("\n1.Delete \n2.Modify \n3.Exit \nEnter your choice :-");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					printf("enter value to delete :-");
					scanf("%d",&val);
					del(arr,size,val);
					break;
				case 2:
					printf("enter value to modify :-");
					scanf("%d",&val);
					modify(arr,size,val);
					break;
				case 3:
					sort(arr,size);
					break;
				case 4:
					exit(0);
				default:
					printf("invalid choice..\n");
					break;
			}
		}
	}
}