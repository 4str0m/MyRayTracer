#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Lights/Light.h"
#include "../Utils/Ray.h"
#include "../Utils/IntersectionData.h"

enum class MaterialType
{
    PLAIN, DIFFUSE, REFLEXIVE
};

class Material
{

    public:
        Material(MaterialType type)
        : m_type(type) {}

        virtual ~Material() = default;

        virtual Color getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const = 0;

        inline MaterialType getType() const { return m_type; }
    private:
        const MaterialType m_type;
};

#endif // MATERIAL_H
