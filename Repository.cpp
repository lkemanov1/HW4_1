#include "Repository.hpp"

Repository& Repository::operator=(const Repository& repo)
{
	if(this!=&repo)
	{ 
		for (int idx = 0; idx < this->subscriber.size(); idx++)
		{
			delete this->subscriber[idx];
		}
		this->subscriber.clear();
		for (int idx = 0; idx < repo.subscriber.size(); idx++)
		{
			this->add(repo.subscriber[idx]);
		}
	}
	return *this;
}

Repository::Repository(const Repository& repo)
{
	for (int idx = 0; idx < repo.subscriber.size(); idx++)
	{
		this->add(repo.subscriber[idx]);
	}
}

Repository::~Repository()
{
	for (int idx = 0; idx < this->subscriber.size(); idx++)
	{
		delete this->subscriber[idx];
	}
	this->subscriber.clear();
}

void Repository::add(Subscriber* sub)
{
	this->subscriber.push_back(sub->clone());
}

Subscriber* Repository::get(std::string id)
{
	for (int idx = 0; idx < this->subscriber.size(); idx++)
	{
		if(this->subscriber[idx]->get_id() == id)
		{
			return this->subscriber[idx];
		}
	}
	return nullptr;
}
