#include <iostream>
#include <cstdlib>
#include "StringsModyfier.hpp"


int main()
{
	artemreyt::InteractiveModeHelper helper;

	while (true)
	{
		helper.print_instructions();
		helper.ask_cmd(1, 8);
		helper.run_cmd();
	}
	return 0;
}
