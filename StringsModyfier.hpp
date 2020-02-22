#ifndef STRINGS_MODYFIER_HPP
#define STRINGS_MODYFIER_HPP

#include <vector>
#include <string>


namespace artemreyt
{
	using std::vector, std::string;

	class StringsModyfier
	{
	 public:
		explicit StringsModyfier(const string &_separator);
		void			add_string(const string& str);
		void			insert(size_t pos_str, size_t field_after, string &str);
		string			at(size_t pos_str) const;
		string			at_full(size_t pos_str) const;
		void			edit(size_t pos_str, size_t pos_field, const string &str);
		void			erase(size_t pos_str, size_t pos_field);
		size_t			size() const;

	 private:
		bool	check_exist(size_t pos_str) const;
		bool	check_exist(size_t pos_str, size_t pos_field) const;

		vector<vector<string>>	data;
		string					separator;
	};

	enum class t_cmd : int
	{
		CMD_ADD_STRING = 1,
		CMD_PRINT_STRINGS,
		CMD_PRINT_STRING_BY_ID,
		CMD_EDIT_STRING,
		CMD_ERASE,
		CMD_INSERT,
		CMD_CLEAR_SCREEN,
		CMD_EXIT,
		CMD_INIT = -1
	};

	class InteractiveModeHelper
	{
	 public:
		InteractiveModeHelper(const string& _separator="\t");
		void			print_instructions();
		void			ask_cmd(int first, int last) const;
		void			add_string();
		void			print_all() const;
		void			print_all_before_exit() const;
		void			print_by_id() const;
		void			edit_string();
		void			erase();
		void			insert();
		static void		clear_screen();
		void			run_cmd();

	 private:
		StringsModyfier modyfier;
		mutable t_cmd	cur_cmd;
	};
};

#endif
