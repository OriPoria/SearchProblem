//
// Created by ori on 12/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H


class square {
public:
    int row;
    int column;
};


template<typename T>
class State {
private:
    T state;
    double cost;
    double h_cost;
    State<T> *camefrom;
    char color;
public:
    double getCost() const {
        return cost;
    }
  double GetHCost() const {
    return h_cost;
  }
  void setCost(double cost) {
        State::cost = cost;
    }


    State(T state1, double cost1, double h_cost_) {
        this->state = state1;
        this->cost = cost1;
        this->color = 'w';
        this->h_cost = h_cost_;
    }


    char getColor() const {
        return color;
    }

    void setColor(char color) {
        this->color = color;
    }

    T getState() const {
        return state;
    }

    void setCamefrom(State<T> *camefrom) {
        this->camefrom = camefrom;
    }

    State<T> *getCamefrom() const {
        return camefrom;
    }

};


#endif //EX4_STATE_H
