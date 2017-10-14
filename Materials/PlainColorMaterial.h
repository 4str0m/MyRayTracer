#ifndef PLAINCOLORMATERIAL_H
#define PLAINCOLORMATERIAL_H

#include <Material.h>
#include "../Utils/Color.h"


class PlainColorMaterial : public Material
{
    public:
        PlainColorMaterial(const std::string& name, Color c)
        :   Material(name)
        ,   m_color(c) {}

        virtual Color getColor(const Ray* ray,
                               const IntersectionData* dat,
                               const Scene* scene,
                               int depth) const override
        {
            return m_color;
        }

    private:
        const Color m_color;
};

#endif // PLAINCOLORMATERIAL_H
