#include "product.h"


//ljCRUD 함수들
int addProduct(Product *p){
        int num;
        printf("제품 이름은?>>");
        scanf("%s",p->name);

        printf("제품 중량은?>>");
        scanf("%d",&(p->weight));

        printf("제품 가격은?>>");
        scanf("%d",&(p->sprice));

        printf("제품 개수는?>>");
        scanf("%d",&num);
        p->price= num*p->sprice;

        printf("제품 별점은 얼마?>>");
        scanf("%d",&(p->stars));

        return 1;
}
void readProduct(Product p){
	if(p.sprice!=-1){
        	printf("%-10s%-8d%-8d%-8d%-8d\n",p.name,p.weight,p.sprice,p.price,p.stars);
	}else{
		printf("삭제되었습니다..\n");
	}
}  
int updateProduct(Product *p){
        int num;
        printf("제품 이름은?>>");
        scanf("%s",p->name);

        printf("제품 중량은?>>");
        scanf("%d",&(p->weight));

        printf("제품 가격은?>>");
        scanf("%d",&(p->sprice));

        printf("제품 개수는?>>");
        scanf("%d",&num);
        p->price= num*p->sprice;

        printf("제품 별점은 얼마?>>");
        scanf("%d",&(p->stars));

        return 1;
}
int deleteProduct(Product *p){
	p->sprice=-1;
	return 1;
}

void listProduct(Product *p, int curcount ){
	printf("num\tname\tweight price\ttotal\tstars\n");
	for(int i=0; i<curcount; i++){
		printf("%d\t",i+1);
		readProduct(p[i]);
	}
}

