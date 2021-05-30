#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>
#include <deque>
// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// MovingAverager is a type of Subscriber, which saves data
// and returns the average of the last `windowSize` number of
// data points when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class MovingAverager:public Subscriber {
public:
	MovingAverager(std::string id, size_t windowSize);

	// id is a unique identifier for a Subscriber
	// Should never be changed once initialized
	const std::string id;

	// windowSize specifies how many most-recent data points
	// should be saved
	// Should never be changed once initialized
	const size_t windowSize;

	// signal adds a new data point
	// Remember, you only need the last windowSize number of 
	// data points added, older data points should be ignored
	void signal(const Message& new_data)override;

	// read calculates the average of the last windowSize number
	// of data points
	// returns 0 if there's no data points
	int read()const override;
	Subscriber* clone()const override;
	std::string get_id()const override;

private:
	int sum;
	std::deque<Message> in_window;
};