#ifndef TACO_h
#define TACO_h

#include "Dish.h"
#include "Simulator.h"
#include "Random.h"

extern Random _random;

class Taco : public Dish {
private:
	int time_until_ready = 9;
	int time_to_eat_min = 5;
	int time_to_eat_max = 20;
public:

	Taco(int clock) : Dish(clock) {}

	bool isReady(int clock) {
		return (clock - start) > time_until_ready;
	}

	int timeToEat(void) {
		return time_to_eat_min + _random.next_int(time_to_eat_max - time_to_eat_min);
	}
};

#endif