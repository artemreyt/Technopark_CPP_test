#include "StringsModyfier.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace artemreyt;
using std::string, std::vector;

StringsModyfier::StringsModyfier(const string &_separator):
			separator(_separator), data()
{}

void			StringsModyfier::add_string(const string& str)
{
	string::size_type start = 0;
	vector<string> vec;

	while (start < str.size())
	{
		string::size_type end = str.find(this->separator, start);
		if (end != string::npos)
			vec.push_back(std::move(str.substr(start, end - start)));
		else
		{
			vec.push_back(std::move(str.substr(start, str.size() - start)));
			break;
		}
		start = end + 1;
	}
	data.push_back(vec);
}

void			StringsModyfier::insert(size_t pos_str, size_t field_after, string &str)
{
	if (check_exist(pos_str, field_after))
		data[pos_str].insert(data[pos_str].begin() + field_after, str);
}

string		StringsModyfier::at(size_t pos_str) const
{
	string str;
	
	if (check_exist(pos_str))
	{
		for (const auto& elem: data[pos_str])
			str += "\'" + elem + "\' ";
	}
	return str;
}

string		StringsModyfier::at_full(size_t pos_str) const
{
	check_exist(pos_str);

	string str;
	for (const auto& elem: data[pos_str])
		str += elem + " ";
	return str;
}

void			StringsModyfier::edit(size_t pos_str, size_t pos_field, const string &str)
{
	if (check_exist(pos_str, pos_field))
		data[pos_str][pos_field] = str;
}

void			StringsModyfier::erase(size_t pos_str, size_t pos_field)
{
	if (check_exist(pos_str))
		data[pos_str].erase(data[pos_str].begin() + pos_field);
}

size_t	StringsModyfier::size() const
{
	return data.size();
}

bool	StringsModyfier::check_exist(size_t pos_str) const
{
	if (pos_str >= data.size())
		throw std::out_of_range("No such string id!");
	return true;
}

bool	StringsModyfier::check_exist(size_t pos_str, size_t pos_field) const
{
	if (check_exist(pos_str) && pos_field >= data[pos_str].size())
		throw std::out_of_range("No such field in string!");
	return true;
}
