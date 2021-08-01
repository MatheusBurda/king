#pragma once

#include "stdafx.h"
#include <list>

using namespace std;

class Observer;

class InputManager {
private:
    std::list<Observer*> objObserving;
    std::list<Observer*>::iterator it;

public:
    InputManager();
    ~InputManager();

    void subscribe(Observer* pObserver);
    void exec();
};
