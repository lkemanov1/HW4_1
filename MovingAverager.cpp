#include "MovingAverager.hpp"
#include "Subscriber.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize):id(id),windowSize(windowSize),sum(0){}

void MovingAverager::signal(const Message& new_data)
{
	this->in_window.push_front(new_data);
	this->sum += new_data.data;
	if (in_window.size() > this->windowSize)
	{
		this->sum -= this->in_window.back().data;
		this->in_window.pop_back();
	}
}

int MovingAverager::read()const
{
	if (this->in_window.size() == 0)
		return 0;
	return this->sum/this->in_window.size();
}

Subscriber* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}

std::string MovingAverager::get_id() const
{
	return this->id;
}
