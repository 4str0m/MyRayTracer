#ifndef REFLEXIVEMATERIAL_H
#define REFLEXIVEMATERIAL_H

#include <Material.h>


class ReflexiveMaterial : public Material
{
    public:
        ReflexiveMaterial(Color dc = {0}, Color sc = {0}, Color ac = {0}, double sp = 5)
        :   Material(MaterialType::REFLEXIVE) {}

        Color getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const override;

    private:
};

#endif // REFLEXIVEMATERIAL_H
