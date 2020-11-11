// Tep1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Table.h"
#include "util.h"
#include "consts.h"


//zadanie 1
void alloc_table_add_5(int table_size)
{
	if (table_size < 0)
	{
		std::cout << INCORRECT_TABLE_SIZE;
		return;
	}

	int* table = new int[table_size];

	fill_table(table_size, table);

	std::cout << PRINTING_TABLE_HEADER;
	print_table(table_size, table);

	delete[] table;
}

//zadanie 1 - modyfikacja
void alloc_reversed_table_add_5(int table_size)
{
	if (table_size < 0)
	{
		std::cout << INCORRECT_TABLE_SIZE;
		return;
	}

	int* reversed_table = new int[table_size];

	for (int i = 0; i < table_size; i++)
	{
		reversed_table[table_size - 1 - i] = i + 5;
	}

	std::cout << PRINTING_TABLE_HEADER;
	print_table(table_size, reversed_table);

	delete[] reversed_table;
}


//zadanie 2
bool alloc_table_2_dim(int*** table, int table_x_size, int table_y_size)
{
	if (table_x_size < 0 || table_y_size < 0) return false;

	*table = (new int* [table_x_size]);
	for (int i = 0; i < table_x_size; i++)
	{
		(*table)[i] = new int[table_y_size];
		//fill_table(table_y_size, (*table)[i]);
	}

	//print_2_dim_table(*table);

	return true;
}


//zadanie 3
bool dealloc_table_2_dim(int*** table, int table_x_size, int table_y_size)
{
	if (table_x_size < 0 || table_y_size < 0) return false;

	for (int i = 0; i < table_x_size; i++)
	{
		delete[](*table)[i];
	}

	delete[] * table;

	return true;
}


//zadanie 4
void mod_tab(Table* tab, int new_size)
{
	(*tab).set_new_size(new_size);
}

void mod_tab(Table tab, int new_size)
{
	tab.set_new_size(new_size);
}

void list1()
{
	//zadanie 1
	//alloc_table_add_5(5);

	//zadanie 1 - modyfikacja
	alloc_table_add_5(3);
	alloc_reversed_table_add_5(3);
	//alloc_reversed_table_add_5(0);
	//alloc_reversed_table_add_5(-2);


	//int** table;

	//zadanie 2
	//alloc_table_2_dim(&table, 5, 3);

	//zadanie 3
	/*
	dealloc_table_2_dim(&table, 5, 3);

	std::cout << table <<"\n";
	std::cout << table[3] <<"\n";
	std::cout << *table <<"\n";
	std::cout << &table <<"\n";
	*/

	//zadanie 4
	/*
	Table tab;
	Table* tab_clone;
	tab_clone = tab.clone();

	std::cout << "\nPierwsza próba modyfikacji\n";
	mod_tab(tab, 2);

	std::cout << "\nDruga próba modyfkacji\n";
	mod_tab(tab_clone, 2);

	std::cout << "\nKoniec prób\n";

	std::cout << "\nDeklaracja ablicy obiektów Table\n";
	Table tab1("test1", 5);
	Table tables[3]{ {}, {tab1}, {"test2", 2} };

	std::cout << "\nKoniec\n";
	*/
}

void list2()
{
	//zadania 1 i 2
	

	Table  tab_0, tab_1;
	tab_0.set_new_size(6);

	tab_0.set_value_at(0, 1);
	tab_0.set_value_at(1, 2);
	tab_0.set_value_at(2, 3);
	tab_0.set_value_at(3, 4);
	tab_0.set_value_at(4, 5);
	tab_0.set_value_at(5, 6);
	
	tab_1.set_new_size(4);

	tab_1.set_value_at(0, 51);
	tab_1.set_value_at(1, 52);
	tab_1.set_value_at(2, 53);
	tab_1.set_value_at(3, 54);
	
	tab_0 = tab_1;
	

	//zadanie 3
	tab_1.set_value_at(2, 123);
	tab_0.print();
	tab_1.print();

	//zadanie 4
	Table tab_2 = tab_0 + tab_1;
	tab_2.print();
}

void list2_mod()
{
	Table  tab_0;
	tab_0.set_new_size(6);

	tab_0.set_value_at(0, 1);
	tab_0.set_value_at(1, 2);
	tab_0.set_value_at(2, 3);
	tab_0.set_value_at(3, 4);
	tab_0.set_value_at(4, 5);
	tab_0.set_value_at(5, 6);

	tab_0.print();
	(--tab_0).print();
};

int main()
{
	//lista 1
	//list1();

	//lista 2
	//list2();

	//lista2-modyfikacja
	list2_mod();
}
