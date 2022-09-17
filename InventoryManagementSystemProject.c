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
void purchaseprod(){// function for purchasing a product
	int quant,i;
    char id[10];
    int z=false;
    count=readFile();
	printf("Sell an Item ");
    printf("\nProduct ID: ");
    fflush(stdin);
	gets(id);
    for (i=0; i<count; i++){
        if (strcmp(id,prod[i].id)==0) 	// if the id that the user want to find and the data id that has been saved at file is matched.
        {
        	z=true;
        printf("\nItem found! Containing: \n");//...then display the match
	   	printf("\nProduct name: %s",prod[i].name);
		printf("\nPrice: %.2lfphp\n\n",prod[i].price);

            printf("Enter the quantity you want to buy  : ");
            fflush(stdin);
			scanf("%d",&quant);
            if (quant>prod[i].quantity){		// if the quantity is lessthan the users quant
               puts("\nInsufficient Quantity\nPlease Restock.\n ");
             break; // break and back to the choices.
				}

            float tempSales = prod[i].sales;  // will be executed if the quantity is greater than the users selected quantity.
            prod[i].numSold += quant;
            prod[i].quantity -= quant;
            prod[i].sales = quant*(prod[i].price*(prod[i].discount/100.0));
            prod[i].sales += tempSales;
			}

	}
 if(z==false){	//if the product id is not available.

	printf("Cant find the product id: %s.",id);
}
	writefile();


}
void deleteprod(){ //function for the delete product.
	count=readFile();
	char id[10];
	int i,j;
	int z=false;
printf("Enter the id that you want to be delete : "); //user's input for deleting.
fflush(stdin);
gets(id);

for(i=0;i<count;i++){		//loop to finding the user's input
		z=true;
	if(strcmp(prod[i].id,id)==0){ // if the user's input matched the data
	for( j=i; j<(count-1); j++)	// it will erase the selected data.
			{
				prod[j]=prod[j+1];
			}
			count--;
	}
}
if(z==false){	// will be executed if the product id is not available.
	printf("Cant find product id: %s .",id);
}
writefile();
}
void addProd(){	// function to add products to the file

  	printf("ENTER NEW PRODUCTS\n");
	readFile();		//reading the files .
  	    if (count>0) {
  	    count=readFile();
  		IDChecker(0,count); // to check if the id is already used.
		}
	else{
		printf("\nProduct ID Number: ");
		fflush(stdin);
		gets(prod[count].id);
		}
		printf("Product Name: ");gets(prod[count].name);
		printf("Quantity of the product: ");scanf("%d",&prod[count].quantity);
		printf("Price of the product: ");scanf("%f",&prod[count].price);
		printf("Item Discount: ");scanf("%d",&prod[count].discount);
		++count; // increment count for the product positions and how many are they in the array.

	writefile(); // putting/saving this to the file.
}
