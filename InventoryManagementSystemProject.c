#include<stdio.h>
#include<string.h>//strlen
#include <stdlib.h>
#define true 0 //true boolean
#define false 1 // for  false the boolean
struct product
	{
		char id[10];   // product code/no.
		char name[20]; // product name
		int  quantity; // remaining quantity of product. Subtract from the original quantity the quantity purchased
        int  numSold;  // initially zero, when no purchase yet.
		float price;   // price of one piece of product
		int discount;  // discount for this product
		float sales;   // accumulated sales, total sales for this product
	};
struct product prod[30];//the maximum array elements.
	int count = 0;	// this will be incremented if there is a new product and this is the
 	FILE *f;	//for the file pointer
