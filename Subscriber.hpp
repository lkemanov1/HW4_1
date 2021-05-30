#pragma once
#include "Message.hpp"
#include <string>
class Subscriber
{
public:
	virtual int read() const = 0;
	virtual void signal(const Message& new_data) = 0;
	virtual Subscriber* clone() const = 0;
	virtual ~Subscriber() = default;
	virtual std::string get_id() const = 0;
};