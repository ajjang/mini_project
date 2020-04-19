#include "manager.h"

int selectMenu(){
	int num;
	printf("======================\n");
	printf("Test CRUD functions\n");
	printf("1. add Product\n");
	printf("2. read Product\n");
	printf("3. update Product\n");
	printf("4. deleteProduct\n");
	printf("5. save Product\n");
	printf("6. search Product\n");
	printf("0. quit\n");
	printf("which num? >>");
	scanf("%d",&num);	
	printf("======================\n");

	return num;
}

int selectProduct(Product* product, int count){
	int ask;
	listProduct(product, count);
	printf("제품번호는 무엇입니까?");
	scanf("%d",&ask);

	return ask;
}

void saveData(Product *product, int count){
	FILE *fp;
	fp= fopen("product.txt", "w");
	
	for(int i=0; i<count; i++)
	{
		if(product[i].sprice != -1){
	        	fprintf(fp,"%-10s%-8d%-8d%-15d%-8d\n",product[i].name,product[i].weight,product[i].sprice,product[i].price,product[i].stars);
	
		}
	}
}

int loadData(Product product[])
{
	int count=0;
	FILE *fp;

	fp=fopen("product.txt","r");
	if(fp==NULL){
		printf("=> 파일 없음!\n");
		return 0;
	}
	for( ; ;count++){
	       	fscanf(fp,"%s %d %d %d %d",product[count].name,&product[count].weight,&product[count].sprice,&product[count].price,&product[count].stars);
			if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩 성공!\n");
	return count;
}

void searchName(Product *product, int count){
	char search[20];
	printf("찾고싶은 제품이름은?: ");
	scanf("%s",search);
	
	printf("==========================================\n");
	printf("name\tweight price\ttotal\tstars\n");
	for(int i=0; i<count; i++){
		if(product[i].sprice != -1){
			if(strstr(product[i].name, search))
				readProduct(product[i]);
		}
	}
}

void searchStandardPrice(Product *product, int count){
	int search;
	printf("찾고싶은 제품 표준가격은?: ");
	scanf("%d",&search);

	printf("==========================================\n");
	printf("name\tweight price\ttotal\tstars\n");
	for(int i=0; i<count; i++){
		if(product[i].sprice != -1){
			if(product[i].sprice == search) readProduct(product[i]);
		}
	}
}

void searchStar(Product *product, int count){

	int search;
	printf("찾고싶은 제품 별점은?: ");
	scanf("%d",&search);

	printf("=========================================\n");
	printf("name\tweight price\ttotal\tstars\n");
	for(int i=0; i<count; i++){
		if(product[i].sprice != -1){
			if(product[i].stars == search) readProduct(product[i]);
		}
	}
}
