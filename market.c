#include <stdio.h>
#include "product.h"
#include "manager.h"
#define DEBUG

int main(){
	Product product[100];
	int count=0;
	count= loadData(product);
	
	while(1){
		int num;
		num= selectMenu();

	        if(count==0){
			if(num==2||num==3||num==4){
				printf("There is no product!\n");
				continue;
			}
		}

		if(num==0){
			break;
		}
		else if(num==1){
			#ifdef DEBUG
				printf("Debug: call %s %d\n",__FILE__,__LINE__);
			#endif
				int curcount=addProduct(&product[count]);
				count= count+curcount;
		}
		else if(num==2){
			#ifdef DEBUG
				printf("Debug: call %s %d\n",__FILE__,__LINE__);
			#endif
				listProduct(product, count);
		}
		else if(num==3){
			#ifdef DEBUG
				printf("Debug: call %s %d\n",__FILE__,__LINE__);
			#endif
				int ask= selectProduct(product, count);
				updateProduct(&product[ask-1]);
		}
		else if(num==4){
			char answer;
			printf("정말로 취소하시겠습니까?(y/n)");
			getchar();
			scanf("%c",&answer);
			if(answer=='y'){
				#ifdef DEBUG
					printf("Debug: call %s %d\n",__FILE__,__LINE__);
				#endif
					int ask= selectProduct(product, count);
					deleteProduct(&product[ask-1]);
					printf("삭제됨!\n");
			}
			else printf("취소됨!\n");
		}
		else if(num==5){
			if(count==0) printf("저장할 데이터가 없습니다!\n");
			else{
				saveData(product, count);
				printf("=> 저장 성공!\n");
			}
		}
		else if(num==6){
			int ask;
			printf("무엇을 검색하시겠습니까?\n1.제품이름\n2.제품표준가격\n3.제품별점\n(번호 입력)>> ");
			scanf("%d",&ask);
			
			if(ask==1) searchName(product, count);
			if(ask==2) searchStandardPrice(product, count);
			if(ask==3) searchStar(product, count);
			else {
				//printf("잘못된 번호입니다.\n");
			}
		}
		else{
			printf("Wrong numbber!!\n");
		}
	}
	return 0;
}	
