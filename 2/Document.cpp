#include "Document.hpp"
#include <iostream>
#include <exception>

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name,location,extension),last_read_line(0){}

void Document::write_line(const std::string& line)
{
	this->line.push_back(line);
}

std::string Document::read_line()
{	
	if(last_read_line < this->line.size())
		return this->line[last_read_line++];
	throw std::out_of_range("No more lines\n");
}

std::string Document::read_line(const unsigned line)
{
	
	if (this->line.size() >= line && line >= 1)
	{
		this->last_read_line = line;
		return this->line[line - 1];
	}
	throw std::out_of_range("There aren't that many lines\n");
		
}

std::string Document::to_string() const
{
	std::string info;
	info = this->get_name() + "\n";
	info += this->get_location() + "\n";
	info += this->get_extension() + "\n";
	for (unsigned idx = 0; idx < this->line.size(); idx++)
	{
		info += this->line[idx] + "\n";
	}
	return info;
}

void Document::from_string(const std::string& info) 
{
	std::string text = info;
	this->name = Object::read_line(text);
	this->location = Object::read_line(text);
	this->extension = Object::read_line(text);
	this->line.clear();
	this->last_read_line = 0;
	while (text.size() > 0)
	{
		this->line.push_back(Object::read_line(text));
	}
}

std::string Document::debug_print() const
{
	std::string info = "";
	for (unsigned idx = 0; idx < this->line.size(); idx++)
	{
		info += "Line " + std::to_string(idx + 1) + ":" + this->line[idx] + "\n";
	}
	return info;

}

bool Document::operator==(const Comparable* to_compare) const
{
	Comparable* temp = const_cast<Comparable*>(to_compare);
	Document* to_cmp = static_cast<Document*>(temp);
	return compare(this->line, to_cmp->line);
}

bool Document::operator!=(const Comparable* to_compare) const
{
	return !((*this) == to_compare);
}

Object* Document::clone() const
{
	return new Document(*this);
}



bool Document::compare(const std::vector<std::string>& first,const std::vector<std::string>& second) const
{
	if (first.size() != second.size())
		return false;
	size_t size = first.size();
	for (unsigned idx = 0; idx < size; idx++)
	{
		if (first[idx] != second[idx])
			return false;
	}
	return true;
}
