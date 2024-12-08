#include<stdio.h>

int main(){
    int n = 0, position, value;
    int choice;
    int arr[100];
    int check = -1; 

    do {
        printf("\n           MENU          \n");
        printf("1. Nhap so phan tu va gia tri cho mang \n");
        printf("2. In ra gia tri cac phan tu trong mang \n");
        printf("3. Dem so luong cac so nguyen to trong mang \n");
        printf("4. Tim gia tri nho thu 2 trong mang \n");
        printf("5. Them 1 phan tu vao mang \n");
        printf("6. Xoa phan tu tai mot vi tri theo yeu cau \n");
        printf("7. Sap xep mang theo thu tu giam dan \n");
        printf("8. Tim kiem phan tu xem co trong mang hay khong \n");
        printf("9. Xoa toan bo phan tu trung lap trong mang va in ra cac phan tu khong trung lap \n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang \n");
        printf("11. So luong so hoan hao\n");
        printf("12. Tim gia tri lon thu 2\n");
        printf("13. Sap xep va hien thi so chan dung truoc so le dung sau\n");
        printf("14. Sap xep mang theo gia tri tang dan\n");
        printf("15. Thoat chuong trinh \n");
        printf("Lua chon cua ban:    ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                printf("Ban hay nhap kich co cho mang:  ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Kich co khong hop le");
                } else {
                    printf("Ban hay nhap gia tri cho cac phan tu:  \n");
                    for (int i = 0; i < n; i++) {
                        printf("Phan tu thu [%d] la: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            case 2: 
                if (n == 0) {
                    printf("Mang dang rong. Ban hay nhap gia tri cho mang. ");
                } else {
                    printf("Gia tri cac phan tu cua mang la: ");
                    for (int i = 0; i < n; i++) {
                        printf("arr[%d]=%d,  ", i, arr[i]);
                    }
                }
                break;
            case 3: 
                if (n == 0) {
                    printf("Mang dang rong ");
                } else {
                    printf("Cac so nguyen to trong mang la: ");
                    for (int i = 0; i < n; i++) {
                        int isPrime = 1;
                        if (arr[i] <= 1) {
                            isPrime = 0;
                        } else {
                            for (int j = 2; j * j <= arr[i]; j++) {
                                if (arr[i] % j == 0) {
                                    isPrime = 0;
                                    break;
                                }
                            }
                        }
                        if (isPrime) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            case 4: 
                if (n < 2) {
                   printf("Khong hop le\n");
                } else {
                    int min = arr[0], min_2 = arr[1];
                    if (arr[0] > arr[1]) {
                        min = arr[1];
                        min_2 = arr[0];
                    }
                    for (int i = 2; i < n; i++) {
                        if (arr[i] < min) {
                            min_2 = min;
                            min = arr[i];
                        } else if (arr[i] < min_2 && arr[i] != min) {
                                 min_2 = arr[i];
                        }
                    } 
                        printf("Gia tri nho thu trong mang la: %d\n", min_2);
                }
                break;
            case 5: 
                printf("Mang ban dau cua ban la: ");
                for (int i = 0; i < n; i++) {
                    printf("%3d", arr[i]);
                }
                printf("\nBan hay nhap vi tri ma ban muon them phan tu: ");
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le.");
                    break;
                }
                printf("Ban hay nhap gia tri muon them vao mang: ");
                scanf("%d", &value);
                for (int i = n; i > position; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[position] = value;
                n++;
                printf("Mang sau khi duoc them la: ");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", arr[i]);
                }
                break;
            case 6: 
                if (n == 0) {
                    printf("Mang dang rong ");
                } else {
                    printf("Ban hay nhap vi tri ma ban muon xoa phan tu: ");
                    scanf("%d", &position);
                    if (position < 0 || position >= n) {
                        printf("Vi tri khong hop le.");
                    } else {
                        for (int i = position; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        printf("Mang sau khi xoa la: ");
                        for (int i = 0; i < n; i++) {
                            printf("  %d   ", arr[i]);
                        }
                    }
                }
                break;
            case 7: 
                if (n == 0) {
                    printf("Mang dang rong ");
                } else {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = 0; j < n - i - 1; j++) {
                            if (arr[j] < arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                    printf("\nMang sau khi duoc sap xep theo thu tu giam dan : ");
                    for (int i = 0; i < n; i++) {
                        printf("%3d", arr[i]);
                    }
                }
                break;
            case 8: 
                if (n == 0) {
                    printf("Mang dang rong ");
                } else {
                    printf("Ban muon tim kiem phan tu nao trong mang : ");
                    scanf("%d", &value);
                    check = -1;
                    for (int i = 0; i < n; i++) {
                        if (value == arr[i]) {
                            check = 1;
                            position = i;
                            break;
                        }
                    }
                    if (check == 1) {
                        printf("Co phan tu %d trong mang tai vi tri %d\n", value, position);
                    } else {
                        printf("Phan tu khong co trong mang.\n");
                    }
                }
                break;
            case 9: 
                if (n == 0) {
                	
                    printf("Mang dang rong\n");
                } else {
                    for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (arr[i] == arr[j]) {
                                arr[j] = arr[n - 1];
                                n--;
                                j--;
                            }
                        }
                    }
        
                printf("Cac phan tu khong trung lap trong mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                }
                break;
            case 10: 
                if (n == 0) {
                    printf("Mang dang rong khong the dao nguoc. ");
                } else {
                    printf("Mang dao nguoc la: ");
                    for (int i = n - 1; i >= 0; i--) {
                        printf("%3d", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 11: 
                if (n == 0) {
                     printf("Mang dang rong\n");
                } else {
                    int count = 0;
                    for (int i = 0; i < n; i++) {
                         int uoc = 0;
                        for (int j = 1; j <= arr[i] / 2; j++) {
                            if (arr[i] % j == 0) {
                                uoc += j;
                            }
                        }
                        if (uoc == arr[i]) {
                            count++;
                        }
                    }
                    printf("So luong so hoan hao trong mang: %d\n", count);
                }
                break;
            case 12: 
                if (n < 2) {
                   printf("Khong hop le\n");
                } else {
                    int min = arr[0], min_2 = arr[1];
                    if (arr[0] < arr[1]) {
                        min = arr[1];
                        min_2 = arr[0];
                    }
                    for (int i = 2; i < n; i++) {
                        if (arr[i] > min) {
                            min_2 = min;
                            min = arr[i];
                        } else if (arr[i] < min_2 && arr[i] != min) {
                                 min_2 = arr[i];
                        }
                    } 
                        printf("Gia tri lon thu trong mang la: %d\n", min_2);
                }
                break;
            case 13: 
                if (n == 0) {
                    printf("Mang dang rong.\n");
                } else {
                    int temp, j = 0;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                            j++;
                        }
                    }   
                    printf("Mang sau khi phan loai: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } 
                break;
            case 14: 
                if (n == 0) {
                    printf("Mang dang rong ");
                } else {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = 0; j < n - i - 1; j++) {
                            if (arr[j] > arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                    printf("\nMang sau khi duoc sap xep theo gia tri tang dan : ");
                    for (int i = 0; i < n; i++) {
                        printf("%3d", arr[i]);
                    }
                }
                break;
            case 15:
                return 0;
            default:
                printf("Ban hay nhap lai nhe. \n");
        }
    } while(choice != 15);
    return 0;
}

