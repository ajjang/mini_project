#include <stdio.h>
#include <string.h>
#include "productStruct.h"

//메뉴번호를 고르는 함수, return 매뉴 번호
//int selectMenu();

/*
CRUD
C: int addProduct(Product *p) : 성공적으로 Product가 추가된다면 return 1 
R: void listProduct(Product *p[], int curcount),void readProduct(Product p) : 반복문을통해'readProduct'함수로 product정보를 출력한다.
U: int updateScore(Product *p)
D: int deleteProduct(Product *p)
*/

int addProduct(Product *p);
void readProduct(Product p); 
int updateProduct(Product *p);
int deleteProduct(Product *p);
void listProduct(Product *p, int curcount); 
//Product 구조체 멤버정보로 product를 찾는다.
//int selectProduct(Product *p, int count); 
//void searchProduct(Product *p, int count);

//File I/
