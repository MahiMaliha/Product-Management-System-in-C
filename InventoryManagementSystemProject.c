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
nt writefile()//write file function
{
    int i;
    f = fopen("inventory.txt", "w");  // ayaw i append; change from f = fopen("inventory.txt", "a");
    if (f == NULL)
        return -1;
    fprintf(f, "%d\n", count);
    for (i = 0; i < count; ++i) // writing all the details from all the function to the text file.
    {
        // Changed
        fputs(prod[i].id, f);
        fprintf(f, "\n");
        fputs(prod[i].name, f);
        fprintf(f, "\n");
        fprintf(f, "%d\n", prod[i].quantity);
        fprintf(f, "%d\n", prod[i].numSold);
        fprintf(f, "%f\n", prod[i].price);
        fprintf(f, "%d\n", prod[i].discount);
        fprintf(f, "%f\n", prod[i].sales);
    }
    fclose(f);
    return 0;
}
int readFile() // read file function
{
    int n = 0;
    int i;
    f = fopen("inventory.txt", "r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; ++i)
    {
        fgets(prod[i].id, 10, f);
        prod[i].id[strlen(prod[i].id) - 1] = 0; // remove new lines
        fgets(prod[i].name, 20, f);
        prod[i].name[strlen(prod[i].name)-1] = 0; // remove new lines
        fscanf(f, "%d", &prod[i].quantity);
        fscanf(f, "%d", &prod[i].numSold);
        fscanf(f, "%f", &prod[i].price);
        fscanf(f, "%d", &prod[i].discount);
        fscanf(f, "%f\n", &prod[i].sales);
    }
    fclose(f);
    return n;
}
void disZeroQuant(){ // for the switch number 7= calling all the product id with zero quantity.
		int i;

       count= readFile();	// call the read function
         printf("\nProducts with zero Quantity: ");
        for (i=0; i<count; i++){
		if(prod[i].quantity==0){// printing the highest product.
    printf("\nName of the product: %s \nProduct Id: %s \nQuantity left: %d \nNumber of product sold: %d \nPrice of the product: %.2f \nDiscount of the product: %d %% \nTotal Sales: %.2lf\n",prod[i].name,prod[i].id,prod[i].quantity,prod[i].numSold,prod[i].price,prod[i].discount,prod[i].sales);
		}
     }
writefile();

}
void dispHsale(){ // to display the highest sale function
	int high,i;
	 high=prod[0].numSold; // getting the first element of the array that has been sold
     for(i=0;i<count;i++) // loop for the num item sold.
     {
          if(prod[i].numSold>high)	//if the element containts the highest sold product.
          high=prod[i].numSold;//it will pass on the high variable.
     }
        printf("\nThe Highest Product Sale is: \n");
   	for(i=0;i<count;i++) // loop to search the highest sold product.
     {
    if(prod[i].numSold==high)// printing the highest product.
    printf("Name of the product: %s \nProduct Id: %s \nQuantity left: %d \nNumber of product sold: %d \nPrice of the product: %.2f \nDiscount of the product: %d %% \nTotal Sales: %.2lf\n",prod[i].name,prod[i].id,prod[i].quantity,prod[i].numSold,prod[i].price,prod[i].discount,prod[i].sales);
     }

}
