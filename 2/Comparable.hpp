#pragma once
class Comparable
{
public:
	Comparable() = default;
	virtual ~Comparable() = default;
	virtual bool operator ==(const Comparable*)const = 0;
	virtual bool operator !=(const Comparable*)const = 0;
};