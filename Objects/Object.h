#ifndef OBJECT_H
#define OBJECT_H

#include "../Utils/Ray.h"
#include "../Utils/IntersectionData.h"
#include "../Materials/Material.h"

#define DELTA_INTERSECT 0.01

class Object
{
    public:
        Object(Material *mat)
        : m_mat(mat) {}

        virtual bool intersect(const Ray& ray, IntersectionData *intersectionData) const = 0;

    protected:
        const Material *m_mat;
};

#endif // OBJECT_H
