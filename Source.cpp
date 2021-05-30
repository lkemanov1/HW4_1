#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "BacklogPublisher.hpp"
#include "SimplePublisher.hpp"
#include "Repository.hpp"
#include <iostream>
int main()
{
	Averager* avg = new Averager("id1");
	MovingAverager* movAvg = new MovingAverager("id2", 5);
	PeriodicSampler* perSam = new PeriodicSampler("id3", 3);
	BacklogPublisher pub;
	Repository repo;
	//pub.subscribe(movAvg);
	//pub.subscribe(avg);
	repo.add(avg);
	repo.add(movAvg);
	repo.add(perSam);
	pub.subscribe(repo.get("id2"));
	pub.signal(1);
	pub.signal(2);
	pub.signal(3);
	pub.signal(4);
	pub.unsubscribe(movAvg);
	pub.signal(5);
	pub.signal(6);
	//pub.unsubscribe(avg);
	pub.signal(7);
	pub.signal(8);
	pub.subscribe(perSam);
	pub.signal(9);
	pub.subscribe(avg);
	std::cout << avg->read() << std::endl;;
	std::cout << repo.get("id2")->read() << std::endl;;
	std::cout << perSam->read() << std::endl;
	BacklogPublisher bp;
	delete avg;
	delete movAvg;
	delete perSam;
	return 0;
}