#ifndef DIFFUSEMATERIAL_H
#define DIFFUSEMATERIAL_H

#include <Material.h>
#include "../Utils/Color.h"


class DiffuseMaterial : public Material
{
    public:

        DiffuseMaterial(Color dc, Color sc, Color ac, float sp = 5)
        :   m_diffuseColor(dc)
        ,   m_specularColor(sc)
        ,   m_ambientColor(ac)
        ,   m_specularPower(sp) {}

        virtual Color getColor(const Ray* ray,
                               const IntersectionData* dat,
                               const Scene* scene,
                               int depth) const override;

    private:
        const Color m_diffuseColor;
        const Color m_specularColor;
        const Color m_ambientColor;
        const float m_specularPower;
};

#endif // DIFFUSEMATERIAL_H
