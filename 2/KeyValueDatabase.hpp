#pragma once
#include "Object.hpp"
#include <string>
#include <utility>
#include <vector>
#include <exception>
class KeyValueDatabase:public Object {
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;
    std::string to_string()const override;
    void from_string(const std::string&) override;
    std::string debug_print()const override;
    bool operator ==(const Comparable*)const override;
    bool operator !=(const Comparable*)const override;
    Object* clone()const override;
private:
    std::vector<std::pair<std::string, int>> database;
    std::pair<std::string, int> to_pair(const std::string& pair) const;
    bool compare_database(const std::vector<std::pair<std::string, int>>& first,
        const std::vector<std::pair<std::string, int>> second)const;
};