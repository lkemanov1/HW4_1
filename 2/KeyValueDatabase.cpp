#include "KeyValueDatabase.hpp"
#include <exception>
#include <stdexcept>
#include <string>

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name, location, extension) {}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	for (unsigned idx = 0; idx < this->database.size(); idx++)
	{
		if (this->database[idx].first == entry.first)
		{
			throw std::invalid_argument("Such key already exists in the database\n");
			return;
		}
	}
	this->database.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	for (unsigned idx = 0; idx < this->database.size(); idx++)
	{
		if (this->database[idx].first == key)
			return this->database[idx].second;
	}
	throw std::invalid_argument("Such key isn't found in the database\n");
}

std::string KeyValueDatabase::to_string() const
{
	std::string info = "";
	info += this->name + "\n";
	info += this->location + "\n";
	info += this->extension + "\n";
	for (unsigned idx = 0; idx < this->database.size(); idx++)
	{
		info += this->database[idx].first + ":" + std::to_string(this->database[idx].second) + "\n";
	}
	return info;
}

void KeyValueDatabase::from_string(const std::string& info)
{
	std::string text = info;
	this->name = Object::read_line(text);
	this->location = Object::read_line(text);
	this->extension = Object::read_line(text);
	this->database.clear();
	while (text.size() > 0)
	{
		std::string pair = Object::read_line(text);
		std::pair<std::string, int> new_pair = to_pair(pair);
		this->add_entry(new_pair);
	}
}

std::string KeyValueDatabase::debug_print() const
{
	std::string to_print = "";
	for (unsigned idx = 0; idx < this->database.size(); idx++)
	{
		to_print += "{" + this->database[idx].first + ":" + std::to_string(this->database[idx].second) + "}\n";
	}
	return to_print;
}

bool KeyValueDatabase::operator==(const Comparable* to_compare) const
{
	Comparable* temp = const_cast<Comparable*>(to_compare);
	KeyValueDatabase* to_cmp = static_cast<KeyValueDatabase*> (temp);
	return compare_database(this->database, to_cmp->database);
}

bool KeyValueDatabase::operator!=(const Comparable* to_compare) const
{
	return !(*this==to_compare);
}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

std::pair<std::string, int> KeyValueDatabase::to_pair(const std::string& pair) const
{
	std::string key = "";
	int value = 0;
	unsigned idx = 0;
	while (pair[idx] != ':' && idx < pair.size())
	{
		key += pair[idx++];
	}
	idx++;
	while (idx < pair.size())
	{
		value *= 10;
		value += (pair[idx++] - '0');
	}
	return std::make_pair(key, value);
}
bool KeyValueDatabase::compare_database(const std::vector<std::pair<std::string, int>>& first, const std::vector<std::pair<std::string, int>> second) const
{
	if (first.size() != second.size())
		return false;
	for (unsigned idx = 0; idx < first.size(); idx++)
	{
		if (first[idx] != second[idx])
			return false;
	}
	return true;
}

