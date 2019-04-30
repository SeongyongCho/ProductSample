//
// Created by sycho on 2019-04-23.
//

#ifndef PRODUCTSAMPLE_LOGIC_H
#define PRODUCTSAMPLE_LOGIC_H

#include <jni.h>
#include <errno.h>
#include <time.h>

namespace native_logic {
    class Logic
    {
    private:
        int a;
        int b;

    public:
        Logic();
        virtual ~Logic();

        void setValue(int &a, int &b);
        int add();
    };
}

#endif //PRODUCTSAMPLE_LOGIC_H
