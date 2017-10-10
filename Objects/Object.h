#ifndef OBJECT_H
#define OBJECT_H

#include "../Utils/Ray.h"

class Object
{
    public:
        Object();

        virtual bool intersects(const Ray& ray) const = 0;

    private:
};

#endif // OBJECT_H
