#include<stdio.h>

void displayArray(int rows, int cols, int arr[rows][cols]){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){		
			printf("arr[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}	
}

void printfArray(int rows, int cols, int arr[rows][cols]){
	printf("In ma tran:\n");
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int rows, cols;
	printf("Nhap so hang: ");
	scanf("%d", &rows);
	printf("Nhap so cot: ");
	scanf("%d", &cols);
	
	int array[rows][cols];
	displayArray(rows, cols, array);
	printfArray(rows, cols, array);
	return 0;
}
