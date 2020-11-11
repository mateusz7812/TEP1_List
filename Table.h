#pragma once
#include <string>

class Table {
	std::string _name;
	int* _table;
	int _table_size;

public:
	Table();
	Table(std::string name, int table_size);
	Table(Table& other);
	Table(Table&& other);
	~Table();
	void set_name(std::string name);
	void set_value_at(int offset, int new_value);
	int value_at(int offset);
	void print();
	bool set_new_size(int table_size);
	Table* clone();
	Table& operator+(Table& other);
	Table& operator=(Table&& other);
	Table& operator=(const Table& other);
	Table& operator--();
};
