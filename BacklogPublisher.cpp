#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* sub)
{
	for (int idx = 0; idx < this->messages.size(); idx++)
	{
		sub->signal(this->messages[idx]);
	}
	this->subscriber.push_back(sub);
}

void BacklogPublisher::unsubscribe(const Subscriber* const to_delete)
{
	for (int idx = 0; idx < this->subscriber.size(); idx++)
	{
		if (this->subscriber[idx]->get_id() == to_delete->get_id())
		{
			this->subscriber.erase(this->subscriber.begin() + idx);
		}
	}
}

void BacklogPublisher::signal(const Message& new_data)
{
	for (int idx = 0; idx < this->subscriber.size(); idx++)
	{
		this->subscriber[idx]->signal(new_data);
	}
	this->messages.push_back(new_data);
}
