#include <stdio.h>

void displayMenu(){
	printf("\nMENU\n");
    printf("1. Nhap so phan tu va gan gia tri cac phan tu\n");
    printf("2. In ra cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n   a. Tang dan\n   b. Giam dan\n");
    printf("7. Tim kiem phan tu nhap vao\n   a. Tuyen tinh\n   b. Nhi phan\n");
    printf("8. Thoat\n");
}
 

void addAllItem(int arr[], int size){
    int i; 
    for(i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void showItems(int arr[], int length){
    int i; 
    for(i = 0; i < length; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int addItems(int arr[], int size){
    int pos, value, i; 
    printf("Vi tri muon them: ");
    scanf("%d", &pos);
    printf("Them phan tu vao mang: ");
    scanf("%d", &value);
    if(pos >= 0 && pos <= size) {
        for(i = size; i > pos; i--){
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
        printf("Mang sau khi them phan tu: ");
        for(i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Vi tri khong hop le\n");
    }
    return size;
}

void editItem(int arr[], int size){
    int pos, value, i;
    printf("Vi tri muon sua: ");
    scanf("%d", &pos);
    if(pos >= 0 && pos < size){
        printf("Gia tri moi: ");
        scanf("%d", &value);
        arr[pos] = value;
        printf("Mang sau khi sua: ");
        for(i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Vi tri khong hop le\n");
    }
}

int deleteItem(int arr[], int size){
    int pos, i; 
    printf("Vi tri muon xoa: ");
    scanf("%d", &pos);
    if(pos >= 0 && pos < size){
        for(i = pos; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Mang sau khi xoa phan tu: ");
        for(i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Vi tri khong hop le\n");
    }
    return size;
}

void sortItems(int arr[], int size){
    char choice;
    int i, j; 
    printf("Sap xep theo thu tu\n   a. Tang dan\n   b. Giam dan\nLua chon: ");
    scanf(" %c", &choice);
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if((choice == 'a' && arr[i] > arr[j]) || (choice == 'b' && arr[i] < arr[j])){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int size){
    int value, found = 0, i; 
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    for(i = 0; i < size; i++){
        if(arr[i] == value){
            printf("Gia tri %d o vi tri arr[%d]\n", value, i);
            found = 1;
        }
    }
    if(found == 0){
        printf("Khong tim thay gia tri %d trong mang\n", value);
    }
}

void binarySearch(int arr[], int size){
    int value, start = 0, end = size - 1, mid, found = 0; 
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == value){
            printf("Gia tri %d o vi tri arr[%d]\n", value, mid);
            found = 1;
            break;
        } else if(arr[mid] < value){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if(found == 0){
        printf("Khong tim thay gia tri %d trong mang\n", value);
    }
}

int main(){
    int arr[100];
    int choose, size = 0, i;
    char type;

    do {
    	displayMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Moi ban nhap so luong phan tu: ");
                scanf("%d", &size);
                addAllItem(arr, size);
                break;
            case 2:
                showItems(arr, size);
                break;
            case 3:
                size = addItems(arr, size);
                break;
            case 4:
                editItem(arr, size);
                break;
            case 5:                
                size = deleteItem(arr, size);
                break;
            case 6:
                sortItems(arr, size);
                printf("Mang sau khi sap xep: ");
                for(i = 0; i < size; i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 7:
                printf("\nLua chon cach tim kiem\n   a. Tuyen tinh\n   b. Nhi phan\nLua chon: ");
                scanf(" %c", &type);
                if(type == 'a'){
                    linearSearch(arr, size);
                } else if(type == 'b'){
                    sortItems(arr, size);
                    binarySearch(arr, size);
                } else {
                    printf("Lua chon khong hop le\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai");
                break;
        }
    } while(choose != 8);

    return 0;
}

