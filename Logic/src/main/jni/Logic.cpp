//
// Created by sycho on 2019-04-23.
//

#include "Logic.h"

namespace native_logic {
    Logic::Logic()
    {
        a = -1;
        b = -1;
    }

    Logic::~Logic()
    = default;

    void Logic::setValue(int &a, int &b)
    {
        this->a = a;
        this->b = b;
    }

    int Logic::add()
    {
        return a + b;
    }
}
