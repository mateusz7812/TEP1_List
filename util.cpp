#include "util.h"
#include <string>
#include <iostream>
#include "consts.h"

std::string replace_fragment(std::string text_to_edit, std::string const& new_text)
{
	return replace_fragment(text_to_edit, TEXT_PLACEHOLDER, new_text);
}

std::string replace_fragment(std::string text_to_edit, std::string const& old_text, std::string const& new_text)
{
	if (text_to_edit.find(old_text) == -1) {
		std::cout << TEXT_DO_NOT_CONTAINS_SUBTEXT_ERROR;
		return text_to_edit;
	}
	return text_to_edit.replace(text_to_edit.find(old_text), old_text.length(), new_text);
}


void print_table(int table_size, int*& table)
{
	for (int i = 0; i < table_size; i++)
	{
		std::cout << table[i] << " ";
	}
	std::cout << "\n";
}

void print_2_dim_table(int**& table)
{
	for (int i = 0; i < 5; i++)
	{
		print_table(3, table[i]);
		std::cout << "\n";
	}
}

void fill_table(int table_size, int*& table)
{
	for (int i = 0; i < table_size; i++)
	{
		table[i] = i + 5;
	}
}
