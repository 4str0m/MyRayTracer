#ifndef DIFFUSEMATERIAL_H
#define DIFFUSEMATERIAL_H

#include <Material.h>
#include "../Utils/Color.h"


class DiffuseMaterial : public Material
{
    public:
        DiffuseMaterial(Color dc = {0}, Color sc = {0}, Color ac = {0}, double sp = 5)
        :   Material(MaterialType::DIFFUSE)
        ,   m_diffuseColor(dc)
        ,   m_specularColor(sc)
        ,   m_ambientColor(ac)
        ,   m_specularPower(sp) {}

        Color getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const override;

    private:
        const Color m_diffuseColor;
        const Color m_specularColor;
        const Color m_ambientColor;
        const double m_specularPower;
};

#endif // DIFFUSEMATERIAL_H
