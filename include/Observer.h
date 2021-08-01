#pragma once

#include "InputManager.h"
#include "stdafx.h"

class Observer {
private:
    InputManager* pIM;

public:
    Observer(InputManager* pIM);
    virtual ~Observer() { }
    virtual void notify() = 0;
};