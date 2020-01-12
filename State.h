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
public:
    State(T state) {
        this->state = state;
    }





};






#endif //EX4_STATE_H
