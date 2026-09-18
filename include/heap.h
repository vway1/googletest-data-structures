#pragma once

class Heap {
public:
    virtual ~Heap() = default;

    virtual void push(int value) = 0;
    virtual int pop() = 0;
};
