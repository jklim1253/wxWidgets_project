#pragma once

template<typename T>
class singleton
{
public :
    static T& Reference()
    {
        static T instance;
        return instance;
    }
protected :
    singleton() {}
    ~singleton() {}
};