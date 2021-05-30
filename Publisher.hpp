#pragma once
#include "Subscriber.hpp"
#include "Message.hpp"
class Publisher
{
public:
	Publisher() = default;
	virtual ~Publisher() = default;
	virtual void subscribe(Subscriber*) = 0;
	virtual void unsubscribe(const Subscriber*) = 0;
	virtual void signal(const Message& new_data) = 0;
};