#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main(){
	int currentIndex=0;
	int numbers[100];
		int sumNumbers;
		int max,min;
		
	do{
		printf("**************MENU******************\n");
		printf("1. Nhap gia tri n phan tu cua mang\n");
		printf("2. In gia tri cac phan tu trong mang\n");
		printf("3. Tinh tong cac phan tu chia het cho 2 va 3 trong mang\n");
		printf("4. In ra gia tri phan tu lon nhat va nho nhat trong mang\n");
		printf("5. Su dung thuat toan sap xep chen va sap xep mang tang dan\n");
		printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
		printf("7. Sap xep cac phan tu le chia het cho 5 o dau mang theo thu tu giam dan, cac phan tu chan chia het cho 5 o cuoi mang theo thu tu tang dan, cac phan tu con lai o giua theo thu tu giam dan\n");
		printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang, sap xep tang dan\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban la: ");
		int choice; 
		scanf("%d",&choice);
		switch (choice){
			case 1:
				int size;
				printf("Nhap so phan tu cua mang:");
				scanf("%d",&size);
				for(int i=currentIndex;i<size;i++){
					printf("Nhap gia tri cua phan tu number[%d] = ",i);
					scanf("%d",&numbers[i]);
					currentIndex++;
				}
				break;
			case 2:
				printf("Gia tri cac phan tu trong mang la:\n");
				for(int i=0;i<currentIndex;i++){
					printf("%d\t",numbers[i]);
				}
				printf("\n");
				break;
			case 3:
				sumNumbers=0;
				for(int i=0;i<currentIndex;i++){
					if(numbers[i]%2==0&& numbers[i]%3==0){
						sumNumbers+=numbers[i];
					}
				}
				printf("Tong cac so chia het cho 2 va 3 la: %d\n",sumNumbers);
				break;
			case 4:
				max=numbers[0];min=numbers[0];
				for(int i=0;i<currentIndex;i++){
					max=(max<numbers[i])?numbers[i]:max;
					min=(min>numbers[i])?numbers[i]:min;
				}
				printf("Gia tri lon nhat la: %d\n",max);
				printf("Gia tri nho nhat la: %d\n",min);
				break;
			case 5:
				for(int i=0;i<currentIndex;i++){
					int key =numbers[i];
					int j=i-1;
					while(j>=0 && numbers[j]>key){
						numbers[j+1]=numbers[j];
						j=j-1;
					}
					numbers[j+1]=key;
				}
				printf("Sap xep mang tang dan: \n");
				for(int i=0;i<currentIndex;i++){
					printf("%d\t",numbers[i]);
				}
				printf("\n");
				break;
			case 6:			
				sumNumbers = 0;
				printf("Cac so nguyen to trong mang: ");
				for(int i=0;i<currentIndex;i++){
					int isPrime = 0;
					if(numbers[i]>=2){
						for(int j=2;j<=sqrt(numbers[i]);j++){
							if(numbers[i]%j==0){
								isPrime = 1;
								break;
							}
						}
					}else{
						isPrime=1;
					}
					if(isPrime==0){
						printf("%d\t",numbers[i]);
						sumNumbers+=numbers[i];
					}
				}
				printf("\nTong cac so nguyen to la: %d\n",sumNumbers);
				break;
				printf("Tong cac so nguyen to trong mang la: %d",sumNumbers);
				break;
			case 7:
				printf("Em chua kip suy nghi a:((");
				break;
			case 8:
				int addValue,addIndex;
				printf("Nhap vao gia tri can them trong mang:");
				scanf("%d",&addValue);
				printf("Nhap vao chi so can chen vao mang:");
				scanf("%d",&addIndex);
					if(addIndex<0||addIndex>=99){
					printf("Khong the chen phan tu vao chi so %d\n",addIndex);
				}else{
					if(addIndex==currentIndex){
						numbers[currentIndex] = addValue;
						currentIndex++;
					}else if(addIndex>currentIndex){
						for(int i=currentIndex;i<addIndex;i++){
							numbers[i] = 0;
						}
						numbers[addIndex] = addValue;
						currentIndex = addIndex+1;
					}else{
						for(int i=currentIndex;i>addIndex;i--){
							numbers[i] = numbers[i-1];
						}
						currentIndex++;
						numbers[addIndex] = addValue;
					}
				}
				break;
			case 9:
				exit(0);
			default:
				printf("Vui long chon tu 1-9");
		}
	}while(1==1);
}
