//
// Created by ori on 12/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H



struct square {
    int row;
    int column;
};


template <typename T>
class State {
private:
    T state;
    double cost;
    State<T>* camefrom;
public:
    State(T state1, double cost1) {
        this->state = state1;
        this->cost = cost1;
    }





};






#endif //EX4_STATE_H
