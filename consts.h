#pragma once
#include <string>

// Table.cpp
const std::string DEFAULT_TABLE_NAME = "table";
const int DEFAULT_TABLE_SIZE = 0;

const std::string TABLE_CLONE_POSTFIX = "_copy";


const std::string TEXT_PLACEHOLDER = "<text>";

const std::string TABLE_CONSTRUCTOR_NO_PARAMS_TEXT = "bezp: ‘" + TEXT_PLACEHOLDER + "’\n";
const std::string TABLE_CONSTRUCTOR_PARAMS_TEXT = "parametr: ‘" + TEXT_PLACEHOLDER + "’\n";
const std::string TABLE_CONSTRUCTOR_CLONE_TEXT = "kopiuj: ‘" + TEXT_PLACEHOLDER + "’\n";
const std::string TABLE_CONSTRUCTOR_MOVE_TEXT = "przenieś: ‘" + TEXT_PLACEHOLDER + "’\n";

const std::string TABLE_DESTRUCTOR_TEXT = "usuwam: ‘" + TEXT_PLACEHOLDER + "’\n";

const std::string CONCATENATED_TABLE_NAME = TEXT_PLACEHOLDER + " and " + TEXT_PLACEHOLDER + " concatenation";

const std::string TABLES_CONCATENATION_TEXT = TEXT_PLACEHOLDER + " and " + TEXT_PLACEHOLDER + " concatenation\n";


const std::string TABLE_COPY_TEXT = TEXT_PLACEHOLDER + " <= " + TEXT_PLACEHOLDER + " copy\n";


//util.cpp

const std::string TEXT_DO_NOT_CONTAINS_SUBTEXT_ERROR = "Tekst nie zawiera szukanego fragmentu";

//Tep1.cpp

const std::string INCORRECT_TABLE_SIZE = "Rozmiar tablicy nieprawidłowy";

const std::string PRINTING_TABLE_HEADER = "Wygenerowana tablica:\n";