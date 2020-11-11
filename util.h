#pragma once
#include <string>

std::string replace_fragment(std::string text_to_edit, std::string const& new_text);

std::string replace_fragment(std::string text_to_edit, std::string const& old_text, std::string const& new_text);

void print_table(int table_size, int*& table);

void print_2_dim_table(int**& table);

void fill_table(int table_size, int*& table);