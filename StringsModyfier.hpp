#ifndef STRINGS_MODYFIER_HPP
#define STRINGS_MODYFIER_HPP

#include <vector>

using std::vector, std::string;

namespace StringsModyfier
{
	class StringsModyfier
	{
	 public:
		explicit StringsModyfier(char _separator) noexcept;


	 private:
		vector<vector<string>>	data;
		char					separator;
	};


	class InteractiveModeHelper
	{

	};

};

#endif
