#ifndef OBJECT_H
#define OBJECT_H

#include "../Utils/Ray.h"
#include "../Utils/IntersectionData.h"
#include "../Materials/Material.h"

class Object
{
    public:
        Object(Color c)
        : m_mat(c) {}

        virtual bool intersect(const Ray& ray, IntersectionData *intersectionData) const = 0;

    public:
        Material m_mat;
};

#endif // OBJECT_H
