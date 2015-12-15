#ifndef MOZZORELLASTIX_h
#define MOZZORELLASTIX_h

#include "Dish.h"
#include "Simulator.h"
#include "Random.h"

extern Random _random;

class MozzorellaStix : public Dish {
private:
	int time_until_ready = 5;
	int time_to_eat_min = 3;
	int time_to_eat_max = 7;
public:

	MozzorellaStix(int clock) : Dish(clock) {}

	bool isReady(int clock) {
		return (clock - start) > time_until_ready;
	}

	int timeToEat() {
		return time_to_eat_min + _random.next_int(time_to_eat_max - time_to_eat_min);
	}
};

#endif

