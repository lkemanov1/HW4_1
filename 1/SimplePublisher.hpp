#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"
#include <vector>

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher:public Publisher {
public:
	// subscribe registers a Subscriber to start receiving messages
	SimplePublisher() = default;
	~SimplePublisher() = default;
	void subscribe(Subscriber*) override;

	// unsubscribe removes a Subscriber from the Publisher
	// Subscribers are removed based on their `id`
	// id's will always be unique
	void unsubscribe(const Subscriber*) override;

	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	void signal(const Message& new_data)override;
private:
	std::vector<Subscriber*> subscriber;
};