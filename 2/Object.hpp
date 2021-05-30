#pragma once
#include "Debug.hpp"
#include "Serializable.hpp"
#include "Comparable.hpp"
#include<string>
class Object:public Serializable, public Debug,public Comparable 
{
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);
    virtual ~Object() = default;
    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
    virtual Object* clone()const = 0;
    virtual bool operator ==(const Comparable*)const override = 0;
    bool operator !=(const Comparable*)const override = 0;
    
protected:
    std::string name, location, extension;
    std::string read_line(std::string& info);

};