#include <stdio.h>
#include <string.h>
//#include "productStruct.h"
int selectMenu();
int selectProduct(Product* product, int count);
int loadData(Product product[]);
void saveData(Product *product, int count);
void searchName(Product *product, int count);
void searchStandardPrice(Product *product, int count);
void searchStar(Product *product, int count);
