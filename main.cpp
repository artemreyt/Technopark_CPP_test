#include <iostream>
#include <cstdlib>
#include "StringsModyfier.hpp"

#define CMD_ADD_STRING			1
#define CMD_PRINT_STRINGS		2
#define CMD_PRINT_STRING_BY_ID	3
#define CMD_EDIT_STRING			4
#define CMD_CLEAR_SCREEN		5
#define CMD_EXIT				6

void	print_instructions()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "1. Add new string" << std::endl;
	std::cout << "2. Print all strings as lists of fields" << std::endl;
	std::cout << "3. Print one string by index" << std::endl;
	std::cout << "4. Edit string by index" << std::endl;
	std::cout << "5. Clear screen" << std::endl;
	std::cout << "6. Exit" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

int main()
{
	StringsModyfier::InteractiveModeHelper helper('\t');

	while (true)
	{
		print_instructions();

		helper.ask_cmd(1, 6);
		switch (helper.get_cmd())
		{
			case CMD_ADD_STRING:
			{
				helper.add_string();
				break;
			}
			case CMD_PRINT_STRINGS:
			{
				helper.print_all();
				break;
			}
			case CMD_PRINT_STRING_BY_ID:
			{
				helper.get_by_id();
				break;
			}
			case CMD_EDIT_STRING:
			{
				helper.edit_string();
				break;
			}
			case CMD_CLEAR_SCREEN:
			{
				system("clear");
				break;
			}
			default:
				return 0;
		}
	}
	return 0;
}
