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
	fp= fopen("product.txt", "wt");
	
	for(int i=0; i<count; i++)
	{
		if(product[i].price != -1){
	        	fprintf(fp,"%-10s%-8d%-8d%-15d%-8d\n",product[i].name,product[i].weight,product[i].sprice,product[i].price,product[i].stars);
	
		}
	}
}

int loadData(Product p[])
{
	int count= 0;
	FILE *fp;

	fp=("product.txt","rt");
	if(fp==NULL){
		printf("=> 파일 없음!\n");
		return 0;
	}
	for(int i=0;i<=count ;count++){
	       	fscanf(fp,"%-10s%-8d%-8d%-15d%-8d\n",product[i].name,product[i].weight,product[i].sprice,product[i].price,product[i].stars);
			if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩 성공!\n");
	return count;
}
}
