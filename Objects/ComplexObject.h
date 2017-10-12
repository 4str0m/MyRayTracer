#ifndef COMPLEXOBJECT_H
#define COMPLEXOBJECT_H

#include <Object.h>
#include <vector>
#include "Triangle.h"

class ComplexObject final : public Object
{
    public:
        static ComplexObject* loadFromFile(Material *mat, const std::string& fileName);

        ~ComplexObject()
        {
            for (Triangle* triangle: m_triangles)
                delete triangle;
        }

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        ComplexObject(Material *mat, std::vector<Triangle*>& triangles)
        :   Object(mat)
        ,   m_triangles(std::move(triangles)) {}

    private:
        std::vector<Triangle*> m_triangles;
};

double stod(const std::string& str, std::string::size_type *pos = nullptr);
#endif // COMPLEXOBJECT_H
