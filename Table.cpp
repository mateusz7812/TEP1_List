#include "Table.h";
#include "consts.h";
#include <iostream>
#include <utility>
#include "util.h"

Table::Table() {
	_name = DEFAULT_TABLE_NAME;
	_table_size = DEFAULT_TABLE_SIZE;
	_table = new int[_table_size];
	std::cout << replace_fragment(TABLE_CONSTRUCTOR_NO_PARAMS_TEXT, _name);
}

Table::Table(std::string name, int table_size)
{
	_name = std::move(name);
	_table_size = table_size;
	_table = new int[_table_size];
	std::cout << replace_fragment(TABLE_CONSTRUCTOR_PARAMS_TEXT, _name);
}

Table::Table(Table& other)
{
	_name = other._name + TABLE_CLONE_POSTFIX;
	_table_size = other._table_size;
	_table = new int[_table_size];

	for (int i = 0; i < _table_size; i++)
	{
		_table[i] = other._table[i];
	}
	std::cout << replace_fragment(TABLE_CONSTRUCTOR_CLONE_TEXT, _name);
}

Table::Table(Table&& other)
{
	this->_name = std::move(other._name);
	other._name.erase();

	this->_table = other._table;
	other._table = nullptr;

	this->_table_size = other._table_size;
	other._table_size = NULL;

	std::cout << replace_fragment(TABLE_CONSTRUCTOR_MOVE_TEXT, _name);
}

Table::~Table()
{
	delete[] _table;
	std::cout << replace_fragment(TABLE_DESTRUCTOR_TEXT, _name);
}

void Table::set_name(std::string name)
{
	_name = std::move(name);
}

void Table::set_value_at(int offset, int new_value)
{
	if (offset < 0 || offset >= _table_size)
	{
		std::cout << INCORRECT_TABLE_SIZE;
		return;
	}
	_table[offset] = new_value;
}

int Table::value_at(int offset)
{
	if (offset < 0 || offset >= _table_size)
	{
		std::cout << INCORRECT_TABLE_SIZE;
		return NULL;
	}
	return _table[offset];

}

void Table::print()
{
	std::cout << "\n" << _name << "\n";
	print_table(_table_size, _table);
}


bool Table::set_new_size(int table_size)
{
	if (table_size < _table_size) return false;
	int* table = _table;
	_table = new int[table_size];

	for (int i = 0; i < _table_size; i++)
	{
		_table[i] = table[i];
	}

	delete[] table;
	_table_size = table_size;
	return true;
}

Table* Table::clone()
{
	return new Table(*this);
}

Table& Table::operator+(Table& other)
{
	std::cout << replace_fragment(replace_fragment(TABLES_CONCATENATION_TEXT, _name), other._name);

	const std::string name = replace_fragment(replace_fragment(CONCATENATED_TABLE_NAME, _name), other._name);

	const int table_size = _table_size + other._table_size;

	Table* table = new Table(name, table_size);

	for (int i = 0; i < _table_size; i++)
	{
		table->set_value_at(i, _table[i]);
	}

	for (int i = _table_size; i < table_size; i++)
	{
		table->set_value_at(i, other._table[i - _table_size]);
	}

	return *table;
}

Table& Table::operator=(Table&& other)
{
	std::cout << _name + " <= " + other._name + " move\n";

	if (this == &other)
		return *this;

	this->_name = std::move(other._name);
	other._name.erase();

	this->_table = other._table;
	other._table = nullptr;

	this->_table_size = other._table_size;
	other._table_size = NULL;

	return *this;
}

Table& Table::operator=(const Table& other)
{
	std::cout << replace_fragment(replace_fragment(TABLE_COPY_TEXT, _name), other._name);

	if (this == &other)
		return *this;

	delete[] _table;

	_name = other._name;
	_table = new int[other._table_size];
	_table_size = other._table_size;

	for (int i = 0; i < _table_size; i++)
	{
		set_value_at(i, other._table[i]);
	}

	return *this;
}

Table& Table::operator--()
{
	if (_table_size == 0) return *this;
	
	int updated_size = _table_size - 1;
	int* updated_table = new int[updated_size];
	for (int i = 0; i < updated_size; i++)
	{
		updated_table[i] = value_at(i);
	}
	delete[] _table;
	_table = updated_table;
	_table_size = updated_size;
	return *this;
};
