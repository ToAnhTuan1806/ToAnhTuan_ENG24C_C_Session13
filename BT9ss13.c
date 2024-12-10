#include<stdio.h>

void displayMenu(){
	printf("\nMENU\n");
	printf("1. Nhap gia tri cac phan tu cua mang\n");
	printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
	printf("3. In ra cac phan tu o goc theo ma tran\n");
	printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
	printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
	printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
	printf("7. Thoat\n");
}

void valueArr(int n, int m, int arr[n][m]){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("arr[%d][%d] = ", i,j);
			scanf("%d", &arr[i][j]);
		}
	}	
}

void printfElement(int n, int m, int arr[n][m]){
	printf("Gia tri cac phan tu cua mang:\n");
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void printElementCorner(int n, int m, int arr[n][m]){
	printf("Cac phan tu nam o goc:\n");
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if ((i==0 && j==0) || (i==0 && j==m-1) || 
                (i==n-1 && j==0) || (i==n-1 && j==m-1)) {
                	printf("%d ", arr[i][j]);
				} else {
					printf("0 ");
				}
		}
		printf("\n");
	}
}

void printfElementSideline(int n, int m, int arr[n][m]){
	printf("Cac phan tu nam tren duong bien:\n");
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(i==0 || i==n-1 || j==0 || j==m-1){
				printf("%d ", arr[i][j]);
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

void printfElementDiagonal(int n, int m, int arr[n][m]){
	printf("Cac phan tu nam tren duong cheo chinh vao cheo phu:\n");
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(i==j || i+j == n-1 ){
				printf("%d ", arr[i][j]);
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int checkPrime(int num){
	int i;
    if (num<2) return 0;
    for (i=2; i*i<=num; i++) {
        if(num%i==0) return 0;
    }
    return 1;
}

void printfElementPrime(int n, int m, int arr[n][m]){
	printf("Cac phan tu la so nguyen to:\n");
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(checkPrime(arr[i][j])){
				printf("%d ", arr[i][j]);
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main(){
	int n, m;
	printf("Nhap so hang: ");
	scanf("%d", &n);
	printf("Nhap so cot: ");
	scanf("%d", &m);
	int arr[n][m];
	int choice;
	do{
		displayMenu();
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				valueArr(n, m, arr);
				break;
			case 2:
				printfElement(n, m, arr);
				break;
			case 3:
				printElementCorner(n, m, arr);
				break;
			case 4:	
				printfElementSideline(n, m, arr);	
				break;	
			case 5:
				printfElementDiagonal(n, m, arr);
				break;
			case 6:
				printfElementPrime(n, m, arr);
				break;
			case 7:
			printf("Thoat chuong trinh\n");
			break;
			default:
			printf("Lua chon khong hop le. Thu lai");	
		}
		
	}while(choice!=7);
	return 0;
}


