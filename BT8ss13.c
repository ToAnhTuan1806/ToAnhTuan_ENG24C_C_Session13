#include<stdio.h>

int findUCLN (int a, int b){
	while(b!=0){
		int c=b;
			b=a%b;
			a=c;
	}
	return a;
}

int main(){
	int num1, num2;
	printf("Nhap so thu nhat: ");
	scanf("%d", &num1);
	printf("Nhap so thu hai: ");
	scanf("%d", &num2);
	
	int ucln=findUCLN(num1, num2);
	printf("Uoc chung lon nhat cua 2 so %d va %d la: %d\n", num1, num2, ucln);	
	return 0;
}
