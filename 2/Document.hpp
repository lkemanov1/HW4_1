#pragma once
#include "Object.hpp"
#include "Comparable.hpp"
#include <string>
#include <vector>
class Document:public Object {
public:
    Document() = default;
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);
    std::string to_string()const override; 
    std::string debug_print()const override;	

    void from_string(const std::string& ) override;
    bool operator ==(const Comparable*)const override;
    bool operator !=(const Comparable*)const override;

    Object* clone()const override;  

private:
    std::vector<std::string> line;
    int last_read_line;
    bool compare(const std::vector<std::string>& first,const std::vector<std::string>& second) const;
};