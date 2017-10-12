#ifndef PLAINCOLORMATERIAL_H
#define PLAINCOLORMATERIAL_H

#include <Material.h>
#include "../Utils/Color.h"


class PlainColorMaterial : public Material
{
    public:
        PlainColorMaterial(Color c)
        :   Material(MaterialType::PLAIN)
        ,   m_color(c) {}

        Color getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const override
        {
            return m_color;
        }

    private:
        const Color m_color;
};

#endif // PLAINCOLORMATERIAL_H
