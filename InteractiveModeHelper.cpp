#include "StringsModyfier.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace artemreyt;
using std::string, std::vector;

InteractiveModeHelper::InteractiveModeHelper(const string& _separator):
		modyfier(_separator)
{}

void		InteractiveModeHelper::ask_cmd(int first, int last) const
{
	int new_cmd = last + 1;

	std::cout << "Enter command: ";
	while (new_cmd < first || new_cmd > last)
	{
		std::cin >> new_cmd;
		std::cin.ignore();
		if (new_cmd < first || new_cmd > last)
			std::cout << "No such command! Try else one: ";
	}
	this->cur_cmd = static_cast<t_cmd>(new_cmd);
}

void		InteractiveModeHelper::add_string()
{
	string str;

	std::cout << "Enter new string: ";
	std::getline(std::cin, str);
	this->modyfier.add_string(str);
}

void		InteractiveModeHelper::print_all() const
{
	for (size_t i = 0; i < modyfier.size(); ++i)
		std::cout << i << "." << modyfier.at(i) << std::endl;
}

void		InteractiveModeHelper::print_all_before_exit() const
{
	for (size_t i = 0; i < modyfier.size(); ++i)
		std::cout << modyfier.at_full(i) << std::endl;
}

void		InteractiveModeHelper::print_by_id() const
{
	size_t id = modyfier.size();

	std::cout << "Enter string id: ";
	std::cin >> id;
	try
	{
		std::cout << modyfier.at(id) << std::endl;
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << std::endl;
	}
}
void		InteractiveModeHelper::edit_string()
{
	size_t pos_str, pos_field;
	string str;

	std::cout << "Enter str id: ";
	std::cin >> pos_str;
	std::cout << "Enter field id: ";
	std::cin >> pos_field;
	std::cin.ignore();
	std::cout << "Enter new field: ";
	std::getline(std::cin, str);

	try
	{
		modyfier.edit(pos_str, pos_field, str);
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void		InteractiveModeHelper::clear_screen()
{
	std::system("clear");
}

void		InteractiveModeHelper::erase()
{
	size_t pos_str, pos_field;

	std::cout << "Enter str id: ";
	std::cin >> pos_str;
	std::cout << "Enter field id: ";
	std::cin >> pos_field;
	std::cin.ignore();

	try
	{
		modyfier.erase(pos_str, pos_field);
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void		InteractiveModeHelper::insert()
{
	size_t pos_str, pos_field;
	string str;

	std::cout << "Enter str id: ";
	std::cin >> pos_str;
	std::cout << "Enter field id: ";
	std::cin >> pos_field;
	std::cin.ignore();
	std::cout << "Enter new field, before which to inser new field: ";
	std::getline(std::cin, str);

	try
	{
		modyfier.insert(pos_str, pos_field, str);
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void		InteractiveModeHelper::run_cmd()
{
	switch (this->cur_cmd)
	{
		case t_cmd::CMD_ADD_STRING:
		{
			add_string();
			break;
		}
		case t_cmd::CMD_PRINT_STRINGS:
		{
			print_all();
			break;
		}
		case t_cmd::CMD_PRINT_STRING_BY_ID:
		{
			print_by_id();
			break;
		}
		case t_cmd::CMD_EDIT_STRING:
		{
			edit_string();
			break;
		}
		case t_cmd::CMD_INSERT:
		{
			insert();
			break;
		}
		case t_cmd::CMD_ERASE:
		{
			erase();
			break;
		}
		case t_cmd::CMD_CLEAR_SCREEN:
		{
			clear_screen();
			break;
		}
		case t_cmd::CMD_EXIT:
		{
			print_all_before_exit();
			std::exit(EXIT_SUCCESS);
		}
		default:
			throw std::runtime_error("UNKNOWN COMMAND");
	}
}

void		InteractiveModeHelper::print_instructions()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "1. Add new string" << std::endl;
	std::cout << "2. Print all strings as lists of fields" << std::endl;
	std::cout << "3. Print one string by index" << std::endl;
	std::cout << "4. Edit string by index" << std::endl;
	std::cout << "5. Erase field" << std::endl;
	std::cout << "6. Insert by index" << std::endl;
	std::cout << "7. Clear screen" << std::endl;
	std::cout << "8. Exit" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}
