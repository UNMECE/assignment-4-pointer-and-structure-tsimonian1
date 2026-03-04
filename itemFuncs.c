#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "item.h"

void add_item(Item *it, double price, const char *sku, char *category, char *name, int index)	{
	it[index].sku = strdup(sku);
	it[index].name = strdup(name);
	it[index].category = strdup(category);
	it[index].price = price;
}

void free_items(Item *item_list, int size)	{
	for(int i=0; i<size; i++)	{
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
}

void print_item(Item *item_list, int size)	{
	for(int i=0;i<size;i++)	{
	printf("Name: %s\nSKU: %s\nCategory: %s\nPrice:$%0.2f\n", item_list[i].name, item_list[i].sku, item_list[i].category, item_list[i].price);
	printf("##############\n");	
}
}

double average_price(Item *item_list, int size)	{
	double sum = 0.00;
	for(int i=0;i<size;i++)	{
		sum += item_list[i].price;
	}
	double average = sum / size;
	return average;
}

int main(int agrc, char *argv[])	{
	
	Item *item_list = malloc(5*sizeof(Item));
	
	add_item(item_list, 13.99, "16543", "Baking goods", "2LB Vanilla Cake Mix",0);

	add_item(item_list, 2.99, "23411", "Candy", "Snickers Bar 2oz",1);
	
	add_item(item_list, 4.99, "14512","Deli", "Sliced Turkey 4oz",2);

	add_item(item_list, 5.50, "67823", "Dairy", "Greek Yogurt", 3);

	add_item(item_list, 1.99, "11010", "Deli", "Salami Stick", 4);

	print_item(item_list, 5);

	printf("Average price: %.2f\n", average_price(item_list,5));

	int found = 0;
	for(int i=0;i<5;i++)	{	
	if(strcmp(argv[1], item_list[i].sku) == 0)	{
			printf("String found: %s, Item: %s\n", argv[1], item_list[i].name);
	 		found = 1;
			break;
		}
	}
	if(!found)	{
		printf("Correct sku not found\n");
	}
		
	free_items(item_list, 5);

	return 0;
}
