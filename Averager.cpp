#include "Averager.hpp"
#include "Subscriber.hpp"
Averager::Averager(std::string id):id(id),sum(0),points(0){}

void Averager::signal(const Message& new_data)
{
	this->sum += new_data.data;
	this->points++;
}

int Averager::read()const
{
	if (this->points == 0)
		return 0;
	return this->sum / this->points;
}

Subscriber* Averager::clone() const
{
	return new Averager(*this);
}

std::string Averager::get_id() const
{
	return this->id;
}
