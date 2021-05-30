#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string& id, const size_t period)
	:id(id),period(period),signals_received(0),last_period_signal(0){}

void PeriodicSampler::signal(const Message& new_data)
{
	this->signals_received++;
	if ((this->signals_received - 1) % this->period == 0 || this->signals_received == 1)
	{
		this->last_period_signal = new_data.data;
	}
}

int PeriodicSampler::read()const
{
	return this->last_period_signal;
}

Subscriber* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}

std::string PeriodicSampler::get_id() const
{
	return this->id;
}
