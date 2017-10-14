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

        Object& rotate(float angle, const Vector3f& axis) override
        {
            m_t.rotate(AngleAxisf(angle*M_PI/180., axis));
            for(Triangle* triangle: m_triangles)
            {
                triangle->rotate(angle, axis);
            }
            return *this;
        }
        Object& translate(const Vector3f& v) override
        {
            m_t.translate(v);
            for(Triangle* triangle: m_triangles)
            {
                triangle->translate(v);
            }
            return *this;
        }
        Object& scale(const Vector3f& s) override
        {
            m_t.scale(s);
            for(Triangle* triangle: m_triangles)
            {
                triangle->scale(s);
            }
            return *this;
        }

    private:
        ComplexObject(Material *mat, std::vector<Triangle*>& triangles)
        :   Object(mat)
        ,   m_triangles(std::move(triangles)) {}

    private:
        std::vector<Triangle*> m_triangles;
};

float stod(const std::string& str, std::string::size_type *pos = nullptr);
#endif // COMPLEXOBJECT_H
