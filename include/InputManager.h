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

    void registerObserver(Observer* pObserver);
    void removeObserver(Observer* pObserver);
    void handleKeyPressed();
};
