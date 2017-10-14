#ifndef REFLEXIVEMATERIAL_H
#define REFLEXIVEMATERIAL_H

#include "Material.h"
#include "DiffuseMaterial.h"

class ReflexiveMaterial : public Material
{
    public:
        ReflexiveMaterial(const std::string& name, Color dc = {0}, Color sc = {0}, Color ac = {0}, float sp = 5, float factor = .5)
        :   Material(name)
        ,   m_diffusePart(name, dc , sc, ac, sp)
        ,   m_factor(factor) {}

        virtual Color getColor(const Ray* ray,
                               const IntersectionData* dat,
                               const Scene* scene,
                               int depth) const override;

    private:
        DiffuseMaterial m_diffusePart;
        float m_factor;
};

#endif // REFLEXIVEMATERIAL_H
