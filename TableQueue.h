#ifndef TableQueue_h
#define TableQueue_h

#include <queue>
#include "Customer.h"
#include "EntranceQueue.h"
#include "EatingQueue.h"
#include "ChickenSoup.h"
#include "Spaghetti.h"

class TableQueue {
private:
    EntranceQueue *entrance_queue;
    EatingQueue *eating_queue;
    
    std::priority_queue<Customer *> the_queue;
    int total_wait;
    int num_served;
    
    
public:
    TableQueue() : total_wait(0), num_served(0) {}
    
    void init(EntranceQueue *entrance_queue, EatingQueue *eating_queue) {
        this->entrance_queue = entrance_queue;
        this->eating_queue = eating_queue;
    }
    
    void update(int clock) {
        if(!the_queue.empty()) {
            
        }
        if (the_queue.size() < eating_queue->max_size) {
            if (!entrance_queue->the_queue.empty()) {
                Customer *customer = entrance_queue->the_queue.front();
                entrance_queue->the_queue.pop();
                entrance_queue->num_served++;
                entrance_queue->total_wait += clock - customer->arrival_time;
                assignDishToCustomer(customer, clock);
                customer->setTimeInQueue(customer->time_in_queue);
                the_queue.push(customer);
                
            }
        }
    }
    
    void assignDishToCustomer(Customer *customer, int clock) {
        SelectionData *data = new SelectionData(new ChickenSoup(clock), new Spaghetti(clock), new ChickenSoup(clock));
        eating_queue->addDishPair(customer, data);
        customer->setTimeInQueue(20);
    }
};

#endif
