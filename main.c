#include "item.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5


void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {

	item_list[index].price = price;

	item_list[index].sku = (char *)malloc(strlen(sku) +1);
	strcpy(item_list[index].sku,sku);

	item_list[index].category = (char *)malloc(strlen(category)+1);
	strcpy(item_list[index].category, category);

	item_list[index].name = (char *)malloc(strlen(name) +1);
	strcpy(item_list[index].name, name);

}

void free_items(Item *item_list, int size){
	
	for (int i =0; i<size; i++){
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);

}

double average_price(Item *item_list, int size){

	double sum =0;

	for(int i=0; i < size; i++){

		sum += item_list[i].price;
	}
	return sum / size;


}

void print_items(Item *item_list, int size){

	for (int i = 0; i <size; i++){
		printf("#######################\n");
		printf("Item Name: %s\n", item_list[i].name);
		printf("Item Price: %.2f\n", item_list[i].price);
		printf("Item SKU: %s\n", item_list[i].sku);
		printf("######################\n");	
	}
	printf(		"Average price of items = %.2f\n", 
			average_price(item_list, size));
}


int main(int argc, char *argv[]){

	Item *itemArray = (Item *)malloc(SIZE * sizeof(Item));

	add_item(itemArray, 5.00, "19282", "breakfast", "Reese's Cereal", 0);
	add_item(itemArray, 3.95, "79862", "dairy", "Milk", 1);
	add_item(itemArray, 2.50, "35021", "snacks", "Chips", 2);
	add_item(itemArray, 6.99, "62389", "beverages", "Orange Juice", 3);
	add_item(itemArray, 4.75, "45123", "bakery", "Bread", 4);

	print_items(itemArray, SIZE);

	if (argc >1){
		char *search_sku = argv[1];
		int found = 0;
		
		for (int i =0; i < SIZE; i++){
			if (strcmp(itemArray[i].sku, search_sku)==0){
				printf("\nItem Found: \n");
				printf("####################\n");
				printf("Item Name = %s\n", itemArray[i].name);
				printf("Item SKU = %s\n", itemArray[i].sku);
				printf("Item Category = %s\n", itemArray[i].category);
				printf("Item Price: %.2f\n", itemArray[i].price);
				found =1;
				break;
			}
		}
		if (!found) {
			printf("\nItem with SKU %s not found.\n", search_sku);

		}

	}
	free_items(itemArray, SIZE);
	

	return 0;
}
