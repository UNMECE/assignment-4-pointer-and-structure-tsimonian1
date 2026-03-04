#ifndef ITEM_h

#define ITEM_H

typedef struct item_struct
{
	double price;
	char *sku;
	char *name;
	char *category;
}item_struct;
typedef item_struct Item;

#endif
