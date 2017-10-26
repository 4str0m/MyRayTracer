#ifndef DIFFUSEMATERIAL_H
#define DIFFUSEMATERIAL_H

#include <Material.h>
#include "../Utils/Color.h"


class DiffuseMaterial : public Material
{
    public:

        DiffuseMaterial(const std::string& name, Color dc, Color sc, float af, float sp = 5)
        :   Material(name)
        ,   m_diffuseColor(dc)
        ,   m_specularColor(sc)
        ,   m_ambientFactor(af)
        ,   m_specularPower(sp) {}

        virtual Color getColor(const Ray* ray,
                               const IntersectionData* dat,
                               const Scene* scene,
                               int depth) const override;

    private:
        const Color m_diffuseColor;
        const Color m_specularColor;
        const float m_ambientFactor;
        const float m_specularPower;
};

#endif // DIFFUSEMATERIAL_H
