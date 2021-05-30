#include "SimplePublisher.hpp"
#include <iostream>

void SimplePublisher::subscribe(Subscriber* subscriber)
{
	this->subscriber.push_back(subscriber);
}

void SimplePublisher::unsubscribe(const Subscriber* const to_delete)
{
	for (int idx = 0; idx < this->subscriber.size(); idx++)
	{
		if (this->subscriber[idx]->get_id() == to_delete->get_id())
		{
			this->subscriber.erase(this->subscriber.begin() + idx);
		}
	}
}

void SimplePublisher::signal(const Message& new_data)
{
	for (int idx = 0; idx < this->subscriber.size(); idx++)
	{
		this->subscriber[idx]->signal(new_data);
	}
}
